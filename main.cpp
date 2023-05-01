#include "entity.h"
#include "combat.h"

int main(){
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1280,720),"Test");
    Paladin myPaladin;
    WhiteMage myWhiteMage;
    BlackMage myBlackMage;
    Fighter myFighter;
    sf::Font font;
    if(!font.loadFromFile("Final-Fantasy.ttf")){
    }
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        combat(myPaladin,myWhiteMage,myBlackMage,myFighter,window,font,1);
    }
    return 0;
}