#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
const sf::Vector2i coordinatesForSprites[10] = {{0,0},{0,16},{0,32},{0,48},{0,64},{0,80},{0,96},{0,112},{0,128},{0,144}};
const std::string tileNames[10] = {"MiddleWall","left_wall","right_wall","left_tile", "right_tile", "grass",
                                   "chair","dragon","black","carpet bottom right" };
const int tileDistance = 64;
const int centerOffset = 352;
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