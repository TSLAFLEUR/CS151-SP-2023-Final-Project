/**
 * @file combat.cpp
 * @author Tyler LaFleur
 * @brief This file contains all function definitions for combat.h 
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "combat.h"

/**
 * @brief This function restores the targets health by 2d4+4 health
 * 
 * @param a 
 */
void potion(Entity &a){
    a.setHP(a.getHP()+rand()%4+rand()%4+4);
    if(a.getmaxHP()<a.getHP()){
        a.setHP(a.getmaxHP());
    }
}

/**
 * @brief This function displays the current action at the top of the screen
 *        (i.e. attack, run, etc.)
 * 
 * @param s 
 * @param window 
 * @param font 
 */
void displayAction(string s,sf::RenderWindow &window,sf::Font &font){
    sf::RectangleShape victory(sf::Vector2f(window.getSize().x/5,window.getSize().y/5));
    victory.setFillColor(sf::Color::Black);
    victory.setOrigin(victory.getGlobalBounds().width/2,victory.getGlobalBounds().height/2);
    victory.setOutlineColor(sf::Color::White);
    victory.setOutlineThickness(2);
    victory.setPosition(window.getSize().x/2,window.getSize().y/5);//draw pal border
    window.draw(victory);sf::Text victoryText;
    victoryText.setFont(font);
    victoryText.setString(s);
    victoryText.setOrigin(victoryText.getGlobalBounds().width/2,victoryText.getGlobalBounds().height/2);
    victoryText.setPosition(window.getSize().x/2,window.getSize().y/5);
    window.draw(victoryText);
    window.display();
    usleep(1500000);
}

/**
 * @brief This function handles the choice of attacking the enemy and executes an attack action
 * 
 * @param font 
 * @param p 
 * @param window 
 * @param e 
 * @return true  player attacks
 * @return false player decides to not attack
 */
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
            if (event.type == sf::Event::Closed){
                window.close();
                exit(1);
            }
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
            
            }    
            selection.setPosition(20,3*window.getSize().y/4);
            window.draw(clearSelection);
            window.draw(selection);
            window.display(); 
        }
        
    }
    return true;
}

/**
 * @brief This function allows the active character execute their skill or magic
 * 
 * @param font 
 * @param a 
 * @param p 
 * @param w 
 * @param b 
 * @param f 
 * @param window 
 * @param e 
 * @return true 
 * @return false 
 */
bool skillMagic(sf::Font &font,Entity a,Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f,sf::RenderWindow &window,Entity &e){
    sf::Event event;
    int choice=1;
    int i=1;
    int height=0;
    sf::RectangleShape clearSelection(sf::Vector2f(30,160));
    clearSelection.setFillColor(sf::Color::Black);
    sf::Text selection;
    selection.setFont(font);
    selection.setString('>');
    if(a.getType()=='p'||a.getType()=='b'||a.getType()=='f'){
        clearSelection.setPosition(20,height+3*window.getSize().y/4);
        selection.setPosition(20,3*window.getSize().y/4);
        window.draw(selection);
        window.display();
        while(i!=0){
            i=1;
            while(window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                    exit(1);
                }
                if(event.type==sf::Event::KeyPressed){
                    if(event.key.code==sf::Keyboard::Enter){
                        if(choice==1){//fight
                            if(a.getType()=='p'){
                                return p.smite(e);
                            }else if(a.getType()=='b'){
                                return b.fire(e);
                            }else if(a.getType()=='f'){
                                return f.slash(e);
                            }
                            return true;
                        }
                    }
                    if(event.key.code==sf::Keyboard::Escape){
                        window.draw(clearSelection);
                        window.display();
                        return false;
                    }
                selection.setPosition(20,3*window.getSize().y/4);
                window.draw(clearSelection);
                window.draw(selection);
                window.display();
                }     
            }
        }
    }else if(a.getType()=='w'){
        clearSelection.setSize(sf::Vector2f(30,30));
        clearSelection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
        selection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
        window.draw(selection);
        window.display();
        while(i!=0){
        i=1;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                exit(1);
            }
            if(event.type==sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Enter){
                    if(choice==1){
                        return w.cure(p);
                    }else if(choice==2){
                        return w.cure(w);
                    }else if(choice==3){
                        return w.cure(b);
                    }if(choice==4){
                        return w.cure(f);
                    }
                    return true;
                }
                if(event.key.code==sf::Keyboard::Escape){
                    clearSelection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
                    window.draw(clearSelection);
                    return false;
                }
                if(event.key.code==sf::Keyboard::Down){
                    if(choice<4){
                        clearSelection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
                        window.draw(clearSelection);
                        choice++;
                    }
                    selection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
                }
                if(event.key.code==sf::Keyboard::Up){
                    if(choice>1){
                        clearSelection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
                        window.draw(clearSelection);
                        choice--;
                    }
                    selection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
                }
            window.draw(clearSelection);
            window.draw(selection);
            window.display();
            }     
        }
    }
    }
    return true;
}

