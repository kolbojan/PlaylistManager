#include "../include/Playlist.h"

#include <iostream>
#include <stdexcept>

Song Playlist::getSong(size_t index) const {
    if (index >= songList.size()) {
        throw std::out_of_range("Error: Song index out of bounds!");
    }
    return songList[index];
}

Podcast Playlist::getPodcast(size_t index) const {
    if (index >= podcastList.size()) {
        throw std::out_of_range("Error: Podcast index out of bounds!");
    }
    return podcastList[index];
}