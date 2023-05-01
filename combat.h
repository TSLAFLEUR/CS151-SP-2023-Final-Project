#ifndef COMBAT_H
#define COMBAT_H

#include "entity.h"

bool fight(sf::Font &font,Entity p,sf::RenderWindow &window,Enemy &e);
bool skillMagic(sf::Font &font,Entity p,sf::RenderWindow &window,Entity &e);
bool items();
bool run();
void displayCombat(const Paladin &myPaladin,const WhiteMage &myWhiteMage,const BlackMage &myBlackMage, const Fighter &myFighter,sf::RenderWindow &window,sf::Font &font);
void displayEnemy(Enemy enemy,sf::RenderWindow &window,sf::Font &font);
bool combatChoice(sf::Font &font,Entity p,sf::RenderWindow &window, Enemy &e);
void combatEnemyAction(Entity &p,Enemy &e);
bool combatPartyActive(Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f);
bool combatEnemyActive(Enemy &e);
int combat(Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f, sf::RenderWindow &window, sf::Font &font, int encounter);

#endif