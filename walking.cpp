#include "walking.h"
spriteWalk::spriteWalk()
{
    characterChoice = spriteSelection[0];
    charTexture.loadFromFile("battlesprites.png");
}
spriteWalk::spriteWalk(std::string name)
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
            std::cout << "error loading character choosing default character" << std::endl;
            characterChoice = spriteSelection[0];
        }
    }
    charTexture.loadFromFile("walking sprites.png");
    charSprite[0].setTexture(charTexture);
    charSprite[1].setTexture(charTexture);
    charSprite[2].setTexture(charTexture);
    charSprite[3].setTexture(charTexture);
    if (characterChoice == spriteSelection[0])
    {
        for (int i = 0; i < 4; i++)
        {
            charSprite[i].setTextureRect(sf::IntRect((i * 16), 0, 16, 16));
            //charSprite[i].setOrigin(16.f / 2.f, 16.f / 2.f);
        }
    }
    else if (characterChoice == spriteSelection[1])
    {
        for (int i = 0; i < 4; i++)
        {
            charSprite[i].setTextureRect(sf::IntRect((i * 16), 16, 16, 16));
            //charSprite[i].setOrigin(16.f / 2.f, 16.f / 2.f);
        }
    }
    else if (characterChoice == spriteSelection[2])
    {
        for (int i = 0; i < 4; i++)
        {
            charSprite[i].setTextureRect(sf::IntRect((i * 16), 32, 16, 16));
           // charSprite[i].setOrigin(16.f / 2.f, 16.f / 2.f);
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            charSprite[i].setTextureRect(sf::IntRect((i * 16), 48, 16, 16));
            //charSprite[i].setOrigin(16.f / 2.f, 16.f / 2.f);
        }
    }

}