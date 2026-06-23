#ifndef PLAYLISTMANAGER_USERINTERFACE_H
#define PLAYLISTMANAGER_USERINTERFACE_H
#include "FileManager.h"
#include "Playlist.h"


class UserInterface {
    private:
        Playlist playlist;
        FileManager fileManager;

    public:
        void start();

    private:
        void createPlaylist();

        void mainMenu();

        void printPlaylistContents(int playlist_choice);

        void selectPlaylists();

        static void printMainMenu();
};


#endif