/**
 * @file tiles.cpp
 * @author Michael J Habermann
 * @brief The tiles functions
 * @date 2023-05-04
 *
 */
#include "tiles.h"

/**
 * @brief Construct a new tiles::tiles object
 *
 * @param textureName Name of the texture
 * @param x The x position of the tile
 * @param y The y postion of the tile
 * @param isFree Tells if tile is free(Note for future implementation)
 */
tiles::tiles(std::string textureName, int x, int y, bool isFree)
{
    pos.x = x;
    pos.y = y;
    sprite.setPosition(pos);
    isPassable = isFree;
    setUpSprite(textureName, tileNames[0]);
}
/**
 * @brief Construct a new tiles::tiles object
 *
 * @param textureName Name of the texture
 * @param x The x position of the tile
 * @param y The y postion of the tile
 * @param isFree Tells if tile is free(Note for future implementation)
 * @param tileType Sets what type of tile this is
 */
tiles::tiles(std::string textureName, int x, int y, bool isFree, std::string tileType)
{
    pos.x = x;
    pos.y = y;
    sprite.setPosition(pos);
    isPassable = isFree;
    setUpSprite(textureName, tileType);
}
/**
 * @brief Sets up the sprite for the class
 *
 * @param textureName The name of the texture for setting up the tiles
 * @param tileName The name of the tile the user selects
 */
void tiles::setUpSprite(std::string textureName, std::string tileName)
{
    if (!tileTextures.loadFromFile(textureName))
    {
        std::cout << "error loading tile file!" << std::endl;
        exit(1);
    }
    tileTextures.setSmooth(false);
    sprite.setTexture(tileTextures);
    for (int i = 0; i < 10; i++)
    {
        if (tileName == tileNames[i])
            sprite.setTextureRect(sf::IntRect(coordinatesForSprites[i].x, coordinatesForSprites[i].y, 32, 32));
    }
}