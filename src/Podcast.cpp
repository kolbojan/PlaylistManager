//
// Created by david on 23/06/2026.
//

#include "../include/Podcast.h"

Podcast::Podcast(std::string t, int d, std::string h) : AudioFiles(t, d, 2), host(h)
{}

std::string Podcast::getPodcastDetails() const {
    return "[Podcast] " + getBaseDetails() + " hosted by " + host;
}

