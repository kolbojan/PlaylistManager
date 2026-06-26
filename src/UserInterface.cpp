#include <iostream>
#include <iomanip>
#include "../include/FileManager.h"
#include "../include/UserInterface.h"
#include "../include/Song.h"
#include "../include/Podcast.h"
#include <limits>


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
        i++;
    }

    cout <<
        "\n0. (Exit)\n"
        "1. Select a playlist\n"
        "2. Create a new playlist" << endl;


    cout << "\nEnter your choice: ";
}

void UserInterface::mainMenu() {
    bool isRunning = true;
    int choice = -1;

    do {
        printMainMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (playlistChoice) {
            case 0:
                break;
            default:
                if (fm.playlistExists(playlistChoice)) {
                    printPlaylistContents(playlistChoice);
                    return;
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


    int editChoice = -1;
    while (editChoice != 0) {
        selectedPlaylist = fm.loadPlaylist(playlist_choice);
        int id = 1;
        cout << endl;
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

        cout << "\n0. (Back)" << endl;
        cout << "1. Add a song" << endl;
        cout << "2. Remove a song" << endl;
        cout << "3. Change the position of a song" << endl;
        cout << "4. Edit the properties of a song" << endl;
        cout << "5. Edit the properties of the playlist" << endl;

        cout << "\nEnter your choice: ";
        cin >> editChoice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
    cout << "(Enter 0 to return to the main menu)" << endl;
    cout << "Playlist name: ";
    string playlistName;
    getline(cin, playlistName);
    if (playlistName == "0") return;
    try {
        fm.createPlaylist(playlistName);
    } catch (...) {
        cout << "Something went wrong while creating your playlist!" << endl;
        return;
    }

    cout << "\nSuccessfully created \"" << playlistName << "\" playlist!" << endl;
}

void UserInterface::addSong() {
    string playlistName = selectedPlaylist.getName();
    cout << "\n==== Adding a new song to " << playlistName << " ====" << endl;
    cout << "(Enter 0 to return to the playlist)" << endl;
    cout << "Song name: ";
    string songName;
    getline(cin, songName);
    if (songName == "0") return;


    cout << "Artist name: ";
    string artistName;
    getline(cin, artistName);
    if (artistName == "0") return;

    cout << "Is this a song or a podcast? [s/p]: ";
    string sOrP;
    cin >> sOrP;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (sOrP == "0") return;

    string albumName;
    if (sOrP == "s") {
        cout << "Album name: ";
        getline(cin, albumName);
        if (albumName == "0") return;
    }

    cout << "Duration of the file (minutes:seconds): ";
    string duration;
    getline(cin, duration);
    if (duration == "0") return;

    cout << "Are you ready to add the song to the playlist?" << endl;
    if (sOrP == "s") {
        cout << songName << " " << artistName << " " << albumName << " " << duration << endl;
    } else {
        cout << songName << " " << artistName << " " << " " << duration << endl;
    }
    cout << "Please enter your choice [y/n]: ";
    string finalChoice;
    cin >> finalChoice;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (songNumber == 0) return;
    try {
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
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (songNumber == 0) return;
    cout << "Number of the song in front of which you wish to place your song: ";
    int songPositionNumber;
    cin >> songPositionNumber;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (songPositionNumber == 0) return;
    try {
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
    cout << "(Enter 0 to return to the p1laylist)" << endl;
    cout << "Song number: ";

    int songNumber;
    cin >> songNumber;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {

        case 0:
            return;

        case 1: {
            cout << "New name: ";
            string newName;
            getline(cin, newName);
            songToEdit->setName(newName);
            break;
        }

        case 2: {
            cout << "New artist name: ";
            string newArtist;
            getline(cin, newArtist);
            songToEdit->setArtist(newArtist);
            break;
        }

        case 3: {
            Song* song = dynamic_cast<Song*>(songToEdit);

            if (song) {
                cout << "New album name: ";
                string newSongAlbum;
                getline(cin, newSongAlbum);

                song->setAlbum(newSongAlbum);
            }
            break;
        }

        case 4: {
            cout << "New duration (minutes:seconds): ";
            string newDuration;
            getline(cin, newDuration);
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
    getline(cin, newPlaylistName);
    if (newPlaylistName == "0") return;
    try {
        selectedPlaylist.setName(newPlaylistName);
        fm.renamePlaylist(oldPlaylistName, selectedPlaylist);
    } catch (...) {
        cout << "An error occurred while trying rename the playlist!" << endl;
        return;
    }
    cout << "Successfully renamed the playlist!" << endl;

}