/**
 * @brief This function allows the active character to use a potion on a party member
 * 
 * @param font 
 * @param a 
 * @param p 
 * @param w 
 * @param b 
 * @param f 
 * @param window 
 * @return true 
 * @return false 
 */
bool items(sf::Font &font,Entity a,Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f,sf::RenderWindow &window){
    sf::Event event;
    int choice=1;
    int i=1;
    int height=0;
    sf::RectangleShape clearSelection(sf::Vector2f(30,30));
    clearSelection.setFillColor(sf::Color::Black);
    clearSelection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
    window.draw(clearSelection);
    sf::Text selection;
    selection.setFont(font);
    selection.setString('>');
    selection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
    window.draw(selection);
    window.display();
    while(i!=0){
        i=1;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                exit(1);
                }
            if(event.type==sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Enter){
                    if(choice==1){
                        potion(p);
                    }else if(choice==2){
                        potion(w);
                    }else if(choice==3){
                        potion(b);
                    }if(choice==4){
                        potion(f);
                    }
                    return true;
                }
                if(event.key.code==sf::Keyboard::Escape){
                    clearSelection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
                    window.draw(clearSelection);
                    return false;
                }
                if(event.key.code==sf::Keyboard::Down){
                    if(choice<4){
                        clearSelection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
                        window.draw(clearSelection);
                        choice++;
                    }
                    selection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
                }
                if(event.key.code==sf::Keyboard::Up){
                    if(choice>1){
                        clearSelection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
                        window.draw(clearSelection);
                        choice--;
                    }
                    selection.setPosition(window.getSize().x-40,choice*window.getSize().y/5);
                }
            window.draw(clearSelection);
            window.draw(selection);
            window.display();
            }     
        }
    }
    return true;
}

/**
 * @brief This function allows the party to run from a combat, ending the sequence
 * 
 * @param Run 
 * @return true 
 * @return false 
 */
bool run(bool &Run){
    Run=true;
    return true;
}

/**
 * @brief This function displays the combat sequence graphics
 * 
 * @param myPaladin 
 * @param myWhiteMage 
 * @param myBlackMage 
 * @param myFighter 
 * @param window 
 * @param font 
 */
