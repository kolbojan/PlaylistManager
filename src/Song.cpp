#include "../include/Song.h"

Song::Song(std::string t, int d, std::string a) : AudioFiles(t, d, 1), artist(a)
{}

std::string Song::getSongDetails() const {
    return "[Song] " + getBaseDetails() + " by" + artist;
}
