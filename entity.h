#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

using std::string;

class Entity{
public:
    Entity();
    void attack(Entity &target)const;
    void setHP(int hp){HP==hp;}
    int getHP ()const{return HP;}
    void setMP(int mp){MP==mp;}
    int getMP()const{return MP;}
    void setSP(int skillp)const{SP==skillp;}
    int getSP()const{return SP;}
    void setphysAtk(int pa){physAtk==pa;}
    int getphysAtk()const{return physAtk;}
    void setphysDef(int pd){physDef==pd;}
    int getphysDef()const{return physDef;}
    void setmgcAtk(int ma){mgcAtk==ma;}
    int getmgcAtk()const{return mgcAtk;}
    void setmgcDef(int md){mgcDef==md;}
    int getmgcDef()const{return mgcDef;}


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
    Paladin():Player(){}
    void smite(Entity &target)const;
private:
};

class WhiteMage :public Player{
public:
    WhiteMage():Player(){}
    void cure(Entity &target)const;
private:
};

class BlackMage :public Player{
public:
    BlackMage():Player(){}
    void fire(Entity &target)const;
private:
};

class Fighter :public Player{
public:
    Fighter():Player(){}
    void rush(Entity &target)const;
private:
};

class Enemy :public Entity{
public:
private:
};

#endif