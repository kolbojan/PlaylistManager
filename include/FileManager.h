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

    void createPlaylist(const std::string& name);

    Playlist loadPlaylist(int playlistId);
    void savePlaylist(const Playlist& playlist);

    bool playlistExists(int playlistId);

    std::vector<std::string> getAllPlaylists();
};


#endif