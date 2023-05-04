#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "entity.h"
#include "combat.h"
#include "menu.h"

const std::string spriteSelection[5] = {"Buff", "Warrior", "Magician", "Mage", "enemy"};
const int charOffset[4] = {0,16,32,48};
struct spriteWalk
{
public:
    spriteWalk();
    spriteWalk(std::string name);
    // void loadCharTexture();
    //void loadCharSprite();
    sf::Texture charTexture;
    // textureTile.loadFromFile("rpg_textures.png");
    sf::Sprite charSprite;
    std::string characterChoice;
    int offset;
    int charCoords[2] = {64,64};
};
void characterWalking(spriteWalk &character,Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f, sf::RenderWindow &window, sf::Font &font, int encounter);