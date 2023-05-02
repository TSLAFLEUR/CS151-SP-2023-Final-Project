#include "combat.h"

bool fight(sf::Font &font,Entity p,sf::RenderWindow &window,Enemy &e){//done
    sf::Event event;
    int choice=1;
    int i=1;
    int height=0;
    sf::RectangleShape clearSelection(sf::Vector2f(30,160));
    clearSelection.setFillColor(sf::Color::Black);
    clearSelection.setPosition(20,height+3*window.getSize().y/4);
    sf::Text selection;
    selection.setFont(font);
    selection.setString('>');
    selection.setPosition(20,3*window.getSize().y/4);
    window.draw(selection);
    window.display();
    while(i!=0){
        i=1;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Enter){
                    if(choice==1){//fight
                        p.attack(e);
                        return true;
                    }
                }
                if(event.key.code==sf::Keyboard::Escape){
                    window.draw(clearSelection);
                    window.display();
                    return false;
                }
            selection.setPosition(window.getSize().x/2-50,height+3*window.getSize().y/4);
            window.draw(clearSelection);
            window.draw(selection);
            window.display();
            }     
        }
    }
    return true;
}

bool skillMagic(sf::Font &font,Entity p,sf::RenderWindow &window,Entity &e){
    sf::Event event;
    int choice=1;
    int i=1;
    int height=0;
    sf::RectangleShape clearSelection(sf::Vector2f(30,160));
    clearSelection.setFillColor(sf::Color::Black);
    clearSelection.setPosition(20,height+3*window.getSize().y/4);
    sf::Text selection;
    selection.setFont(font);
    selection.setString('>');
    selection.setPosition(20,3*window.getSize().y/4);
    window.draw(selection);
    window.display();
    while(i!=0){
        i=1;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Enter){
                    if(choice==1){//fight
                        p.attack(e);
                        return true;
                    }
                }
                if(event.key.code==sf::Keyboard::Escape){
                    return false;
                }
            selection.setPosition(window.getSize().x/2-50,height+3*window.getSize().y/4);
            window.draw(clearSelection);
            window.draw(selection);
            window.display();
            }     
        }
    }
    return true;
}

bool items(){
    return true;
}

bool run(){
    return true;
}

void displayCombat(const Paladin &myPaladin,const WhiteMage &myWhiteMage,const BlackMage &myBlackMage, const Fighter &myFighter,sf::RenderWindow &window,sf::Font &font){
    sf::RectangleShape combat(sf::Vector2f(window.getSize().x,window.getSize().y));
    combat.setFillColor(sf::Color::Black);
    window.draw(combat);
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

void displayEnemy(Enemy enemy,sf::RenderWindow &window,sf::Font &font){
    sf::Text en;
    en.setFont(font);
    en.setString("Enemy1"); 
    en.setPosition(50,3*window.getSize().y/4);
    window.draw(en);
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
    bool madeCombatDecision=false;
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
    while(!madeCombatDecision){
        madeCombatDecision=false;
        while(window.pollEvent(event)){
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
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
                        madeCombatDecision=fight(font,p,window,e);
                    }else if(choice==2){//skills
                        madeCombatDecision=skillMagic(font,p,window,e);
                    }else if(choice==3){//items
                        madeCombatDecision=items();
                    }else if(choice==4){//run
                        madeCombatDecision=run();
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

bool combatPartyActive(Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f){
    if(p.isDefeated()&&w.isDefeated()&&b.isDefeated()&&f.isDefeated()){
        std::cout<<"party defeated."<<std::endl;
        return false;
    }
    return true;
}

bool combatEnemyActive(Enemy &e){
    if(e.isDefeated()){
        std::cout<<"enemy defeated."<<std::endl;
        return false;
    }
    return true;
}

int combat(Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f, sf::RenderWindow &window, sf::Font &font, int encounter){
    std::queue<Entity> init;
    Enemy enemy[1];
    bool validTarget;
    init.push(f);
    init.push(b);
    init.push(p);
    init.push(w);
    init.push(enemy[0]);
    displayCombat(p,w,b,f,window,font);
    displayEnemy(enemy[0],window,font);
    while(combatPartyActive(p,w,b,f)&&combatEnemyActive(enemy[0]))
    {
        if(init.front().getType()=='p'){//if paladin's turn
            if(!p.isDefeated()){
                while(combatChoice(font,p,window,*enemy)){}
                init.push(init.front());
            }
            init.pop();
        } else if(init.front().getType()=='w'){//if white mage's turn
            if(!w.isDefeated()){
                while(combatChoice(font,w,window,*enemy)){}
                init.push(init.front());
            }
            init.pop();
        } else if(init.front().getType()=='b'){//if black mage's turn
            if(!b.isDefeated()){
                while(combatChoice(font,b,window,*enemy)){}
                init.push(init.front());
            }
            init.pop();
        } else if(init.front().getType()=='f'){//if fighter's turn
            if(!f.isDefeated()){
                while(combatChoice(font,f,window,*enemy)){}
                init.push(init.front());
            }
            init.pop();
        } else if(init.front().getType()=='e'){
            validTarget=false;
            while(!validTarget){
                switch(rand()%4){
                    case(0):
                        if(!p.isDefeated()){
                            combatEnemyAction(p,enemy[0]);
                            validTarget=true;
                        }
                        break;
                    case(1):
                        if(!w.isDefeated()){
                            combatEnemyAction(w,enemy[0]);
                            validTarget=true;
                        }
                        break;
                    case(2):
                        if(!b.isDefeated()){
                            combatEnemyAction(b,enemy[0]);
                            validTarget=true;
                        }
                        break;
                    case(3):
                        if(!f.isDefeated()){
                            combatEnemyAction(f,enemy[0]);
                            validTarget=true;
                        }
                        break;
                    default:
                        break;
                }
                if(!combatPartyActive(p,w,b,f)){
                    break;
                }
            init.push(init.front());//put front of queue to back
            init.pop();//remove current turn from front
            }
        }
        displayCombat(p,w,b,f,window,font);
        displayEnemy(enemy[0],window,font);
    }
    if(!combatEnemyActive(enemy[0])){
        std::cout<<"Victory"<<std::endl;
        return 1;
    }
    if(!combatPartyActive(p,w,b,f)){
        std::cout<<"Defeat"<<std::endl;
        return 0;
    }
    return 0;
}

void gameOver(sf::RenderWindow &window, sf::Font &font){
    sf::RectangleShape combat(sf::Vector2f(window.getSize().x,window.getSize().y));
    combat.setFillColor(sf::Color::Black);
    window.draw(combat);
    while(1){
        sf::Text gameOver;
        gameOver.setFont(font);
        gameOver.setString("GAME OVER");
        gameOver.setOrigin(gameOver.getGlobalBounds().width/2,gameOver.getGlobalBounds().height/2);
        gameOver.setPosition(sf::Vector2f(window.getSize().x/2,window.getSize().y/2));
        window.draw(gameOver);
        window.display();
        sf::Event event;
        while(window.pollEvent(event)){
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
                break;
        }
    }
}