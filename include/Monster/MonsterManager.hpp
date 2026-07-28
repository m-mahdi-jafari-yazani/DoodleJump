#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Monster/Monster.hpp"
#include "Monster/MonsterSpawner.hpp"
#include "Platform/PlatformEntry.hpp"
#include "Core/Difficulty.hpp"

class MonsterManager
{
public:

    MonsterManager();

    void update(float deltaTime);

    void draw(sf::RenderWindow& window) const;

    void moveAll(float dy);

    void addMonster(std::unique_ptr<Monster> monster);

    void removeDeadMonsters();

    void clear();

    std::vector<std::unique_ptr<Monster>>& getMonsters();

    const std::vector<std::unique_ptr<Monster>>& getMonsters() const;
    
    void spawnMonsters(const std::vector<PlatformEntry>& platforms); 
    
    void removeOffScreenMonsters();

    void respawnMonsters(const std::vector<PlatformEntry>& platforms);

    void setDifficulty(Difficulty difficulty);

private:
    std::vector<std::unique_ptr<Monster>> monsters;
    MonsterSpawner monsterSpawner;
    Difficulty difficulty = Difficulty::Medium;
};