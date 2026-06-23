#include "../include/Song.h"


std::string Song::getArtist() const {
    return artist;
}

void Song::setArtist(const std::string& a) {
    artist = a;
}

std::string Song::getAlbum() const {
    return album;
}

void Song::setAlbum(const std::string& a) {
    album = a;
}