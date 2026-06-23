#ifndef PLAYLISTMANAGER_SONG_H
#define PLAYLISTMANAGER_SONG_H
#include <string>
#include "AudioFiles.h"

class Song : public AudioFiles {
private:
    std::string artist;

public:
    Song(std::string t, int d, std:: string a);

    std::string getSongDetails() const;
};



#endif