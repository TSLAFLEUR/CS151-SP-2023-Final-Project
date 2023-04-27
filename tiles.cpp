#include "tiles.h"


tiles::tiles(std::string textureName,int x,int y,bool isFree)
{
    pos.x = x;
    pos.y = y;
    sprite.setPosition(pos);
    isPassable = isFree;
    setUpSprite(textureName,tileNames[0]);
}

tiles::tiles(std::string textureName,int x,int y,bool isFree,std::string tileType)
{
    pos.x = x;
    pos.y = y;
    sprite.setPosition(pos);
    isPassable = isFree;
    setUpSprite(textureName,tileType);
}

bool tiles::setUpSprite(std::string textureName,std::string tileName)
{
    if(!tileTextures.loadFromFile(textureName))
    {
        return false;
    }
    tileTextures.setSmooth(true);
    sprite.setTexture(tileTextures);
    for(int i = 0; i<10;i++)
    {
        if(tileName== tileNames[i])
        sprite.setTextureRect(sf::IntRect(coordinatesForSprites[i].x,coordinatesForSprites[i].y,32,32));
    }
    return true;
    
}