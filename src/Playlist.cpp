#include "../include/Playlist.h"
#include <stdexcept>

std::string Playlist::getName() const {
    return name;
}

void Playlist::setName(const std::string& newName) {
    name = newName;
}

const std::vector<Song>& Playlist::getSongs() const {
    return songs;
}

Song& Playlist::getSong(int index) {
    if (index <= 0 || index > (int)songs.size()) {
        throw std::out_of_range("Invalid song index");
    }
    return songs[index - 1]; // UI uses 1-based indexing
}

void Playlist::addSong(const Song& song) {
    songs.push_back(song);
}

void Playlist::removeSong(int index) {
    if (index <= 0 || index > (int)songs.size()) {
        throw std::out_of_range("Invalid song index");
    }
    songs.erase(songs.begin() + (index - 1));
}

void Playlist::reorderSong(int fromIndex, int toIndex) {
    if (fromIndex <= 0 || fromIndex > (int)songs.size() ||
        toIndex <= 0 || toIndex > (int)songs.size()) {
        throw std::out_of_range("Invalid song index");
        }

    Song temp = songs[fromIndex - 1];
    songs.erase(songs.begin() + (fromIndex - 1));

    // adjust if moving forward in vector
    if (toIndex > fromIndex) {
        toIndex--;
    }

    songs.insert(songs.begin() + (toIndex - 1), temp);
}

void Playlist::updateSong(int index, const Song& song) {
    if (index <= 0 || index > (int)songs.size()) {
        throw std::out_of_range("Invalid song index");
    }

    songs[index - 1] = song;
}