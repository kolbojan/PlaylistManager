#include "../include/Song.h"


std::string Song::getAlbum() const {
    return album;
}

void Song::setAlbum(const std::string& a) {
    album = a;
}

std::string Song::getType() const
{
    return "Song";
}