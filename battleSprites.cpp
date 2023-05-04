/**
 * @file battleSprites.cpp
 * @author Michael J Habermann
 * @brief Functions for the battlesprites
 * @date 2023-05-04
 *
 */
#include "battleSprites.h"

/**
 * @brief Construct a new battle Sprites::battle Sprites object
 * 
 * @param name The name of the sprite you want to pull up1
 */
battleSprites::battleSprites(std::string name)
{
    for (int i = 0; i < 5; i++)
    {
        if (name == spriteSelection[i])
        {
            characterChoice = name;
            break;
        }
        else
        {
            // std::cout << "error loading character choosing default character" << std::endl;
            characterChoice = spriteSelection[0];
            offset = charOffset[0];
        }
    }

    charSprite.scale(sf::Vector2f(4.f, 4.f));
    if (characterChoice == spriteSelection[2])
    {
        charTexture.loadFromFile("battlesprites.png");
        charSprite.setTexture(charTexture);
        offset = battleSpriteOffset[2];
        charSprite.move(1050.f, 23.f);
        charSprite.setTextureRect(sf::IntRect(0, offset, 24, 24));
    }
    else if (characterChoice == spriteSelection[3])
    {
        charTexture.loadFromFile("battlesprites.png");
        charSprite.setTexture(charTexture);
        offset = battleSpriteOffset[3];
        charSprite.move(1050.f, 161.f);
        charSprite.setTextureRect(sf::IntRect(0, offset, 24, 24));
    }
    else if (characterChoice == spriteSelection[1])
    {
        charTexture.loadFromFile("battlesprites.png");
        charSprite.setTexture(charTexture);
        offset = battleSpriteOffset[1];
        charSprite.move(1050.f, 299.f);
        charSprite.setTextureRect(sf::IntRect(0, offset, 24, 24));
    }
    else if (characterChoice == spriteSelection[0])
    {
        charTexture.loadFromFile("battlesprites.png");
        charSprite.setTexture(charTexture);
        offset = battleSpriteOffset[0];
        charSprite.move(1050.f, 437.f);
        charSprite.setTextureRect(sf::IntRect(0, offset, 24, 24));
    }
    else
    {
        charTexture.loadFromFile("goblin.png");
        charSprite.setTexture(charTexture);
        offset = 0;
        charSprite.move(50.f, 50.f);
        charSprite.setTextureRect(sf::IntRect(0, offset, 48, 48));
        charSprite.scale(sf::Vector2f(2.f, 2.f));
    }
}