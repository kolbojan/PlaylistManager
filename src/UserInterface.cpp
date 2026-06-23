#include <iostream>
#include <iomanip>
#include "../include/FileManager.h"
#include "../include/UserInterface.h"


using namespace std;

void UserInterface::start() {
    mainMenu();
}

void UserInterface::printMainMenu() {
    cout << "==== Playlist Manager ====" << endl;

    // Print current library:
    cout << "Your Library: " << endl;
    // TODO: fileManager.printLibrary();
    // Example:
    // [1] My Favourites
    // [2] Bangers
    // [3] Rap

    cout <<
        "0. (Exit)\n"
        "1. Select a playlist\n"
        "2. Create a new playlist" << endl;


    cout << "Enter your choice: ";
}

void UserInterface::mainMenu() {
    bool isRunning = true;
    int choice = -1;

    do {
        printMainMenu();
        cin >> choice;
        switch (choice) {
            case 0:
                break;
            case 1:
                selectPlaylists();
                break;
            case 2:
                createPlaylist();
        }
    } while (choice != 0);

}

void UserInterface::selectPlaylists() {
    int playlistChoice = -1;
    while (playlistChoice != 0) {
        cout << "(Enter 0 to return)" << endl;
        cout << "Choose the playlist: ";
        cin >> playlistChoice;

        switch (playlistChoice) {
            case 0:
                break;
            default:
                // TODO: if(fileManager.playlistExists(playlistChoice)
                if (false) {
                    printPlaylistContents(playlistChoice);
                } else {
                    cout << "Invalid playlist ID!" << endl;
                    cout << "Please enter the number in front of the playlist you wish to select." << endl;
                }
                break;
        }
    }
}

string trim(const string& s, size_t maxLen) {
    if (s.size() <= maxLen) return s;
    return s.substr(0, maxLen - 3) + "...";
}

void UserInterface::printPlaylistContents(int playlist_choice) {
    // TODO: Playlist selectedPlaylist = fileManager.loadPlaylist(playlist_choice)
    // TODO: Refer to this section when adding attributes to Song and Playlist.
    // int id = 1;
    //
    // cout << left
    //      << setw(5)  << "ID"
    //      << setw(30) << "Title"
    //      << setw(25) << "Artist"
    //      << setw(25) << "Album"
    //      << setw(10) << "Duration"
    //      << endl;
    //
    // cout << string(95, '-') << endl;
    //
    // for (const Song& song : selectedPlaylist.getSongs()) {
    //     cout << left
    //          << setw(5)  << id++
    //          << setw(30) << trim(song.getName(), 30)
    //          << setw(25) << trim(song.getArtist(), 25)
    //          << setw(25) << trim(song.getAlbum(), 25)
    //          << setw(10) << song.getDuration()
    //          << endl;
    // }

    int editChoice = -1;
    while (editChoice != 0) {
        cout << "0. (Back)" << endl;
        cout << "1. Add a song" << endl;
        cout << "2. Remove a song" << endl;
        cout << "3. Change the position of a song" << endl;
        cout << "4. Edit the properties of a song" << endl;
        cout << "5. Edit the properties of the playlist" << endl;

        cout << "Enter your choice: ";
        cin >> editChoice;

        switch (editChoice) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice number!" << endl;
                cout << "Please enter the number in front of the option you wish to select." << endl;
                break;
        }
    }

}

void UserInterface::createPlaylist() {
    cout << "\n==== Creating a new playlist ====" << endl;
    cout << "Playlist name: ";
    string playlistName;
    cin >> playlistName;
    try {
        // TODO: FileManager.createPlaylist(playlistName)
    } catch (...) {
        cout << "Something went wrong while creating your playlist!" << endl;
        return;
    }

    cout << "\nSuccessfully created \"" << playlistName << "\" playlist!" << endl;
}