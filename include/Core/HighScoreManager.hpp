#pragma once

class HighScoreManager
{
public:
    HighScoreManager();

    int getHighScore() const;

    void update(int score);

private:
    void load();

    void save() const;

private:
    int highScore;
};