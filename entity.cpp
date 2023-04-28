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
    target.setHP(target.getHP()-this->getphysAtk());//(this->getphysAtk()-target.getphysDef()));
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
}

//Combat
void initiative(const Paladin p,const WhiteMage w,const BlackMage b, const Fighter f,const Enemy &e, int encounter,std::queue<Entity> &q){
    q.push(f);
    q.push(b);
    q.push(p);
    q.push(w);
}

void fight(){

}

void skillMagic(){

}

void items(){

}

void run(){

}

void displayCombat(const Paladin &myPaladin,const WhiteMage &myWhiteMage,const BlackMage &myBlackMage, const Fighter &myFighter,sf::RenderWindow &window,sf::Font &font){
    sf::RectangleShape border(sf::Vector2f(window.getSize().x/5,window.getSize().y/5-10));
    border.setFillColor(sf::Color::Black);
    border.setOutlineColor(sf::Color::White);
    border.setOutlineThickness(2);
    border.setPosition(4*window.getSize().x/5-10,window.getSize().y/5-10);//draw pal border
    window.draw(border);
    border.setPosition(4*window.getSize().x/5-10,2*window.getSize().y/5-10);//draw whm border
    window.draw(border);
    border.setPosition(4*window.getSize().x/5-10,3*window.getSize().y/5-10);//draw blm border
    window.draw(border);
    border.setPosition(4*window.getSize().x/5-10,4*window.getSize().y/5-10);//draw fighter border
    window.draw(border);
    border.setSize(sf::Vector2f(window.getSize().x/4+10,window.getSize().y/5+30));//draw friendly action border
    border.setPosition(window.getSize().x/2-10,3*window.getSize().y/4-10);
    window.draw(border);
    border.setSize(sf::Vector2f(window.getSize().x/4+10,3.5*window.getSize().y/5));//draw friendly border
    border.setPosition(window.getSize().x/2-10,10);
    window.draw(border);
    border.setSize(sf::Vector2f(window.getSize().x/2-20,window.getSize().y/5+30));//draw enemy text border
    border.setPosition(10,3*window.getSize().y/4-10);
    window.draw(border);
    border.setSize(sf::Vector2f(window.getSize().x/2-20,3.5*window.getSize().y/5));//draw enemy border
    border.setPosition(10,10);
    window.draw(border);
    sf::Text pal;
    sf::Text whm;
    sf::Text blm;
    sf::Text fht;
    pal.setFont(font);
    whm.setFont(font);
    blm.setFont(font);
    fht.setFont(font);
    pal.setString("Paladin"); 
    whm.setString("White Mage");
    blm.setString("Black Mage");
    fht.setString("Fighter");
    pal.setPosition(4*window.getSize().x/5,window.getSize().y/5);
    whm.setPosition(4*window.getSize().x/5,2*window.getSize().y/5);
    blm.setPosition(4*window.getSize().x/5,3*window.getSize().y/5);
    fht.setPosition(4*window.getSize().x/5,4*window.getSize().y/5);
    window.draw(pal);
    window.draw(whm);
    window.draw(blm);
    window.draw(fht);
    sf::Text palHP;
    sf::Text whmHP;
    sf::Text blmHP;
    sf::Text fhtHP;
    palHP.setFont(font);
    whmHP.setFont(font);
    blmHP.setFont(font);
    fhtHP.setFont(font);
    palHP.setString("HP  "+std::to_string(myPaladin.getHP()));
    whmHP.setString("HP  "+std::to_string(myWhiteMage.getHP()));
    blmHP.setString("HP  "+std::to_string(myBlackMage.getHP()));
    fhtHP.setString("HP  "+std::to_string(myFighter.getHP()));
    palHP.setPosition(4*window.getSize().x/5,40+window.getSize().y/5);
    whmHP.setPosition(4*window.getSize().x/5,40+2*window.getSize().y/5);
    blmHP.setPosition(4*window.getSize().x/5,40+3*window.getSize().y/5);
    fhtHP.setPosition(4*window.getSize().x/5,40+4*window.getSize().y/5);
    window.draw(palHP);
    window.draw(whmHP);
    window.draw(blmHP);
    window.draw(fhtHP);
    sf::Text palSP;
    sf::Text whmMP;
    sf::Text blmMP;
    sf::Text fhtSP;
    palSP.setFont(font);
    whmMP.setFont(font);
    blmMP.setFont(font);
    fhtSP.setFont(font);
    palSP.setString("SP  "+std::to_string(myPaladin.getSP()));
    whmMP.setString("MP  "+std::to_string(myWhiteMage.getMP()));
    blmMP.setString("MP  "+std::to_string(myBlackMage.getMP()));
    fhtSP.setString("SP  "+std::to_string(myFighter.getSP()));
    palSP.setPosition(4*window.getSize().x/5,80+window.getSize().y/5);
    whmMP.setPosition(4*window.getSize().x/5,80+2*window.getSize().y/5);
    blmMP.setPosition(4*window.getSize().x/5,80+3*window.getSize().y/5);
    fhtSP.setPosition(4*window.getSize().x/5,80+4*window.getSize().y/5);
    window.draw(palSP);
    window.draw(whmMP);
    window.draw(blmMP);
    window.draw(fhtSP);
    sf::Text fight;
    sf::Text sm;
    sf::Text items;
    sf::Text run;
    fight.setFont(font);
    sm.setFont(font);
    items.setFont(font);
    run.setFont(font);
    fight.setString("FIGHT");
    sm.setString("SKILLS MAGIC");
    items.setString("ITEMS");
    run.setString("RUN");
    fight.setPosition(window.getSize().x/2,3*window.getSize().y/4);
    sm.setPosition(window.getSize().x/2,40+3*window.getSize().y/4);
    items.setPosition(window.getSize().x/2,80+3*window.getSize().y/4);
    run.setPosition(window.getSize().x/2,120+3*window.getSize().y/4);
    window.draw(fight);
    window.draw(sm);
    window.draw(items);
    window.draw(run);
    window.display();
}

