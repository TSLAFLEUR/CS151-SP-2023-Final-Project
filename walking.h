#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

const std::string spriteSelection[4] = {"Buff", "Warrior", "Magician", "Mage"};
struct spriteWalk
{
public:
    spriteWalk();
    spriteWalk(std::string name);
    // void loadCharTexture();
    void loadCharSprite();
    sf::Texture charTexture;
    // textureTile.loadFromFile("rpg_textures.png");
    sf::Sprite charSprite[4];
    std::string characterChoice;
};