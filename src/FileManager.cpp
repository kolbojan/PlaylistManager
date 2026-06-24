#include "../include/FileManager.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <utility>
#include "../include/Song.h"
#include "../include/Podcast.h"
#include "../include/Playlist.h"

namespace fs = std::filesystem;

FileManager::FileManager() {
    basePath = "../data/";

    // NEW: ensure base directory exists
    if (!fs::exists(basePath)) {
        fs::create_directories(basePath);
    }
}

void FileManager::createPlaylist(const std::string& name) const {
    const std::string filePath = basePath + name + ".csv";

    std::ofstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error: Could not create playlist file: " << filePath << std::endl;
        return;
    }

    file << "Name,Artist,Album,Duration,Type\n";
    file.close();
}

std::vector<std::string> FileManager::getAllPlaylists() const {
    std::vector<std::string> playlists;

    try {
        for (const auto& entry : fs::directory_iterator(basePath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".csv") {
                playlists.push_back(entry.path().stem().string());
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }

    return playlists;
}

bool FileManager::playlistExists(int playlistId) const {
    std::vector<std::string> playlists = getAllPlaylists();
    int index = 1;
    for (const auto& playlist : playlists) {
        if (playlistId == index) {
            return true;
        }
        index++;
    }
    return false;
}

Playlist FileManager::loadPlaylist(int playlistId) const {
    int index = 1;
    std::string fileName;
    std::string playlistName;

    for (const auto& entry : fs::directory_iterator(basePath)) {
        if (entry.is_regular_file() &&
            entry.path().extension() == ".csv") {

            if (index == playlistId) {
                fileName = entry.path().string();
                playlistName = entry.path().stem().string();
                break;
            }
            index++;
        }
    }

    if (fileName.empty()) {
        throw std::invalid_argument("Playlist doesn't exist!");
    }

    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::invalid_argument("Playlist couldn't be opened!");
    }

    Playlist playlist;

    playlist.setName(playlistName);

    std::string line;

    if (std::getline(file, line)) {
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string name, artist, album, duration, type;

        std::getline(ss, name, ',');
        std::getline(ss, artist, ',');
        std::getline(ss, album, ',');
        std::getline(ss, duration, ',');
        std::getline(ss, type, ',');

        std::unique_ptr<AudioFile> audio;

        if (type == "Song") {
            auto song = std::make_unique<Song>();
            song->setName(name);
            song->setArtist(artist);
            song->setAlbum(album);
            song->setDuration(duration);

            audio = std::move(song);
        }
        else if (type == "Podcast") {
            auto podcast = std::make_unique<Podcast>();
            podcast->setName(name);
            podcast->setArtist(artist);
            podcast->setDuration(duration);

            audio = std::move(podcast);
        }
        else {
            continue;
        }

        playlist.addSong(std::move(audio));
    }

    return playlist;
}

void FileManager::savePlaylist(const Playlist& playlist) const {
    std::string fileName = basePath + playlist.getName() + ".csv";

    if (!fs::exists(fileName)) {
        throw std::invalid_argument("Playlist does not exist!");
    }

    std::ofstream file(fileName, std::ios::trunc);

    if (!file.is_open()) {
        throw std::invalid_argument("Playlist couldn't be opened!");
    }

    file << "Name,Artist,Album,Duration,Type\n";

    for (const auto& audio : playlist.getSongs()) {

        if (auto song = dynamic_cast<Song*>(audio.get())) {
            file << song->getName() << ","
                 << song->getArtist() << ","
                 << song->getAlbum() << ","
                 << song->getDuration() << ","
                 << "Song\n";
        }
        else if (auto podcast = dynamic_cast<Podcast*>(audio.get())) {
            file << podcast->getName() << ","
                 << podcast->getArtist() << ","
                 << ","
                 << podcast->getDuration() << ","
                 << "Podcast\n";
        }
    }

    file.close();
}

void FileManager::renamePlaylist(const std::string& old, const Playlist& playlist) const {
    createPlaylist(playlist.getName());
    savePlaylist(playlist);
    removePlaylist(old);
}

void FileManager::removePlaylist(const std::string& name) const {
    std::string fileName = basePath + name + ".csv";

    if (!fs::exists(fileName)) {
        throw std::invalid_argument("Playlist does not exist!");
    }

    if (!fs::remove(fileName)) {
        throw std::invalid_argument("Playlist couldn't be deleted!");
    }
}