void displayCombat(Paladin &myPaladin,WhiteMage &myWhiteMage,BlackMage &myBlackMage,Fighter &myFighter,sf::RenderWindow &window,sf::Font &font){
    battleSprites testy1(spriteSelection[0]);
    battleSprites testy2(spriteSelection[1]);
    battleSprites testy3(spriteSelection[2]);
    battleSprites testy4(spriteSelection[3]);
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
    pal.setString("PALADIN"); 
    whm.setString("WHITE MAGE");
    blm.setString("BLACK MAGE");
    fht.setString("FIGHTER");
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
    if(myPaladin.isDefeated() == true)
    {
        testy3.offset = battleSpriteOffset[2] + 96;
        testy3.charSprite.setTextureRect(sf::IntRect(0, testy3.offset, 24, 24));
    }
    else
    {
        testy3.offset = battleSpriteOffset[2];
        testy3.charSprite.setTextureRect(sf::IntRect(0, testy3.offset, 24, 24));
    }
        if(myWhiteMage.isDefeated() == true)
    {
        testy4.offset = battleSpriteOffset[3] + 96;
        testy4.charSprite.setTextureRect(sf::IntRect(0, testy4.offset, 24, 24));
    }
    else
    {
        testy4.offset = battleSpriteOffset[3];
        testy4.charSprite.setTextureRect(sf::IntRect(0, testy4.offset, 24, 24));
    }
        if(myBlackMage.isDefeated() == true)
    {
        testy2.offset = battleSpriteOffset[1] + 96;
        testy2.charSprite.setTextureRect(sf::IntRect(0, testy2.offset, 24, 24));
    }
    else
    {
        testy2.offset = battleSpriteOffset[1];
        testy2.charSprite.setTextureRect(sf::IntRect(0, testy2.offset, 24, 24));
    }
        if(myFighter.isDefeated() == true)
    {
        testy1.offset = battleSpriteOffset[0] + 96;
        testy1.charSprite.setTextureRect(sf::IntRect(0, testy1.offset, 24, 24));
    }
    else
    {
        testy1.offset = battleSpriteOffset[0];
        testy1.charSprite.setTextureRect(sf::IntRect(0, testy1.offset, 24, 24));
    }
    window.draw(testy1.charSprite);
    window.draw(testy2.charSprite);
    window.draw(testy3.charSprite);
    window.draw(testy4.charSprite);
    window.display();
}

/**
 * @brief This function displays the list of enemies on bottom left
 * 
 * @param enemy 
 * @param window 
 * @param font 
 */
void displayEnemy(Enemy enemy,sf::RenderWindow &window,sf::Font &font){
    sf::Text en;
    en.setFont(font);
    en.setString("GOBLIN"); 
    en.setPosition(50,3*window.getSize().y/4);
    window.draw(en);
}

/**
 * @brief This function allows the active character to choose their action during their turn
 * 
 * @param font 
 * @param a 
 * @param p 
 * @param w 
 * @param b 
 * @param f 
 * @param window 
 * @param e 
 * @param Run 
 * @return true 
 * @return false 
 */
