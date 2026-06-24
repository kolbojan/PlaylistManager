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
        static void createPlaylist();

        void mainMenu();

        void addSong();

        void removeSong();

        void changePosition();

        void editSong();

        void editPlaylist();

        void printPlaylistContents(int playlist_choice);

        void selectPlaylists();

        static void printMainMenu();
};


#endif