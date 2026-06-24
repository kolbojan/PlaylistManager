#include "../include/Playlist.h"
#include <stdexcept>
#include <algorithm>


std::string Playlist::getName() const {
    return name;
}


void Playlist::setName(const std::string& newName) {
    name = newName;
}


const std::vector<std::unique_ptr<AudioFile>>& Playlist::getSongs() const {
    return content;
}


AudioFile* Playlist::getSong(int index) {

    if (index <= 0 || index > (int)content.size()) {
        throw std::out_of_range("Invalid file index");
    }

    return content[index - 1].get();
}


void Playlist::addSong(std::unique_ptr<AudioFile> file) {

    if (!file) {
        throw std::invalid_argument("Cannot add empty file");
    }

    content.push_back(std::move(file));
}


void Playlist::removeSong(int index) {

    if (index <= 0 || index > (int)content.size()) {
        throw std::out_of_range("Invalid file index");
    }

    content.erase(content.begin() + (index - 1));
}


void Playlist::reorderSong(int fromIndex, int toIndex) {

    if (fromIndex <= 0 || fromIndex > (int)content.size() ||
        toIndex <= 0 || toIndex > (int)content.size()) {

        throw std::out_of_range("Invalid file index");
        }


    auto temp = std::move(content[fromIndex - 1]);


    content.erase(content.begin() + (fromIndex - 1));


    if (toIndex > fromIndex) {
        toIndex--;
    }


    content.insert(
        content.begin() + (toIndex - 1),
        std::move(temp)
    );
}


void Playlist::updateSong(int index, std::unique_ptr<AudioFile> file) {

    if (index <= 0 || index > (int)content.size()) {
        throw std::out_of_range("Invalid file index");
    }


    if (!file) {
        throw std::invalid_argument("Cannot replace with empty file");
    }


    content[index - 1] = std::move(file);
}