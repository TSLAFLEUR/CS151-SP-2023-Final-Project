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
            // std::cout << "error loading character choosing default character" << std::endl;
            characterChoice = spriteSelection[0];
            offset = charOffset[0];
        }
    }
    charTexture.loadFromFile("walking sprites.png");
    charSprite.setTexture(charTexture);
    if (characterChoice == spriteSelection[0])
    {
        offset = charOffset[0];
    }
    else if (characterChoice == spriteSelection[1])
    {
        offset = charOffset[1];
    }
    else if (characterChoice == spriteSelection[2])
    {
        offset = charOffset[2];
    }
    else
    {
        offset = charOffset[3];
    }
    charSprite.setTextureRect(sf::IntRect(0, offset, 16, 16));
    charSprite.move(64.f, 64.f);
}

void characterWalking(spriteWalk &character)
{
    //std::cout << character.charCoords[0] << ' ' <<  character.charCoords[1] << std::endl;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&character.charCoords[0] >= 64)
        {
            // left key is pressed: move our character
            // character.charSprite.setTextureRect(sf::IntRect(48, 0, 16, 16));
            character.charSprite.move(-1.f, 0.f);
            // if (clock.getElapsedTime().asSeconds() > 1.0f)
            //{
                character.charCoords[0]--;
            if (character.charSprite.getTextureRect() == (sf::IntRect(48, character.offset, 16, 16)))
            {
                character.charSprite.setTextureRect(sf::IntRect(32, character.offset, 16, 16));
            }
            else
            {
                character.charSprite.setTextureRect(sf::IntRect(48, character.offset, 16, 16));
            }
            // }
            // character.charSprite.setTextureRect(sf::IntRect(32, 0, 16, 16));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& character.charCoords[1] >= 64)
        {
            // left key is pressed: move our character
            // character.charSprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
            character.charSprite.move(0.f, -1.f);
            character.charCoords[1]--;
            if (character.charSprite.getTextureRect() == (sf::IntRect(96, character.offset, 16, 16)))
            {
                character.charSprite.setTextureRect(sf::IntRect(16, character.offset, 16, 16));
            }
            else
            {
                character.charSprite.setTextureRect(sf::IntRect(96, character.offset, 16, 16));
            }
        }

       else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& character.charCoords[0] <= 912)
        {
            // left key is pressed: move our character
            // character.charSprite.setTextureRect(sf::IntRect(64, 0, 16, 16));
            character.charSprite.move(1.f, 0.f);
            character.charCoords[0]++;
            if (character.charSprite.getTextureRect() == (sf::IntRect(64, character.offset, 16, 16)))
            {
                character.charSprite.setTextureRect(sf::IntRect(80, character.offset, 16, 16));
                //character.charSprite.setOrigin(16.f / 2.f, 0.f / 2.f);
            }
            else
            {
                character.charSprite.setTextureRect(sf::IntRect(64, character.offset, 16, 16));
                //character.charSprite.setOrigin(16.f / 2.f, 0.f / 2.f);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&character.charCoords[1] <= 896)
        {
            // left key is pressed: move our character
            // character.charSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
            character.charSprite.move(0.f, 1.f);
            character.charCoords[1]++;
            if (character.charSprite.getTextureRect() == (sf::IntRect(112, character.offset, 16, 16)))
            {
                character.charSprite.setTextureRect(sf::IntRect(0, character.offset, 16, 16));
            }
            else
            {
                character.charSprite.setTextureRect(sf::IntRect(112, character.offset, 16, 16));
            }
        }
}