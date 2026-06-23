//
// Created by david on 23/06/2026.
//

#include "Library.h"
#include <iostream>
#include <stdexcept>

Songs Library::getSong(size_t index) const {
    if (index >= songList.size()) {
        throw std::out_of_range("Error: Song index out of bounds!");
    }
    return songList[index];
}

Podcast Library::getPodcast(size_t index) const {
    if (index >= podcastList.size()) {
        throw std::out_of_range("Error: Podcast index out of bounds!");
    }
    return podcastList[index];
}

