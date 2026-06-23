//
// Created by david on 23/06/2026.
//

#ifndef PLAYLISTMANAGER_AUDIOFILES_H
#define PLAYLISTMANAGER_AUDIOFILES_H
#include <string>

class AudioFiles {
private:
    std::string title;
    int duration;
    int typeId;   // 1 = song, 2 = podcast

public:
    AudioFiles(std::string t, int d, int Id);

    std::string getBaseDetails() const;

    std::string getBaseDetails();
    int getTypeId() const {
        return typeId;
    }

};


#endif //PLAYLISTMANAGER_AUDIOFILES_H