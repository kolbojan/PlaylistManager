//
// Created by david on 23/06/2026.
//

#ifndef PLAYLISTMANAGER_LIBRARY_H
#define PLAYLISTMANAGER_LIBRARY_H
#include <vector>
#include "Songs.h"
#include "Podcast.h"

class Library {
private:
    std::vector<Songs> songList;
    std::vector<Podcast> podcastList;

public:
    void addSong(Songs s);
    void addPodcast(Podcast p);
    void printAll() const;

    Songs getSong(size_t index) const;
    Podcast getPodcast(size_t index) const;
};


#endif //PLAYLISTMANAGER_LIBRARY_H