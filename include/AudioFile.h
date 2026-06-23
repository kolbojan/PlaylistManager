#ifndef PLAYLISTMANAGER_AUDIOFILE_H
#define PLAYLISTMANAGER_AUDIOFILE_H

#include <string>

class AudioFile {
private:
    std::string title;
    std::string duration;

public:
    std::string getTitle() const;
    std::string getDuration() const;

    void setTitle(const std::string& t);
    void setDuration(const std::string& d);

    virtual ~AudioFile() = default;
};

#endif