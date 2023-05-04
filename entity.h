/**
 * @file entity.h
 * @author Tyler LaFleur
 * @brief This file contains all function prototypes for entity, player, enemy, and job classes
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

using std::string;

/**
 * @brief Generic class for any being in game
 * 
 */
class Entity{
public:
    Entity();
    virtual void attack(Entity &target);
    void setType(char t){type=t;}
    const char getType(){return type;}
    bool isDefeated(){return defeated;}
    void checkDefeated(){if(HP<=0){defeated=true;setHP(0);}}

    void setmaxHP(int hp){maxHP=hp;HP=hp;}
    int getmaxHP()const{return maxHP;}
    void setmaxMP(int mp){maxMP=mp;MP=mp;}
    int getmaxMP()const{return maxMP;}
    void setmaxSP(int sp){maxSP=sp;SP=sp;}
    int getmaxSP()const{return maxSP;}
    void setmaxphysAtk(int pa){maxphysAtk=pa;physAtk=pa;}
    int getmaxphysAtk()const{return maxphysAtk;}
    void setmaxphysDef(int pd){maxphysDef=pd;physDef=pd;}
    int getmaxphysDef()const{return maxphysDef;}
    void setmaxmgcAtk(int ma){maxmgcAtk=ma;mgcAtk=ma;}
    int getmaxmgcAtk()const{return maxmgcAtk;}
    void setmaxmgcDef(int md){maxmgcDef=md;mgcDef=md;}
    int getmaxmgcDef()const{return maxmgcDef;}
    void setmaxspeed(int s){maxspeed=s;speed=s;}
    int getmaxspeed()const{return maxspeed;}

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
    bool defeated=false;
    
    int maxHP;//health points
    int maxMP;//magic points
    int maxSP;//skill points
    int maxphysAtk;//physical attack
    int maxphysDef;//physical defense
    int maxmgcAtk;//magic attack
    int maxmgcDef;//magic defense
    int maxspeed;
    
    int HP;//health points
    int MP;//magic points
    int SP;//skill points
    int physAtk;//physical attack
    int physDef;//physical defense
    int mgcAtk;//magic attack
    int mgcDef;//magic defense
    int speed;
};

/**
 * @brief Generic class for a player
 * 
 */
class Player :public Entity{
public: 
private:
};

/**
 * @brief Paladin job, tank
 * 
 */
class Paladin :public Player{
public:
    Paladin();
    bool smite(Entity &target);
private:
};

/**
 * @brief White mage job, healer
 * 
 */
class WhiteMage :public Player{
public:
    WhiteMage();
    bool cure(Entity &target);
private:
};

/**
 * @brief Black mage job, magic dps
 * 
 */
class BlackMage :public Player{
public:
    BlackMage();
    bool fire(Entity &target);
private:
};

/**
 * @brief Fighter job, physical dps
 * 
 */
class Fighter :public Player{
public:
    Fighter();
    bool slash(Entity &target);
private:
};

class Enemy :public Entity{
public:
    Enemy();
private:
};

#endif