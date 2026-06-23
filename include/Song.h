#ifndef PLAYLISTMANAGER_SONG_H
#define PLAYLISTMANAGER_SONG_H
#include <string>
#include "AudioFile.h"

class Song : public AudioFile {
private:
    std::string artist;
    std::string album;

public:
    std::string getArtist() const;
    std::string getAlbum() const;

    void setArtist(const std::string& a);
    void setAlbum(const std::string& a);
};



#endif