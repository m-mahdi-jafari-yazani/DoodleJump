#pragma once

class ScoreManager
{
public:
    void add(float distance);

    int getScore() const;

    void reset();

private:
    int score = 0;
};