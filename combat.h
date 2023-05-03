#ifndef COMBAT_H
#define COMBAT_H

#include "entity.h"
#include <unistd.h>

void potion(Entity &a);
void displayAction(string s,sf::RenderWindow &window,sf::Font &font);
bool fight(sf::Font &font,Entity p,sf::RenderWindow &window,Enemy &e);
bool skillMagic(sf::Font &font,Entity a,Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f,sf::RenderWindow &window,Entity &e);
bool items(sf::Font &font,Entity a,Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f,sf::RenderWindow &window);
bool run(bool &Run);
void displayCombat(const Paladin &myPaladin,const WhiteMage &myWhiteMage,const BlackMage &myBlackMage, const Fighter &myFighter,sf::RenderWindow &window,sf::Font &font);
void displayEnemy(Enemy enemy,sf::RenderWindow &window,sf::Font &font);
bool combatChoice(sf::Font &font,Entity a,Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f,sf::RenderWindow &window, Enemy &e,bool &Run);
void combatEnemyAction(Entity &p,Enemy &e);
bool combatPartyActive(Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f);
bool combatEnemyActive(Enemy &e);
int combat(Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f, sf::RenderWindow &window, sf::Font &font, int encounter);
void gameOver(sf::RenderWindow &window, sf::Font &font);

#endif