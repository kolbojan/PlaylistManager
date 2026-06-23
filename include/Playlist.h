#ifndef PLAYLISTMANAGER_PLAYLIST_H
#define PLAYLISTMANAGER_PLAYLIST_H
#include <vector>
#include "Song.h"
#include "Podcast.h"


class Playlist {
private:
    std::vector<Song> songList;
    std::vector<Podcast> podcastList;

public:
    void addSong(Song s);
    void addPodcast(Podcast p);
    void printAll() const;

    Song getSong(size_t index) const;
    Podcast getPodcast(size_t index) const;
};



#endif