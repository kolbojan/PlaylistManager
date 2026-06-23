//
// Created by david on 23/06/2026.
//

#ifndef PLAYLISTMANAGER_SONGS_H
#define PLAYLISTMANAGER_SONGS_H
#include <string>
#include "AudioFiles.h"

class Songs : public AudioFiles {
private:
    std::string artist;

public:
    Songs(std::string t, int d, std:: string a);

    std::string getSongDetails() const;
};


#endif //PLAYLISTMANAGER_SONGS_H