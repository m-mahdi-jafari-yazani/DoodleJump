#pragma once

#include "Core/Difficulty.hpp"

class DifficultyManager
{
public:

    DifficultyManager();

    void next();

    void previous();

    Difficulty getDifficulty() const;

    const char* getDifficultyName() const;

    bool isBlackHoleEnabled() const;

private:

    Difficulty difficulty;
};