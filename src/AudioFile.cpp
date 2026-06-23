#include "../include/AudioFile.h"

std::string AudioFile::getTitle() const {
    return title;
}

std::string AudioFile::getDuration() const {
    return duration;
}

void AudioFile::setTitle(const std::string& t) {
    title = t;
}

void AudioFile::setDuration(const std::string& d) {
    duration = d;
}