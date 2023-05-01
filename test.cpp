#include "entity.h"

int main(){
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1280,720),"Test");
    Player party2;
    Player *party[4];
    Paladin myPaladin;
    WhiteMage myWhiteMage;
    BlackMage myBlackMage;
    Fighter myFighter;
    party[0]=&myPaladin;
    party[1]=&myWhiteMage;
    party[2]=&myBlackMage;
    party[3]=&myFighter;
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