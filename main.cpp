/**
 * @file main.cpp
 * @author Zackary Morrow
 * @brief  This program testing a menu system for the final project
 * @version 0.1
 * @date 4-19-23
 * 
 * @copyright Copyright (c) 2022
 * @acknowledgment https://code.markrichards.ninja/sfml/how-to-create-simple-buttons-for-your-sfml-game
 * compile command: g++ -std=c++11 main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
 * 
 * 
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 500), "Menu!");
    sf::RectangleShape rect(sf::Vector2f(128.0f, 128.0f));
    rect.setFillColor(sf::Color::Black);
    rect.setScale(800.0f, 500.0f);
   

//menu banner
    Button menu;
    menu.setText("MENU");
    menu.setPosition({400, 25});
    menu.setSize({200, 71});
    menu.setColor(sf::Color::Black);
    menu.setColorTextHover(sf::Color::White);
    menu.setColorTextNormal(sf::Color::White);
//menu banner

//test
   Button party;
   party.setText("PARTY");
   party.setPosition({400, 125});
   party.setSize({200, 71});
   party.setColor(sf::Color(0,0,0));
   party.setColorTextHover(sf::Color::Green);
   party.setColorTextNormal(sf::Color::Red);
//test

//test
   Button items;
   items.setText("ITEMS");
   items.setPosition({400, 225});
   items.setSize({200, 71});
   items.setColor(sf::Color(0,0,0));
   items.setColorTextHover(sf::Color::Green);
   items.setColorTextNormal(sf::Color::Red);
//test   

//test
   Button magic;
   magic.setText("MAGIC");
   magic.setPosition({400, 325});
   magic.setSize({200, 71});
   magic.setColor(sf::Color(0,0,0));
   magic.setColorTextHover(sf::Color::Green);
   magic.setColorTextNormal(sf::Color::Red);
//test

//test
   Button quit;
   quit.setText("QUIT");
   quit.setPosition({400, 425});
   quit.setSize({200, 71});
   quit.setColor(sf::Color(0,0,0));
   quit.setColorTextHover(sf::Color::Green);
   quit.setColorTextNormal(sf::Color::Red);
//test
    

   while (window.isOpen())
   {
       sf::Event event;
       while (window.pollEvent(event))
       {
           if(event.type == sf::Event::Closed)
                {
                    window.close();  
                }
        
            
                

        menu.updateMenu(event, window);    
        party.updateParty(event, window);
        items.updateItems(event, window);
        magic.updateMagic(event, window);
        quit.updateQuit(event, window);
       }

       //window.clear(sf::Color::Black);
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
       {
            window.draw(rect);
            window.draw(menu);
            window.draw(party);
            window.draw(items);
            window.draw(magic);
            window.draw(quit);
            
       }
       
       
       //window.draw(rect);
       if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition().x >0 && sf::Mouse::getPosition().x<800)
       {
            
            
            rect.setFillColor(sf::Color::Black);
            rect.setScale(800.0f, 500.0f);
            //window.draw(rect);
            
            
       }

       window.display();
   }

   return 0;
}






/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 500), "MyButton!");
    sf::Texture texture;
    if (!texture.loadFromFile("button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    //create sprite that look like a button
    sf::Sprite button(texture);
    
    //get size of image
    sf::Vector2u imageSize=texture.getSize();
    //change origin to the center of the image (makes rotation easy)
    button.setOrigin(imageSize.x/2, imageSize.y/2);
    //set position
    sf::Vector2f position={300,200};
    button.setPosition(position.x,position.y);
    //choose color
    button.setColor(sf::Color(0, 0, 255));
    //set size as a ration of original size
    button.setScale(0.5,0.5);
    //Make label
    sf::Font font;
    if (!font.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    sf::Text text;
    text.setFont(font);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = button.getGlobalBounds().height/2;
    text.setCharacterSize(fontSize);
    //set label
    text.setString("Push me!");
    //set origin to the middle
    text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
    //set position at the middle of the button
    text.setPosition(position.x, position.y-fontSize/4);
    //choose colors
    sf::Color textNormal = sf::Color::Green;
    sf::Color textHover = sf::Color::Red;
    text.setFillColor(textNormal);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            //get position of the mouse
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            bool mouseInButton =    mousePosition.x >= button.getPosition().x - button.getGlobalBounds().width/2
                                    && mousePosition.x <= button.getPosition().x + button.getGlobalBounds().width/2
                                    && mousePosition.y >= button.getPosition().y - button.getGlobalBounds().height/2
                                    && mousePosition.y <= button.getPosition().y + button.getGlobalBounds().height/2;
            if(event.type == sf::Event::MouseMoved)
            {
                if(mouseInButton)
                {
                    text.setFillColor(textHover);
                }
                else
                {
                    text.setFillColor(textNormal);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)////////////////////////////////
            {
                if(event.mouseButton.button==sf::Mouse::Left)
                {
                    if(mouseInButton)
                    {
                        button.setRotation(180);
                    }
                    else
                    {
                        button.setRotation(0);
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button==sf::Mouse::Left)
                {
                    if(mouseInButton)
                    {
                        text.setFillColor(textHover);
                        button.setRotation(0);
                    }
                    else
                    {
                        text.setFillColor(textNormal);
                        button.setRotation(0);
                    }
                }
            }
        }
        window.clear();
        window.draw(button);
        window.draw(text);
        window.display();
    }
    return 0;
}
*/