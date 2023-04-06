#include "entity.h"
using std::cout;
using std::endl;

int main(){
    Player *party[4];
    Paladin myPaladin;
    WhiteMage myWhiteMage;
    BlackMage myBlackMage;
    Fighter myFighter;
    party[0]=&myPaladin;
    party[1]=&myWhiteMage;
    party[2]=&myBlackMage;
    party[3]=&myFighter;
    Enemy combat[2];
    cout<<combat[0].getHP()<<endl;
    party[0]->attack(combat[0]);
    cout<<combat[0].getHP()<<endl;
    cout<<combat[1].getHP()<<endl;
    cout<<party[0]->getphysAtk()<<endl;
    static_cast<Paladin*>(party[0])->smite(combat[1]);
    cout<<combat[1].getHP()<<endl;
}