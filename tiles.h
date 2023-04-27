#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
const sf::Vector2i coordinatesForSprites[10] = {{352,0},{384,32},{384,64},{352,32},{320,192},{448,96},{448,128},{448,160},{416,128},{416,160}};
const std::string tileNames[10] = {"middleStone","stone top left","stone bottom left","stone top right", "Wall", "carpet middle",
                                   "carpet top left","carpet bottom left","carpet top right","carpet bottom right" };
class tiles
{
public:
sf::Texture tileTextures;
sf::Vector2f pos;
sf::Sprite sprite;
bool isPassable;
//tiles(std::string textureName,sf::Vector2f coords,bool isFree);
tiles(std::string textureName,int x,int y,bool isFree);
tiles(std::string textureName,int x,int y,bool isFree,std::string tileType);
bool setUpSprite(std::string textureName,std::string tileName);
private:


};