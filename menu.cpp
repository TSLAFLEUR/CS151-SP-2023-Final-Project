#include "button.h"

void displayMenu(sf::RenderWindow &window)
{
    sf::RectangleShape rect(sf::Vector2f(128.0f, 128.0f));
    rect.setFillColor(sf::Color::Black);
    rect.setScale(1600.0f, 900.0f);
   

//menu banner
    Button menu;
    menu.setText("MENU");
    menu.setPosition({640, 25});
    menu.setSize({200, 71});
    menu.setColor(sf::Color::Black);
    menu.setColorTextHover(sf::Color::White);
    menu.setColorTextNormal(sf::Color::White);
//menu banner

//test
   Button party;
   party.setText("PARTY");
   party.setPosition({640, 125});
   party.setSize({200, 71});
   party.setColor(sf::Color(0,0,0));
   party.setColorTextHover(sf::Color::Green);
   party.setColorTextNormal(sf::Color::Red);
//test

//test
   Button items;
   items.setText("ITEMS");
   items.setPosition({640, 225});
   items.setSize({200, 71});
   items.setColor(sf::Color(0,0,0));
   items.setColorTextHover(sf::Color::Green);
   items.setColorTextNormal(sf::Color::Red);
//test   

//test
   Button magic;
   magic.setText("MAGIC");
   magic.setPosition({640, 325});
   magic.setSize({200, 71});
   magic.setColor(sf::Color(0,0,0));
   magic.setColorTextHover(sf::Color::Green);
   magic.setColorTextNormal(sf::Color::Red);
//test

//test
   Button quit;
   quit.setText("QUIT");
   quit.setPosition({640, 425});
   quit.setSize({200, 71});
   quit.setColor(sf::Color(0,0,0));
   quit.setColorTextHover(sf::Color::Green);
   quit.setColorTextNormal(sf::Color::Red);
//test
   int choice;
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
               choice++;
               if(choice>4)
                  choice = 4;   
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
               choice--;
               if(choice<0)
                  choice = 0;
            }    
                     

         menu.updateMenu(event, window);    
         party.updateParty(event, window, choice);
         items.updateItems(event, window, choice);
         magic.updateMagic(event, window, choice);
         quit.updateQuit(event, window, choice);
         window.draw(rect);

            window.draw(menu);
            window.draw(party);
            window.draw(items);
            window.draw(magic);
            window.draw(quit);

         //window.display();
        
      }

      //  //window.clear(sf::Color::Black);
      //  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      //  {
            
            
      //  }
       
       //window.draw(rect);
       

       //window.display();
   }
}

void mainMenu(sf::RenderWindow &window)
{
   sf::RectangleShape rect(sf::Vector2f(128.0f, 128.0f));
   rect.setFillColor(sf::Color::Black);
   rect.setScale(1600.0f, 900.0f);

   Button start;
   start.setText("START");
   start.setPosition({640, 25});
   start.setSize({200, 71});
   start.setColor(sf::Color::Black);
   start.setColorTextHover(sf::Color::White);
   start.setColorTextNormal(sf::Color::White);

   Button exit;
   exit.setText("QUIT");
   exit.setPosition({640, 125});
   exit.setSize({200, 71});
   exit.setColor(sf::Color::Black);
   exit.setColorTextHover(sf::Color::White);
   exit.setColorTextNormal(sf::Color::White);

   int mainChoice;
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
               mainChoice++;
               if(mainChoice>2)
                  mainChoice = 2;   
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
               mainChoice--;
               if(mainChoice<0)
                  mainChoice = 0;
            }    
                     

         start.updateStart(event, window, mainChoice);
         exit.updateExit(event, window, mainChoice);
         window.draw(rect);

            window.draw(start);
            window.draw(exit);

         //window.display();
        
      }
   }
}