#include "gameWorld.h"

GameWorld::GameWorld()
{
    gridLength = 16;
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
        Rows[0].push_back(new tiles("rpg_textures.png", j * 64, 0 * 64, false, tileNames[4]));
    }
    gameTiles.push_back(Rows[0]);





    for (int i = 1; i < 15; i++)
    {
        Rows[i].push_back(new tiles("rpg_textures.png", 0 * 64, i * 64, false, tileNames[4]));
        for (int j = 1; j < gridLength - 1; j++)
        {
            Rows[i].push_back(new tiles("rpg_textures.png", j * 64, i * 64, false, tileNames[0]));
        }
        Rows[i].push_back(new tiles("rpg_textures.png", 15 * 64, i * 64, false, tileNames[4]));
        gameTiles.push_back(Rows[i]);
    }
    for (int j = 0; j < gridLength; j++)
    {
        Rows[15].push_back(new tiles("rpg_textures.png", j * 64, 15 * 64, false, tileNames[4]));
    }
    gameTiles.push_back(Rows[15]);
}