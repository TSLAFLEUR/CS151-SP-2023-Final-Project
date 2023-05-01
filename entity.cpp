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

void Entity::attack(Entity &target){
    int damage=(this->getphysAtk()-(target.getphysDef()/2));
    if(damage<=0){
        damage=1;
    }
    target.setHP(target.getHP()-damage);
    std::cout<<target.HP<<std::endl;
    target.checkDefeated();
}

//Player
Paladin::Paladin():Player(){
    setType('p');
    setmaxHP(rand()%10+rand()%10+rand()%10+rand()%10);
    setmaxSP(rand()%8+rand()%8+rand()%8+rand()%8);
    setmaxMP(0);
    setmaxphysAtk(rand()%8+rand()%8+rand()%8+rand()%8);
    setmaxphysDef(rand()%10+rand()%10+rand()%10+rand()%10);
    setmaxmgcAtk(rand()%6+rand()%6+rand()%6+rand()%6);
    setmaxmgcDef(rand()%8+rand()%8+rand()%8+rand()%8);
    setmaxspeed(rand()%6+rand()%6+rand()%6+rand()%6);
}

void Paladin::smite(Entity &target){
    if(Entity::getSP()>5){ 
        Entity::setSP(Entity::getSP()-5);  
        target.setHP(target.getHP()-(((Entity::getmgcAtk())*2)-target.getmgcDef()));
    }
}
//White Mage
WhiteMage::WhiteMage():Player(){
    setType('w');
    setmaxHP(rand()%8+rand()%8+rand()%8+rand()%8);
    setmaxSP(0);
    setmaxMP(rand()%10+rand()%10+rand()%10+rand()%10);
    setmaxphysAtk(rand()%6+rand()%6+rand()%6+rand()%6);
    setmaxphysDef(rand()%6+rand()%6+rand()%6+rand()%6);
    setmaxmgcAtk(rand()%10+rand()%10+rand()%10+rand()%10);
    setmaxmgcDef(rand()%8+rand()%8+rand()%8+rand()%8);
    setmaxspeed(rand()%10+rand()%10+rand()%10+rand()%10);
}
//Black Mage
BlackMage::BlackMage():Player(){
    setType('b');
    setmaxHP(rand()%6+rand()%6+rand()%6+rand()%6);
    setmaxSP(0);
    setmaxMP(rand()%10+rand()%10+rand()%10+rand()%10);
    setmaxphysAtk(rand()%6+rand()%6+rand()%6+rand()%6);
    setmaxphysDef(rand()%6+rand()%6+rand()%6+rand()%6);
    setmaxmgcAtk(rand()%10+rand()%10+rand()%10+rand()%10);
    setmaxmgcDef(rand()%8+rand()%8+rand()%8+rand()%8);
    setmaxspeed(rand()%8+rand()%8+rand()%8+rand()%8);
}
//Fighter
Fighter::Fighter():Player(){
    setType('f');
    setmaxHP(rand()%8+rand()%8+rand()%8+rand()%8);
    setmaxSP(rand()%10+rand()%10+rand()%10+rand()%10);
    setmaxMP(0);
    setmaxphysAtk(rand()%10+rand()%10+rand()%10+rand()%10);
    setmaxphysDef(rand()%8+rand()%8+rand()%8+rand()%8);
    setmaxmgcAtk(rand()%6+rand()%6+rand()%6+rand()%6);
    setmaxmgcDef(rand()%6+rand()%6+rand()%6+rand()%6);
    setmaxspeed(rand()%8+rand()%8+rand()%8+rand()%8);
}
//Enemy
Enemy::Enemy():Entity(){
    setType('e');
    setmaxHP(rand()%12+rand()%12+rand()%12+rand()%12);
    setmaxSP(rand()%12+rand()%12+rand()%12+rand()%12);
    setmaxMP(rand()%12+rand()%12+rand()%12+rand()%12);
    setmaxphysAtk(rand()%12+rand()%12+rand()%12+rand()%12);
    setmaxphysDef(rand()%12+rand()%12+rand()%12+rand()%12);
    setmaxmgcAtk(rand()%12+rand()%12+rand()%12+rand()%12);
    setmaxmgcDef(rand()%12+rand()%12+rand()%12+rand()%12);
    setmaxspeed(rand()%12+rand()%12+rand()%12+rand()%12);
}

