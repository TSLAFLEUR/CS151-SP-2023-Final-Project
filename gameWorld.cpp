#include "gameWorld.h"

GameWorld::GameWorld()
{
    gridLength = 14;
    setUpInitState();
    setUpTiles();
}

void GameWorld::setUpInitState()
{
    playerPos = sf::Vector2i(0, 0);
}

void GameWorld::setUpTiles()
{
    gameTiles.clear();
    std::vector<tiles *> Rows[gridLength];
    // Rows[0].push_back(new tiles("rpg_textures.png",0,0,false));
    for (int j = 0; j < gridLength; j++)
    {
        Rows[0].push_back(new tiles("castle_tiles.png", j * tileDistance + centerOffset , 0 * tileDistance, false, tileNames[0]));
    }
    gameTiles.push_back(Rows[0]);

    for (int i = 1; i < 13; i++)
    {
        Rows[i].push_back(new tiles("castle_tiles.png", 0 * tileDistance+ centerOffset, i * tileDistance, false, tileNames[1]));
        for (int j = 1; j < gridLength - 1; j++)
        {
            Rows[i].push_back(new tiles("castle_tiles.png", j * tileDistance+ centerOffset, i * tileDistance, false, tileNames[4]));
        }
        Rows[i].push_back(new tiles("castle_tiles.png", 13 * tileDistance+ centerOffset, i * tileDistance, false, tileNames[1]));
        gameTiles.push_back(Rows[i]);
    }
    for (int j = 0; j < gridLength; j++)
    {
        Rows[gridLength - 1].push_back(new tiles("castle_tiles.png", j * tileDistance+ centerOffset, 13 * tileDistance, false, tileNames[0]));
    }
    gameTiles.push_back(Rows[gridLength - 1]);
}