bool combatChoice(sf::Font &font,Entity a,Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f,sf::RenderWindow &window, Enemy &e,bool &Run){
    sf::RectangleShape clearActive(sf::Vector2f(30,4*window.getSize().y/5));
    clearActive.setFillColor(sf::Color::Black);
    clearActive.setPosition(4*window.getSize().x/5-50,window.getSize().y/5);
    window.draw(clearActive);
    sf::Text active;
    active.setFont(font);
    active.setString('>');
    if(a.getType()=='p'){
        active.setPosition(4*window.getSize().x/5-50,window.getSize().y/5);
    }else if(a.getType()=='w'){
        active.setPosition(4*window.getSize().x/5-50,2*window.getSize().y/5);
    }else if(a.getType()=='b'){
        active.setPosition(4*window.getSize().x/5-50,3*window.getSize().y/5);
    }else if(a.getType()=='f'){
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
            if (event.type == sf::Event::Closed){
                window.close();
                exit(1);
            }
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
                        if(madeCombatDecision){
                            displayAction("ATTACK",window,font);
                        }
                    }else if(choice==2){//skills
                        if(a.getType()=='p'){
                            madeCombatDecision=skillMagic(font,a,p,w,b,f,window,e);
                            if(madeCombatDecision){
                                displayAction("SMITE",window,font);
                            }
                        }else if(a.getType()=='b'){
                            madeCombatDecision=skillMagic(font,a,p,w,b,f,window,e);
                            if(madeCombatDecision){
                                displayAction("FIRE",window,font);
                            }
                        }else if(a.getType()=='w'){
                            madeCombatDecision=skillMagic(font,a,p,w,b,f,window,e);
                            if(madeCombatDecision){
                                displayAction("CURE",window,font);
                            }
                        }else if(a.getType()=='f'){
                            madeCombatDecision=skillMagic(font,a,p,w,b,f,window,e);
                            if(madeCombatDecision){
                                displayAction("SLASH",window,font);
                            }
                        }
                    }else if(choice==3){//items
                        madeCombatDecision=items(font,a,p,w,b,f,window);
                        if(madeCombatDecision){
                            displayAction("POTION",window,font);
                        }
                    }else if(choice==4){//run
                        madeCombatDecision=run(Run);
                        displayAction("RUN",window,font);
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

/**
 * @brief This function allows the enemy to make their action
 * 
 * @param p 
 * @param e 
 */
void combatEnemyAction(Entity &p,Enemy &e){
    e.attack(p);
}

/**
 * @brief This function checks if the party is active or dead
 * 
 * @param p 
 * @param w 
 * @param b 
 * @param f 
 * @return true  at least one party member is alive
 * @return false all party members are dead
 */
bool combatPartyActive(Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f){
    if(p.isDefeated()&&w.isDefeated()&&b.isDefeated()&&f.isDefeated()){
        return false;
    }
    return true;
}

/**
 * @brief This function checks if the enemy is active or dead
 * 
 * @param e 
 * @return true  the enemy is alive
 * @return false the enemy is dead
 */
bool combatEnemyActive(Enemy &e){
    if(e.isDefeated()){
        return false;
    }
    return true;
}

/**
 * @brief This function is in charge of the entire combat loop 
 * 
 * @param p 
 * @param w 
 * @param b 
 * @param f 
 * @param window 
 * @param font 
 * @param encounter 
 * @return int 
 */
int combat(Paladin &p,WhiteMage &w,BlackMage &b,Fighter &f, sf::RenderWindow &window, sf::Font &font, int encounter){
    //create turn queue
    std::queue<Entity> init;
    Enemy enemy[1];
    bool validTarget;
    init.push(f);
    init.push(b);
    init.push(p);
    init.push(w);
    init.push(enemy[0]);
    //display graphics
    displayCombat(p,w,b,f,window,font);
    displayEnemy(enemy[0],window,font);

    bool run=false;
    while(combatPartyActive(p,w,b,f)&&combatEnemyActive(enemy[0]))//while party and enemies are live
    {
        if(init.front().getType()=='p'){//if paladin's turn
            if(!p.isDefeated()){
                while(combatChoice(font,p,p,w,b,f,window,*enemy,run)){}
                init.push(init.front());
            }
            init.pop();
        } else if(init.front().getType()=='w'){//if white mage's turn
            if(!w.isDefeated()){
                while(combatChoice(font,w,p,w,b,f,window,*enemy,run)){}
                init.push(init.front());
            }
            init.pop();
        } else if(init.front().getType()=='b'){//if black mage's turn
            if(!b.isDefeated()){
                while(combatChoice(font,b,p,w,b,f,window,*enemy,run)){}
                init.push(init.front());
            }
            init.pop();
        } else if(init.front().getType()=='f'){//if fighter's turn
            if(!f.isDefeated()){
                while(combatChoice(font,f,p,w,b,f,window,*enemy,run)){}
                init.push(init.front());
            }
            init.pop();
        } else if(init.front().getType()=='e'){//if enemy's turn
            validTarget=false;
            while(!validTarget){
                switch(rand()%4){//choose a target at random, trying a new target if target is knocked out
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
            displayAction("ATTACK",window,font);
            init.push(init.front());//put front of queue to back
            init.pop();//remove current turn from front
            }
        }
        if(run){//if party decides to run, end combat
            return 2;
        }
        displayCombat(p,w,b,f,window,font);
        displayEnemy(enemy[0],window,font);
    }
    
    if(!combatEnemyActive(enemy[0])){//if enemy is dead, return with victory
        displayAction("VICTORY",window,font);
        return 1;
    }
    if(!combatPartyActive(p,w,b,f)){//if party is dead, return with game over
        return 0;
    }
    return 0;
}

/**
 * @brief This function displays the game over screen
 * 
 * @param window 
 * @param font 
 */
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
                exit(1);
        }
    }
}