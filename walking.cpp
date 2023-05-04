#include "walking.h"

spriteWalk::spriteWalk()
{
    characterChoice = spriteSelection[0];
    charTexture.loadFromFile("walking sprites.png");
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
    charSprite.move(416.f, 64.f);
}

void characterWalking(spriteWalk &character,Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f, sf::RenderWindow &window, sf::Font &font, int encounter)
{
    //std::cout << character.charCoords[0] << ' ' <<  character.charCoords[1] << std::endl;
    static int pollCounter = 15;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&character.charCoords[0] >= 64)
        {
            // left key is pressed: move our character
            // character.charSprite.setTextureRect(sf::IntRect(48, 0, 16, 16));
            character.charSprite.move(-2.f, 0.f);
            // if (clock.getElapsedTime().asSeconds() > 1.0f)
            //{
                character.charCoords[0]--;
                pollCounter++;
            if (rand()%100==0){
                combat(p,w,b,f,window,font,1);
            }
            if (pollCounter >30)
            {
                character.charSprite.setTextureRect(sf::IntRect(32, character.offset, 16, 16));
            }
            else if (pollCounter < 30)
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
            character.charSprite.move(0.f, -2.f);
            character.charCoords[1]--;
            pollCounter++;
            if (rand()%100==0){
                combat(p,w,b,f,window,font,1);
            }
            if (pollCounter >30)
            {
                character.charSprite.setTextureRect(sf::IntRect(16, character.offset, 16, 16));
            }
            else if (pollCounter < 30)
            {
                character.charSprite.setTextureRect(sf::IntRect(96, character.offset, 16, 16));
            }
        }

       else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& character.charCoords[0] <= 768)
        {
            // left key is pressed: move our character
            // character.charSprite.setTextureRect(sf::IntRect(64, 0, 16, 16));
            character.charSprite.move(2.f, 0.f);
            character.charCoords[0]++;
            pollCounter++;
            if (rand()%100==0){
                combat(p,w,b,f,window,font,1);
            }
            if (pollCounter >30)
            {
                character.charSprite.setTextureRect(sf::IntRect(80, character.offset, 16, 16));
                //character.charSprite.setOrigin(16.f / 2.f, 0.f / 2.f);
            }
            else if (pollCounter < 30)
            {
                character.charSprite.setTextureRect(sf::IntRect(64, character.offset, 16, 16));
                //character.charSprite.setOrigin(16.f / 2.f, 0.f / 2.f);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&character.charCoords[1] <= 768)
        {
            // left key is pressed: move our character
            // character.charSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
            character.charSprite.move(0.f,2.f);
            character.charCoords[1]++;
            pollCounter++;
            if (rand()%100==0){
                combat(p,w,b,f,window,font,1);
            }
            if (pollCounter >30)
            {
                character.charSprite.setTextureRect(sf::IntRect(0, character.offset, 16, 16));
            }
            else if (pollCounter < 30)
            {
                character.charSprite.setTextureRect(sf::IntRect(112, character.offset, 16, 16));
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            sf::RectangleShape combat(sf::Vector2f(window.getSize().x,window.getSize().y));
    combat.setFillColor(sf::Color::Black);
    window.draw(combat);
            displayMenu(window);
        }
            if(pollCounter > 60)
            {
                pollCounter = 0;
            }
}