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
// Paladin::Paladin():Player(){
//     setHP(50);
//     setSP(25);
//     setphysAtk(25);
//     setphysDef(20);
//     setmgcAtk(25);
//     setmgcDef(10);
// }
void Paladin::smite(Entity &target){
    if(Entity::getSP()>5){ 
        Entity::setSP(Entity::getSP()-5);  
        target.setHP(target.getHP()-(((Entity::getmgcAtk())*2)-target.getmgcDef()));
    }
}
//White Mage

//Black Mage

//Fighter

//Enemy

//Combat
void initiative(const Paladin p,const WhiteMage w,const BlackMage b, const Fighter f, int encounter,std::queue<Entity> &q){
    q.push(f);
    q.push(b);
    q.push(p);
    q.push(w);
    if(encounter==1){
        Enemy e;
        q.push(e);
    }
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

bool combatChoice(sf::Font &font,Entity p,sf::RenderWindow &window, Enemy &e){
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
                        std::cout<<"fight"<<std::endl;
                        i=0;
                    }else if(choice==2){//skills
                        std::cout<<"skills"<<std::endl;
                        i=0;
                    }else if(choice==3){//items
                        std::cout<<"items"<<std::endl;
                        i=0;
                    }else if(choice==4){//run
                        std::cout<<"run"<<std::endl;
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

void combatEnemyAction(){

}

void combat(const Paladin p,const WhiteMage w,const BlackMage b, const Fighter f, sf::RenderWindow &window, sf::Font &font ,int encounter){
    std::queue<Entity> init;
    initiative(p,w,b,f,encounter,init);//determine initiative
    bool combat=true;
    bool waitForInstruct=true;
    Enemy enemy[5];
    init.push(enemy[0]);
    displayCombat(p,w,b,f,window,font);
    while(combat)
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
            combatEnemyAction();
        }
        init.push(init.front());//put front of queue to back
        init.pop();//remove current turn from front
        displayCombat(p,w,b,f,window,font);
    }
}

