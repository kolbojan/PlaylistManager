//
// Created by david on 23/06/2026.
//

#include "AudioFiles.h"

AudioFiles::AudioFiles(std::string t, int d, int Id) : title(t), duration(d), typeId(Id)
{}

std::string AudioFiles::getBaseDetails() const {
    return title + " (" + std::to_string(duration) + "s)";

}
