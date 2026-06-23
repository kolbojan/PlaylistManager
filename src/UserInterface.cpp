#include <iostream>
#include <iomanip>
#include "../include/FileManager.h"
#include "../include/UserInterface.h"
#include "../include/Song.h"


using namespace std;

Playlist selectedPlaylist;

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
    // TODO: selectedPlaylist = fileManager.loadPlaylist(playlist_choice)
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
                addSong();
                break;
            case 2:
                removeSong();
                break;
            case 3:
                changePosition();
                break;
            case 4:
                editSong();
                break;
            case 5:
                editPlaylist();
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

void UserInterface::addSong() {
    // TODO: string playlistName = selectPlaylist.getName();
    string playlistName = "TEST";
    cout << "\n==== Adding a new song to " << playlistName << " ====" << endl;
    cout << "(Enter 0 to return to the playlist)" << endl;
    cout << "Song name: ";
    string songName;
    cin >> songName;
    if (songName == "0") return;
    cout << "Artist name: ";
    string artistName;
    cin >> artistName;
    if (artistName == "0") return;
    cout << "Album name: ";
    string albumName;
    cin >> albumName;
    if (albumName == "0") return;
    cout << "Duration of the song (minutes:seconds): ";
    string duration;
    cin >> duration;
    if (duration == "0") return;
    cout << "Are you ready to add the song to the playlist?" << endl;
    cout << songName << " " << artistName << " " << albumName << " " << duration << endl;
    cout << "Please enter your choice [Y/n]: ";
    string finalChoice;
    cin >> finalChoice;
    if (finalChoice == "n") return;
    Song newSong;
    // TODO: Attributes of Song class:
    // newSong.name = songName;
    // newSong.artist = artistName;
    // newSong.album = albumName;
    // newSong.duration = duration;
    try {
        // TODO: selectedPlaylist.addSong(newSong);
    } catch (...) {
        cout << "An error occurred while trying to add your song!" << endl;
        return;
    }
    cout << "Successfully added a new song to the playlist!" << endl;
}

void UserInterface::removeSong() {
    cout << "Which song do you want to remove?" << endl;
    cout << "(Enter 0 to return to the playlist)" << endl;
    cout << "Song number: ";
    int songNumber;
    cin >> songNumber;
    if (songNumber == 0) return;
    try {
        // TODO: Playlist.removeSong(songNumber)
    } catch (...) {
        cout << "An error occurred while trying to remove song!" << endl;
        return;
    }
    cout << "Successfully removed the song!";
}

void UserInterface::changePosition() {
    cout << "Which song do you want to move?" << endl;
    cout << "(Enter 0 to return to the playlist)" << endl;
    cout << "Song number: ";
    int songNumber;
    cin >> songNumber;
    if (songNumber == 0) return;
    cout << "Number of the song in front of which you wish to place your song: ";
    int songPositionNumber;
    cin >> songPositionNumber;
    if (songPositionNumber == 0) return;
    try {
        // TODO: Playlist.reorderSong(songNumber, songPositionNumber)
        // It will reorder the internal vector containing all the songs so that songNumber is in front of songPosition.
    } catch (...) {
        cout << "An error occurred while trying to remove song!" << endl;
        return;
    }
    cout << "Successfully moved the song!";
}


void UserInterface::editSong() {
    cout << "Which song do you want to edit?" << endl;
    cout << "(Enter 0 to return to the playlist)" << endl;
    cout << "Song number: ";
    int songNumber;
    cin >> songNumber;
    if (songNumber == 0) return;
    Song songToEdit; // TODO: Playlist.getSong(songNumber);
    // cout << "[1] " << songToEdit.name << endl;
    // cout << "[2] " << songToEdit.artist << endl;
    // cout << "[3] " << songToEdit.album << endl;
    // cout << "[4] " << songToEdit.duration << endl;
    cout << "Which property do you wish to edit?" << endl;
    cout << "(Enter 0 to return to the playlist)" << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 0:
            return;

        case 1: {
            cout << "New name: ";
            string newSongName;
            cin >> newSongName;
            //songToEdit.name = newSongName;
            break;
        }

        case 2: {
            cout << "New artist name: ";
            string newSongArtist;
            cin >> newSongArtist;
            //songToEdit.artist = newSongArtist;
            break;
        }
        case 3: {
            cout << "New album name: ";
            string newSongAlbum;
            cin >> newSongAlbum;
            //songToEdit.album = newSongAlbum;
            break;
        }
        case 4: {
            cout << "New duration (minutes:seconds) : ";
            string newSongDuration;
            cin >> newSongDuration;
            //songToEdit.duration = newSongDuration;
            break;
        }
    }

    try {
        // TODO: selectedPlaylist.updateSong(songNumber, songToEdit);
        // Will replace the song specified by the songNumber to a new one (songToEdit)
    } catch (...) {
        cout << "An error occurred while trying to edit the song!" << endl;
        return;
    }
    cout << "Successfully edited the song!" << endl;
}

void UserInterface::editPlaylist() {
    cout << "(Enter 0 to return to the playlist)" << endl;
    cout << "Enter the new name of the playlist: ";
    string newPlaylistName;
    cin >> newPlaylistName;
    if (newPlaylistName == "0") return;
    try {
        // TODO: selectedPlaylist.changeName(newPlaylistName);
    } catch (...) {
        cout << "An error occurred while trying rename the playlist!" << endl;
        return;
    }
    cout << "Successfully renamed the playlist!" << endl;

}