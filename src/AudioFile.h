//
// Created by david on 23/06/2026.
//

#ifndef PLAYLISTMANAGER_AUDIOFILE_H
#define PLAYLISTMANAGER_AUDIOFILE_H
#include <string>

class AudioFile {
private:
    std::string title;
    int duration;
    int typeId;   // 1 = song, 2 = podcast

public:
    AudioFile(std::string t, int d, int Id);

    std::string getBaseDetails() const;

    std::string getBaseDetails();
    int getTypeId() const {
        return typeId;
    }

};


#endif //PLAYLISTMANAGER_AUDIOFILES_H