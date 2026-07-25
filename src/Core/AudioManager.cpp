#include "Core/AudioManager.hpp"

#include <algorithm>

#include "Core/ResourceManager.hpp"

void AudioManager::play(const std::string& soundID)
{
    activeSounds.emplace_back();

    auto& sound = activeSounds.back();

    sound.setBuffer(
        ResourceManager::getInstance().getSound(soundID)
    );

    sound.setVolume(soundVolume);

    sound.play();

    activeSounds.erase(
        std::remove_if(
            activeSounds.begin(),
            activeSounds.end(),
            [](const sf::Sound& s)
            {
                return s.getStatus() == sf::Sound::Stopped;
            }),
        activeSounds.end());
}

void AudioManager::playMusic(const std::string& filePath)
{
    if (!music.openFromFile(filePath))
    {
        return;
    }

    music.setLoop(true);
    music.play();
}

void AudioManager::stopMusic()
{
    music.stop();
}

void AudioManager::pauseMusic()
{
    music.pause();
}

void AudioManager::resumeMusic()
{
    if (music.getStatus() == sf::Music::Paused)
        music.play();
}

void AudioManager::setSoundVolume(float volume)
{
    soundVolume = volume;
}

void AudioManager::setMusicVolume(float volume)
{
    music.setVolume(volume);
}

bool AudioManager::isMusicPlaying() const
{
    return music.getStatus() == sf::Music::Playing;
}
