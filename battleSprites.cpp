#include "battleSprites.h"

battleSprites::battleSprites()
{
    characterChoice = spriteSelection[0];
    charTexture.loadFromFile("battlesprites.png");
}
battleSprites::battleSprites(std::string name)
{
    for (int i = 0; i < 4; i++)
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
    charTexture.loadFromFile("battlesprites.png");
    charSprite.setTexture(charTexture);
    charSprite.scale(sf::Vector2f(4.f, 4.f));
    if (characterChoice == spriteSelection[2])
    {
        offset = battleSpriteOffset[2];
        charSprite.move(1050.f, 23.f);
    }
    else if (characterChoice == spriteSelection[3])
    {
        offset = battleSpriteOffset[3];
        charSprite.move(1050.f, 161.f);
    }
    else if (characterChoice == spriteSelection[1])
    {
        offset = battleSpriteOffset[1];
        charSprite.move(1050.f, 299.f);
    }
    else
    {
        offset = battleSpriteOffset[0];
        charSprite.move(1050.f, 437.f);
    }
    charSprite.setTextureRect(sf::IntRect(0, offset, 24, 24));
}