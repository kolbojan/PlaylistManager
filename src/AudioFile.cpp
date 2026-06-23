//
// Created by david on 23/06/2026.
//

#include "AudioFile.h"

AudioFile::AudioFile(std::string t, int d, int Id) : title(t), duration(d), typeId(Id)
{}

std::string AudioFile::getBaseDetails() const {
    return title + " (" + std::to_string(duration) + "s)";

}
