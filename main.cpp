/**
 * @file main.cpp
 * @author Zackary Morrow
 * @brief  This program testing a menu system for the final project
 * @version 0.1
 * @date 4-19-23
 * 
 * @copyright Copyright (c) 2022
 * @acknowledgment https://code.markrichards.ninja/sfml/how-to-create-simple-buttons-for-your-sfml-game
 * compile command: g++ -std=c++11 *.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
 * 
 * 
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"
#include "menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Menu!");
    

   while (window.isOpen())
   {
       sf::Event event;
       while (window.pollEvent(event))
       {
           if(event.type == sf::Event::Closed)
                {
                    window.close();  
                }
            int choice;
            //updateChoice(choice);
            displayMenu(window);    
                

        
       }
       //window.display();
   }

   return 0;
}