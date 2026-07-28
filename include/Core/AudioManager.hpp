#pragma once

#include <SFML/Audio.hpp>

#include <string>
#include <vector>

class AudioManager
{
public:
    AudioManager() = default;

    void play(const std::string& soundID);

    void playMusic(const std::string& filePath);

    void stopMusic();

    void pauseMusic();

    void resumeMusic();

    void setSoundVolume(float volume);

    void setMusicVolume(float volume);

    bool isMusicPlaying() const;

    float getMusicVolume() const;

private:
    std::vector<sf::Sound> activeSounds;

    sf::Music music;

    float soundVolume = 100.f;
    float musicVolume = 100.f;
};