#include <iostream>
#include <iomanip>
#include "../include/FileManager.h"
#include "../include/UserInterface.h"
#include "../include/Song.h"
#include "../include/Podcast.h"


using namespace std;

Playlist selectedPlaylist;

FileManager fm = FileManager();

void UserInterface::start() {
    mainMenu();
}

void UserInterface::printMainMenu() {
    cout << "==== Playlist Manager ====" << endl;

    // Print current library:
    cout << "Your Library: " << endl;
    vector<string> playlists = fm.getAllPlaylists();
    int i = 1;
    for (const string& playlistName : playlists) {
        cout << "[" << i << "] " << playlistName << endl;
    }

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
                if (fm.playlistExists(playlistChoice)) {
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
    selectedPlaylist = fm.loadPlaylist(playlist_choice);
    int id = 1;

    cout << left
         << setw(5)  << "ID"
         << setw(30) << "Title"
         << setw(25) << "Artist"
         << setw(25) << "Album"
         << setw(10) << "Duration"
         << endl;

    cout << string(95, '-') << endl;

    for (const auto& song : selectedPlaylist.getSongs()) {

        if (auto* songPtr = dynamic_cast<Song*>(song.get())) {
            cout << left
                 << setw(5)  << id++
                 << setw(30) << trim(songPtr->getName(), 30)
                 << setw(25) << trim(songPtr->getArtist(), 25)
                 << setw(25) << trim(songPtr->getAlbum(), 25)
                 << setw(10) << songPtr->getDuration()
                 << endl;
        }
        else if (auto* podcastPtr = dynamic_cast<Podcast*>(song.get())) {
            cout << left
                 << setw(5)  << id++
                 << setw(30) << trim(podcastPtr->getName(), 30)
                 << setw(25) << trim(podcastPtr->getArtist(), 25)
                 << setw(25) << trim("", 25)
                 << setw(10) << podcastPtr->getDuration()
                 << endl;
        }
    }

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
        fm.createPlaylist(playlistName);
    } catch (...) {
        cout << "Something went wrong while creating your playlist!" << endl;
        return;
    }

    cout << "\nSuccessfully created \"" << playlistName << "\" playlist!" << endl;
}

void UserInterface::addSong() {
    // TODO: string playlistName = selectPlaylist.getName();
    string playlistName = selectedPlaylist.getName();
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


    cout << "Is this a song or a podcast? [s/p]: ";
    string sOrP;
    cin >> sOrP;
    if (sOrP == "0") return;

    string albumName;
    if (sOrP == "s") {
        cout << "Album name: ";
        cin >> albumName;
        if (albumName == "0") return;
    }

    cout << "Duration of the file (minutes:seconds): ";
    string duration;
    cin >> duration;
    if (duration == "0") return;

    cout << "Are you ready to add the song to the playlist?" << endl;
    if (sOrP == "s") {
        cout << songName << " " << artistName << " " << albumName << " " << duration << endl;
    } else {
        cout << songName << " " << artistName << " " << " " << duration << endl;
    }
    cout << "Please enter your choice [Y/n]: ";
    string finalChoice;
    cin >> finalChoice;
    if (finalChoice == "n") return;
    auto newSong = std::make_unique<Song>();
    auto newPodcast = std::make_unique<Podcast>();
    if (sOrP == "s") {
        newSong->setName(songName);
        newSong->setArtist(artistName);
        newSong->setAlbum(albumName);
        newSong->setDuration(duration);
    } else {
        newPodcast->setName(songName);
        newPodcast->setArtist(artistName);
        newPodcast->setDuration(duration);
    }

    try {
        if (sOrP == "s") {
            selectedPlaylist.addSong(std::move(newSong));
        } else {
            selectedPlaylist.addSong(std::move(newPodcast));
        }
        fm.savePlaylist(selectedPlaylist);
    } catch (exception& e) {
        cout << "An error occurred while trying to add your song!" << e.what() << endl;
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
        selectedPlaylist.removeSong(songNumber);
        fm.savePlaylist(selectedPlaylist);
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
        selectedPlaylist.reorderSong(songNumber, songPositionNumber);
        fm.savePlaylist(selectedPlaylist);
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

    AudioFile* songToEdit = selectedPlaylist.getSong(songNumber);

    cout << "[1] " << songToEdit->getName() << endl;
    cout << "[2] " << songToEdit->getArtist() << endl;

    if (songToEdit->getType() == "Song") {
        Song* song = dynamic_cast<Song*>(songToEdit);

        if (song) {
            cout << "[3] " << song->getAlbum() << endl;
        } else {
            cout << "[3] Error reading album" << endl;
        }
    } else {
        cout << "[3] No album data for a Podcast" << endl;
    }

    cout << "[4] " << songToEdit->getDuration() << endl;

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
            string newName;
            cin >> newName;
            songToEdit->setName(newName);
            break;
        }

        case 2: {
            cout << "New artist name: ";
            string newArtist;
            cin >> newArtist;
            songToEdit->setArtist(newArtist);
            break;
        }

        case 3: {
            Song* song = dynamic_cast<Song*>(songToEdit);

            if (song) {
                cout << "New album name: ";
                string newSongAlbum;
                cin >> newSongAlbum;

                song->setAlbum(newSongAlbum);
            }
            break;
        }

        case 4: {
            cout << "New duration (minutes:seconds): ";
            string newDuration;
            cin >> newDuration;
            songToEdit->setDuration(newDuration);
            break;
        }
    }

    try {
        fm.savePlaylist(selectedPlaylist);
    } catch (exception& e) {
        cout << "There was an error saving the playlist!" << e.what() << endl;
        return;
    }

    cout << "Successfully edited the song!" << endl;
}

void UserInterface::editPlaylist() {
    cout << "(Enter 0 to return to the playlist)" << endl;
    cout << "Enter the new name of the playlist: ";
    string newPlaylistName;
    string oldPlaylistName = selectedPlaylist.getName();
    cin >> newPlaylistName;
    if (newPlaylistName == "0") return;
    try {
        // TODO: selectedPlaylist.changeName(newPlaylistName);
        selectedPlaylist.setName(newPlaylistName);
        fm.renamePlaylist(oldPlaylistName, selectedPlaylist);
    } catch (...) {
        cout << "An error occurred while trying rename the playlist!" << endl;
        return;
    }
    cout << "Successfully renamed the playlist!" << endl;

}