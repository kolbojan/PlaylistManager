#ifndef PLAYLISTMANAGER_FILEMANAGER_H
#define PLAYLISTMANAGER_FILEMANAGER_H


#include <string>
#include <vector>
#include "Playlist.h"

class FileManager {
private:
    std::string basePath;

public:
    FileManager();

    void createPlaylist(const std::string &name) const;

    Playlist loadPlaylist(int playlistId) const;

    void savePlaylist(const Playlist &playlist) const;

    bool playlistExists(int playlistId) const;

    std::vector<std::string> getAllPlaylists() const;

    void renamePlaylist(const std::string& old, const Playlist& playlist) const;

    void removePlaylist(const std::string& name) const;
};


#endif