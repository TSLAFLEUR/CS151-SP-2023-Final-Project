/**
 * @file entity.cpp
 * @author Tyler LaFleur
 * @brief This file contains all function definitions for entity, player, enemy, and job classes
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "entity.h"

//Entity
Entity::Entity(){
    name = "null";
    type='p';//p=physical, m=magic
    HP=rand()%10+rand()%10;
    MP=rand()%10+rand()%10;
    SP=rand()%10+rand()%10;
    physAtk=rand()%10+rand()%10;
    physDef=rand()%10+rand()%10;
    mgcAtk=rand()%10+rand()%10;
    mgcDef=rand()%10+rand()%10;
    speed=rand()%10+rand()%10;
    defeated=false;
}

/**
 * @brief This function attacks the chosen target using physical attack against physical defense
 * 
 * @param target 
 */
void Entity::attack(Entity &target){
    int damage=(this->getphysAtk()-(target.getphysDef()/2));
    if(damage<=0){
        damage=1;
    }
    target.setHP(target.getHP()-damage);
    target.checkDefeated();
}

//Player
Paladin::Paladin():Player(){
    setType('p');
    setmaxHP(10+rand()%10+rand()%10+rand()%10);
    setmaxSP(8+rand()%8+rand()%8+rand()%8);
    setmaxMP(0);
    setmaxphysAtk(8+rand()%8+rand()%8+rand()%8);
    setmaxphysDef(10+rand()%10+rand()%10+rand()%10);
    setmaxmgcAtk(6+rand()%6+rand()%6+rand()%6);
    setmaxmgcDef(8+rand()%8+rand()%8+rand()%8);
    setmaxspeed(6+rand()%6+rand()%6+rand()%6);
}

/**
 * @brief deal physical and magical damage to enemy
 * 
 * @param target 
 * @return true 
 * @return false 
 */
bool Paladin::smite(Entity &target){
    int damage=((getmgcAtk()+getphysAtk())-(target.getmgcDef()/2));
    if(damage<=0){
        damage=1;
    }
    if(getSP()>=5){ 
        target.setHP(target.getHP()-damage);
        if(target.getHP()<0){
            target.checkDefeated();
            target.setHP(0);
        }
        setSP(getSP()-5);  
        return true;
    }
    return false;
}

//White Mage
WhiteMage::WhiteMage():Player(){
    setType('w');
    setmaxHP(8+rand()%8+rand()%8+rand()%8);
    setmaxSP(0);
    setmaxMP(10+rand()%10+rand()%10+rand()%10);
    setmaxphysAtk(6+rand()%6+rand()%6+rand()%6);
    setmaxphysDef(6+rand()%6+rand()%6+rand()%6);
    setmaxmgcAtk(10+rand()%10+rand()%10+rand()%10);
    setmaxmgcDef(8+rand()%8+rand()%8+rand()%8);
    setmaxspeed(10+rand()%10+rand()%10+rand()%10);
}

/**
 * @brief Heal party member equal to magic attack
 * 
 * @param target 
 * @return true 
 * @return false 
 */
bool WhiteMage::cure(Entity &target){
    if(getMP()>=5){
        target.setHP(target.getHP()+getmgcAtk());
        if(target.getmaxHP()<target.getHP()){
            target.checkDefeated();
            target.setHP(target.getmaxHP());
        }
        setMP(getMP()-5);
        return true;
    }
    return false;
}

//Black Mage
BlackMage::BlackMage():Player(){
    setType('b');
    setmaxHP(6+rand()%6+rand()%6+rand()%6);
    setmaxSP(0);
    setmaxMP(10+rand()%10+rand()%10+rand()%10);
    setmaxphysAtk(6+rand()%6+rand()%6+rand()%6);
    setmaxphysDef(6+rand()%6+rand()%6+rand()%6);
    setmaxmgcAtk(10+rand()%10+rand()%10+rand()%10);
    setmaxmgcDef(8+rand()%8+rand()%8+rand()%8);
    setmaxspeed(8+rand()%8+rand()%8+rand()%8);
}

/**
 * @brief deal magical damage against enemy
 * 
 * @param target 
 * @return true 
 * @return false 
 */
bool BlackMage::fire(Entity &target){
    int damage=(this->getmgcAtk()*2-(target.getmgcDef()/2));
    if(damage<=0){
        damage=1;
    }
    if(getMP()>=5){
        target.setHP(target.getHP()-damage);
        if(target.getHP()<0){
            target.checkDefeated();
            target.setHP(0);
        }
        setMP(getMP()-5);
        return true;
    }
    return false;
}

//Fighter
Fighter::Fighter():Player(){
    setType('f');
    setmaxHP(8+rand()%8+rand()%8+rand()%8);
    setmaxSP(10+rand()%10+rand()%10+rand()%10);
    setmaxMP(0);
    setmaxphysAtk(10+rand()%10+rand()%10+rand()%10);
    setmaxphysDef(8+rand()%8+rand()%8+rand()%8);
    setmaxmgcAtk(6+rand()%6+rand()%6+rand()%6);
    setmaxmgcDef(6+rand()%6+rand()%6+rand()%6);
    setmaxspeed(8+rand()%8+rand()%8+rand()%8);
}

/**
 * @brief Deal physical damage to enemy
 * 
 * @param target 
 * @return true 
 * @return false 
 */
bool Fighter::slash(Entity &target){
    int damage=(this->getphysAtk()*2-(target.getphysDef()/2));
    if(damage<=0){
        damage=1;
    }
    if(getSP()>=5){
        target.setHP(target.getHP()-damage);
        if(target.getHP()<0){
            target.checkDefeated();
            target.setHP(0);
        }
        setSP(getSP()-5);
        return true;
    }
    return false;
}

//Enemy
Enemy::Enemy():Entity(){
    setType('e');
    setmaxHP(12+rand()%12+rand()%12+rand()%12);
    setmaxSP(12+rand()%12+rand()%12+rand()%12);
    setmaxMP(12+rand()%12+rand()%12+rand()%12);
    setmaxphysAtk(12+rand()%12+rand()%12+rand()%12);
    setmaxphysDef(12+rand()%12+rand()%12+rand()%12);
    setmaxmgcAtk(12+rand()%12+rand()%12+rand()%12);
    setmaxmgcDef(12+rand()%12+rand()%12+rand()%12);
    setmaxspeed(12+rand()%12+rand()%12+rand()%12);
}

