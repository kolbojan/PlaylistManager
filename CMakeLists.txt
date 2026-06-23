cmake_minimum_required(VERSION 4.0)
project(PlaylistManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(PlaylistManager src/main.cpp
        src/Song.cpp
        include/Song.h
        src/Playlist.cpp
        include/Playlist.h
        src/FileManager.cpp
        include/FileManager.h
        src/UserInterface.cpp
        include/UserInterface.h
        include/AudioFile.h
        src/AudioFiles.cpp
        src/AudioFiles.h)
