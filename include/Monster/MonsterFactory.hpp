#pragma once

#include <memory>
#include <random>

#include "Monster/Monster.hpp"
#include "Monster/MonsterType.hpp"

class MonsterFactory
{
public:
    MonsterFactory();

    std::unique_ptr<Monster> createMonster(
        float x,
        float y
    );

private:
    MonsterType chooseMonsterType();

private:
    std::mt19937 randomEngine;

    std::uniform_int_distribution<int> typeDistribution;
};