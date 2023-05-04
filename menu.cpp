/**
 * @file menu.cpp
 * @author Zackary Morrow
 * @brief implementation file for menu related functions
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "button.h"

/**
 * @brief displays the menu and updates all buttons
 * 
 * @param window is window on the which the menu will be displayed
 */
void displayMenu(sf::RenderWindow &window)
{
   sf::RectangleShape rect(sf::Vector2f(128.0f, 128.0f));
   rect.setFillColor(sf::Color::Black);
   rect.setScale(1600.0f, 900.0f);

   // menu banner
   Button menu;
   menu.setText("MENU");
   menu.setPosition(sf::Vector2f(window.getSize().x / 2, 1 * window.getSize().y / 9));
   menu.setSize({200, 71});
   menu.setColor(sf::Color::Black);
   menu.setColorTextHover(sf::Color::White);
   menu.setColorTextNormal(sf::Color::White);
   // menu banner

   // test
   Button party;
   party.setText("PARTY");
   party.setPosition(sf::Vector2f(window.getSize().x / 2, 3 * window.getSize().y / 9));
   party.setSize({200, 71});
   party.setColor(sf::Color(0, 0, 0));
   party.setColorTextHover(sf::Color::Green);
   party.setColorTextNormal(sf::Color::Red);
   // test

   // test
   Button items;
   items.setText("ITEMS");
   items.setPosition(sf::Vector2f(window.getSize().x / 2, 4 * window.getSize().y / 9));
   items.setSize({200, 71});
   items.setColor(sf::Color(0, 0, 0));
   items.setColorTextHover(sf::Color::Green);
   items.setColorTextNormal(sf::Color::Red);
   // test

   // test
   Button magic;
   magic.setText("MAGIC");
   magic.setPosition(sf::Vector2f(window.getSize().x / 2, 5 * window.getSize().y / 9));
   magic.setSize({200, 71});
   magic.setColor(sf::Color(0, 0, 0));
   magic.setColorTextHover(sf::Color::Green);
   magic.setColorTextNormal(sf::Color::Red);
   // test

   // test
   Button quit;
   quit.setText("QUIT");
   quit.setPosition(sf::Vector2f(window.getSize().x / 2, 6 * window.getSize().y / 9));
   quit.setSize({200, 71});
   quit.setColor(sf::Color(0, 0, 0));
   quit.setColorTextHover(sf::Color::Green);
   quit.setColorTextNormal(sf::Color::Red);
   // test
   int choice = 0;
   menu.updateMenu(window);
   party.updateParty(window, choice);
   items.updateItems(window, choice);
   magic.updateMagic(window, choice);
   quit.updateQuit(window, choice);
   window.draw(rect);

   window.draw(menu);
   window.draw(party);
   window.draw(items);
   window.draw(magic);
   window.draw(quit);

   window.display();
   while (window.isOpen())
   {
      sf::Event event;
      while (window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
         {
            window.close();
         }

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
         {
            choice++;
            if (choice > 4)
               choice = 4;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
         {
            choice--;
            if (choice < 1)
               choice = 1;
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
         {
            return;
         }

         menu.updateMenu(window);
         party.updateParty(window, choice);
         items.updateItems(window, choice);
         magic.updateMagic(window, choice);
         quit.updateQuit(window, choice);
         window.draw(rect);

         window.draw(menu);
         window.draw(party);
         window.draw(items);
         window.draw(magic);
         window.draw(quit);

         // window.display();
      }
   }
}

/**
 * @brief displays the main start menu for the game
 * 
 * @param window the window on which the start menu will be displayed
 * @param font a font used for the menu
 */
void mainMenu(sf::RenderWindow &window,sf::Font &font)
{
   sf::RectangleShape rect(sf::Vector2f(window.getSize().x,window.getSize().y));
   rect.setFillColor(sf::Color::Black);
   //rect.setScale(1600.0f, 900.0f);

   sf::Text title;
   title.setFont(font);
   //title.setOrigin(0,title.getLocalBounds().height/2);
   title.setPosition(window.getSize().x/6,2*window.getSize().y/8);
   title.setScale(4,3);
   title.setString("FINAL DUCK");
   window.draw(title);

   Button start;
   start.setText("START");
   start.setPosition(sf::Vector2f(window.getSize().x/2,4*window.getSize().y/8));
   start.setSize({200, 71});
   start.setColor(sf::Color::Black);
   start.setColorTextHover(sf::Color::Red);
   start.setColorTextNormal(sf::Color::White);

   Button exit;
   exit.setText("QUIT");
   exit.setPosition(sf::Vector2f(window.getSize().x/2,5*window.getSize().y/8));
   exit.setSize({200, 71});
   exit.setColor(sf::Color::Black);
   exit.setColorTextHover(sf::Color::Red);
   exit.setColorTextNormal(sf::Color::White);

   int mainChoice=0;
   window.draw(rect);
   window.draw(start);
   window.draw(exit);
   window.display();
   while (window.isOpen())
   {
      
      sf::Event event;
      while (window.pollEvent(event))
      {
           if(event.type == sf::Event::Closed)
                {
                    window.close();  
                }
        
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
               if(mainChoice<2){
                  mainChoice++;
               } 
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
               if(mainChoice>1){
                  mainChoice--;
               }
            }    
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
               if(mainChoice==1){
                  return;
               }else if(mainChoice==2){
                  window.close();
               }
            }

         start.updateStart(event, window, mainChoice);
         exit.updateExit(event, window, mainChoice);
         window.draw(rect);
         window.draw(title);
         window.draw(start);
         window.draw(exit);
         window.display();
        
      }
   }
}