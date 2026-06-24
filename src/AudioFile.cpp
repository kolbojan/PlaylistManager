#include "../include/AudioFile.h"

std::string AudioFile::getName() const {
    return title;
}

std::string AudioFile::getDuration() const {
    return duration;
}

void AudioFile::setName(const std::string& t) {
    title = t;
}

void AudioFile::setDuration(const std::string& d) {
    duration = d;
}

std::string AudioFile::getArtist() const {
    return artist;
}

void AudioFile::setArtist(const std::string& a) {
    artist = a;
}