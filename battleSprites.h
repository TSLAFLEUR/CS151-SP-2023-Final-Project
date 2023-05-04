/**
 * @file battleSprites.h
 * @author Michael J Habermann
 * @brief Header file for the battlesprites
 * @date 2023-05-04
 * 
 * 
 */
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "entity.h"
#include "combat.h"
#include "menu.h"
#include "walking.h"
const int battleSpriteOffset[4] = {0,24,48,72};
struct battleSprites
{
public:
    battleSprites(std::string name);
    // void loadCharTexture();
    void loadCharSprite();
    sf::Texture charTexture;
    int offset;
    // textureTile.loadFromFile("rpg_textures.png");
    sf::Sprite charSprite;
    std::string characterChoice;
};