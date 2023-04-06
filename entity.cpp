#include "entity.h"

//Entity
Entity::Entity(){
    name = "null";
    type='p';//p=physical, m=magic
    HP=10;
    MP=0;
    SP=10;
    physAtk=10;
    physDef=5;
    mgcAtk=10;
    mgcDef=5;
    speed=10;
}

void Entity::attack(Entity &target)const{
    target.setHP(target.getHP()-(this->getphysAtk()-target.getphysDef()));
}

//Player

//Paladin
void Paladin::smite(Entity &target)const{
    if(Entity::getSP()>5){ 
        Entity::setSP(Entity::getSP()-5);  
        target.setHP(((Entity::getmgcAtk())*2)-target.getmgcDef());
    }
}
//White Mage

//Black Mage

//Fighter

//Enemy