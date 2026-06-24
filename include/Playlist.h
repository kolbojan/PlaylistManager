#ifndef PLAYLISTMANAGER_PLAYLIST_H
#define PLAYLISTMANAGER_PLAYLIST_H
#include <vector>
#include <memory>
#include "AudioFile.h"


class Playlist {
private:
    std::string name;
    std::vector<std::unique_ptr<AudioFile>> content;

public:
    std::string getName() const;
    void setName(const std::string& newName);

    const std::vector<std::unique_ptr<AudioFile>>& getSongs() const;

    AudioFile* getSong(int index);

    void addSong(std::unique_ptr<AudioFile> song);
    void removeSong(int index);

    void reorderSong(int fromIndex, int toIndex);
    void updateSong(int index, std::unique_ptr<AudioFile> song);
};



#endif