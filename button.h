/**
 * @file button.h
 * @author Zackary Morrow
 * @brief declaration file for button related functions
 * @version 0.1
 * @date 2023-05-03
 * 
 * @copyright Copyright (c) 2023
 * Compile command: g++ -std=c++11 *.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
 */


#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>


enum state {normal, hovered, clicked};

class Button: public sf::Drawable
{
public:
    //Default constructor that loads texture from file “button.png” and font from “college.ttf” file.
    //set texture for mButton, set the origin to the middle of the button (texture), 
    //set color to White, position to {300,100}, set state to normal, and scale to 100%
    //set font for the text, set the size of the text to the half of Button size, set the origin to the middle of the text 
    //and set position at the middle of the button, assign “Push me!” as a string of the button
    Button();
    //Constructor that sets button label to s, button position to the position,  button size to size (given in pixels), and button color to color.
    Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~Button(){};
    //change button position to position (what else needs to be changed?)
    void setPosition(sf::Vector2f position);
    //change button size to size (what else needs to be changed?)
    void setSize(sf::Vector2f  size);
    //change button color to color (what else needs to be changed?)
    void setColor(sf::Color btnColor);
    //change button label to s (what else needs to be changed?)
    void setText(std::string s);
    void setColorTextNormal(sf::Color textNormalColor){mTextNormal = textNormalColor;};
    void setColorTextHover(sf::Color textHoverColor){mTextHover = textHoverColor;};

    sf::Vector2f getPosition(){return mPosition;};
    sf::Vector2f getDimensions(){return sf::Vector2f(mButton.getGlobalBounds().width, mButton.getGlobalBounds().height);};
    sf::Uint32 getState(){return mBtnState;};

    //This function update the button state and/or look
    void updateMenu(sf::RenderWindow& window);
    void updateParty(sf::RenderWindow& window, int choice);
    void updateItems(sf::RenderWindow& window, int choice);
    void updateMagic(sf::RenderWindow& window, int choice);
    void updateQuit(sf::RenderWindow& window, int choice);
    void updateStart(sf::Event& e, sf::RenderWindow& window, int mainChoice);
    void updateExit(sf::Event& e, sf::RenderWindow& window, int mainChoice);

    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

private:
    sf::Sprite mButton;
    sf::Sprite mButton2;
    sf::Texture mTexture;
    sf::Color mButtonColor;
    sf::Vector2f mPosition;
    sf::Uint32 mBtnState;
    
    //text
    sf::Text mText;
    sf::Font mFont;
    sf::Color mTextNormal;
    sf::Color mTextHover;

};

#endif