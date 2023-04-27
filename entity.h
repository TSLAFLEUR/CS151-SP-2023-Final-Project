#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>

using std::string;

class Entity{
public:
    Entity();
    void attack(Entity &target)const;
    void setType(char t){type=t;}
    int getType(){return type;}
    void setHP(int hp){HP=hp;}
    int getHP()const{return HP;}
    void setMP(int mp){MP=mp;}
    int getMP()const{return MP;}
    void setSP(int sp){SP=sp;}
    int getSP()const{return SP;}
    void setphysAtk(int pa){physAtk=pa;}
    int getphysAtk()const{return physAtk;}
    void setphysDef(int pd){physDef=pd;}
    int getphysDef()const{return physDef;}
    void setmgcAtk(int ma){mgcAtk=ma;}
    int getmgcAtk()const{return mgcAtk;}
    void setmgcDef(int md){mgcDef=md;}
    int getmgcDef()const{return mgcDef;}
    void setspeed(int s){speed=s;}
    int getspeed()const{return speed;}
private:
    string name;
    char type;//p=physical, m=magic
    int HP;//health points
    int MP;//magic points
    int SP;//skill points
    int physAtk;//physical attack
    int physDef;//physical defense
    int mgcAtk;//magic attack
    int mgcDef;//magic defense
    int speed;
};

class Player :public Entity{
public: 
private:
};

class Paladin :public Player{
public:
    Paladin():Player(){setType('p');}
    void smite(Entity &target);
private:
};

class WhiteMage :public Player{
public:
    WhiteMage():Player(){
        setType('w');
        setMP(10);
    }
    void cure(Entity &target)const;
private:
};

class BlackMage :public Player{
public:
    BlackMage():Player(){
        setType('b');
        setMP(10);
    }
    void fire(Entity &target)const;
private:
};

class Fighter :public Player{
public:
    Fighter():Player(){setType('f');}
    void rush(Entity &target)const;
private:
};

class Enemy :public Entity{
public:
private:
};

void displayCombat(const Paladin &myPaladin,const WhiteMage &myWhiteMage,const BlackMage &myBlackMage, const Fighter &myFighter,sf::RenderWindow &window,sf::Font &font);
void combat(const Paladin p,const WhiteMage w,const BlackMage b, const Fighter f,sf::RenderWindow &window,sf::Font &font, int encounter=0);
void initiative(const Paladin p,const WhiteMage w,const BlackMage b, const Fighter f, int encounter,std::queue<int> &q);
#endif