#ifndef PLAYLISTMANAGER_AUDIOFILE_H
#define PLAYLISTMANAGER_AUDIOFILE_H

#include <string>

class AudioFile {
protected:  // So that subclass Song can access these!
    std::string title;
    std::string duration;
    std::string artist;

public:
    std::string getName() const;
    std::string getDuration() const;
    std::string getArtist() const;

    void setName(const std::string& t);
    void setDuration(const std::string& d);
    void setArtist(const std::string& t);


    virtual ~AudioFile() = default;

    virtual std::string getType() const = 0;
};

#endif