#ifndef PLAYLISTMANAGER_SONG_H
#define PLAYLISTMANAGER_SONG_H
#include <string>
#include "AudioFile.h"

class Song : public AudioFile {
private:
    std::string artist;
    std::string album;

public:
    std::string getAlbum() const;

    void setAlbum(const std::string& a);

    std::string getType() const override;
};



#endif