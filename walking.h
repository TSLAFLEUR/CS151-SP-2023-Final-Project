#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

const std::string spriteSelection[4] = {"Buff", "Warrior", "Magician", "Mage"};
const int charOffset[4] = {0,16,32,48};
struct spriteWalk
{
public:
    spriteWalk();
    spriteWalk(std::string name);
    // void loadCharTexture();
    void loadCharSprite();
    sf::Texture charTexture;
    // textureTile.loadFromFile("rpg_textures.png");
    sf::Sprite charSprite;
    std::string characterChoice;
    int offset;
};
void characterWalking(spriteWalk &character);