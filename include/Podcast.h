#ifndef PLAYLISTMANAGER_PODCAST_H
#define PLAYLISTMANAGER_PODCAST_H
#include <string>
#include "AudioFile.h"

class Podcast : public AudioFile {
private:
    std::string artist;

public:
    std::string getType() const override;
};


#endif