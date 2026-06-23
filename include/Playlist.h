#ifndef PLAYLISTMANAGER_PLAYLIST_H
#define PLAYLISTMANAGER_PLAYLIST_H
#include <vector>
#include "Song.h"
#include "Podcast.h"


class Playlist {
private:
    std::string name;
    std::vector<Song> songs;

public:
    std::string getName() const;
    void setName(const std::string& newName);

    const std::vector<Song>& getSongs() const;

    Song& getSong(int index);

    void addSong(const Song& song);
    void removeSong(int index);

    void reorderSong(int fromIndex, int toIndex);
    void updateSong(int index, const Song& song);
};



#endif