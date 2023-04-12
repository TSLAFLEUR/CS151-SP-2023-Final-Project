/**
 * @file button.cpp
 * @author Zackary Morrow
 * @brief Implementation file
 * @version 0.1
 * @date 2023-03-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "button.h"

Button::Button()
{
    if (!mTexture.loadFromFile("button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    //create sprite that look like a button
    mButton.setTexture(mTexture);
    
    //get size of image
    sf::Vector2u imageSize=mTexture.getSize();
    //change origin to the center of the image (makes rotation easy)
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    //set position
    mButton.setPosition(300, 100);
    //choose color
    mButton.setColor(sf::Color::White);
    //set size as a ration of original size
    //mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
    //Make label
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    
    mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set label
    mText.setString("Push me!");
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
    //choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Red;
    mText.setFillColor(mTextNormal);
}

Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    if (!mTexture.loadFromFile("button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    //create sprite that look like a button
    mButton.setTexture(mTexture);
    
    //get size of image
    sf::Vector2u imageSize=mTexture.getSize();
    //change origin to the center of the image (makes rotation easy)
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    //set position
    mButton.setPosition(position.x,position.y);
    //choose color
    mButton.setColor(color);
    //set size as a ration of original size
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
    //Make label
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    
    mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set label
    mText.setString(s);
    //set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(position.x, position.y-fontSize/4);
    //choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Red;
    mText.setFillColor(mTextNormal);
}

void Button::update(sf::Event& e, sf::RenderWindow& window)
{
    //get position of the mouse
    //sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosition = window.mapPixelToCoords(mousePos);
    bool mouseInButton =    mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
                            && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
                            && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
                            && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
    if(e.type == sf::Event::MouseMoved)
    {
        if(mouseInButton)
        {
            mText.setFillColor(mTextHover);
        }
        else
        {
            mText.setFillColor(mTextNormal);
        }
    }
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if(e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                
            }
            else
            {
                
            }
        }
    }
    if (e.type == sf::Event::MouseButtonReleased)
    {
        if (e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mText.setFillColor(mTextHover);
                mButton.setRotation(0);
            }
                    else
                    {
                        mText.setFillColor(mTextNormal);
                        mButton.setRotation(0);
                    }
                }
            }
}

void Button::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}

void Button::setText(std::string s)
{
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
    mText.setString(s);
}

void Button::setPosition(sf::Vector2f position)
{
    mPosition = position;
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mButton.setPosition(position.x, position.y);
    mText.setCharacterSize(fontSize);
    mText.setPosition(position.x, position.y-fontSize/4);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
}

void Button::setSize(sf::Vector2f  size)
{
    mButton.setScale(size.x/mButton.getGlobalBounds().width, size.y/mButton.getGlobalBounds().height);
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    
}

void Button::setColor(sf::Color btnColor)
{
    mButton.setColor(btnColor);
}