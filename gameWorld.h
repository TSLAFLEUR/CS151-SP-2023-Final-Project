/**
 * @file gameWorld.h
 * @author Michael J Habermann
 * @brief The overworld for the gameworld
 * @date 2023-05-04
 * 
 * 
 */
#pragma once

#include "tiles.h"
#include <vector>

class GameWorld
{
public:
    std::vector<std::vector<tiles *>> gameTiles;
    int gridLength;
    GameWorld();
    void setUpInitState();
    void setUpTiles();

private:
    sf::Vector2i playerPos;
    sf::Vector2i enemyPos;
};
