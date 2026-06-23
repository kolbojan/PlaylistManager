//
// Created by david on 23/06/2026.
//

#include "Songs.h"

Songs::Songs(std::string t, int d, std::string a) : AudioFiles(t, d, 1), artist(a)
{}

std::string Songs::getSongDetails() const {
    return "[Song] " + getBaseDetails() + " by" + artist;
}

