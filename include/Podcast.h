//
// Created by david on 23/06/2026.
//

#ifndef PLAYLISTMANAGER_PODCAST_H
#define PLAYLISTMANAGER_PODCAST_H
#include "AudioFiles.h"

class Podcast : public AudioFiles {
private:
    std::string host;

public:
    Podcast(std::string t, int d, std::string h);

    std::string getPodcastDetails() const;

};


#endif //PLAYLISTMANAGER_PODCAST_H