bool combatChoice(sf::Font &font,Entity p,sf::RenderWindow &window, const Enemy &e){
    sf::RectangleShape clearActive(sf::Vector2f(30,4*window.getSize().y/5));
    clearActive.setFillColor(sf::Color::Black);
    clearActive.setPosition(4*window.getSize().x/5-50,window.getSize().y/5);
    window.draw(clearActive);
    sf::Text active;
    active.setFont(font);
    active.setString('>');
    if(p.getType()=='p'){
        active.setPosition(4*window.getSize().x/5-50,window.getSize().y/5);
    }else if(p.getType()=='w'){
        active.setPosition(4*window.getSize().x/5-50,2*window.getSize().y/5);
    }else if(p.getType()=='b'){
        active.setPosition(4*window.getSize().x/5-50,3*window.getSize().y/5);
    }else if(p.getType()=='f'){
        active.setPosition(4*window.getSize().x/5-50,4*window.getSize().y/5);
    }
    window.draw(active);
    sf::Event event;
    int choice=1;
    int i=1;
    int height=0;
    sf::RectangleShape clearSelection(sf::Vector2f(30,160));
    clearSelection.setFillColor(sf::Color::Black);
    clearSelection.setPosition(window.getSize().x/2-50,height+3*window.getSize().y/4);
    sf::Text selection;
    selection.setFont(font);
    selection.setString('>');
    selection.setPosition(window.getSize().x/2-50,height+3*window.getSize().y/4);
    window.draw(selection);
    window.display();
    while(i!=0){
        i=1;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Down){
                    if(height<120){
                        height+=40;
                        choice++;
                    }
                }
                if(event.key.code==sf::Keyboard::Up){
                    if(height>0){
                        height-=40;
                        choice--;
                    }
                }
                if(event.key.code==sf::Keyboard::Enter){
                    if(choice==1){//fight
                        fight();
                        i=0;
                    }else if(choice==2){//skills
                        skillMagic();
                        i=0;
                    }else if(choice==3){//items
                        items();
                        i=0;
                    }else if(choice==4){//run
                        run();
                        i=0;
                    }
                }
                selection.setPosition(window.getSize().x/2-50,height+3*window.getSize().y/4);
                window.draw(clearSelection);
                window.draw(selection);
                window.display();
            }     
        }
    }
    return false;
}

void combatEnemyAction(Entity &p,Enemy &e){
    e.attack(p);
}

bool combatActive(const Paladin &p,const WhiteMage &w,const BlackMage &b, const Fighter &f){
    return true;
}

void combat(Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f, sf::RenderWindow &window, sf::Font &font, int encounter){
    std::queue<Entity> init;
    Enemy enemy[1];
    //initiative(p,w,b,f,enemy[0],encounter,init);//determine initiative
    init.push(f);
    init.push(b);
    init.push(p);
    init.push(w);
    init.push(enemy[0]);
    displayCombat(p,w,b,f,window,font);
    while(combatActive(p,w,b,f))
    {
        if(init.front().getType()=='p'){//if paladin's turn
            while(combatChoice(font,p,window,*enemy)){}
        } else if(init.front().getType()=='w'){//if white mage's turn
            while(combatChoice(font,w,window,*enemy)){}
        } else if(init.front().getType()=='b'){//if black mage's turn
            while(combatChoice(font,b,window,*enemy)){}
        } else if(init.front().getType()=='f'){//if fighter's turn
            while(combatChoice(font,f,window,*enemy)){}
        } else if(init.front().getType()=='e'){
            std::cout<<"Enemy turn"<<std::endl;
            switch(rand()%4){
                case(0):
                    combatEnemyAction(p,enemy[0]);
                    break;
                case(1):
                    combatEnemyAction(w,enemy[0]);
                    break;
                case(2):
                    combatEnemyAction(b,enemy[0]);
                    break;
                case(3):
                    combatEnemyAction(f,enemy[0]);
                    break;
                default:
                    break;
            }
        }
        init.push(init.front());//put front of queue to back
        init.pop();//remove current turn from front
        displayCombat(p,w,b,f,window,font);
    }
}

