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

void Button::updateMenu(sf::Event& e, sf::RenderWindow& window)
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
    
        
    /*
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
            }*/
}

void Button::updateParty(sf::Event& e, sf::RenderWindow& window)
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
                
                sf::RectangleShape rect(sf::Vector2f(128.0f, 128.0f));
                rect.setFillColor(sf::Color::Black);
                rect.setScale(800.0f, 500.0f);
                window.draw(rect);
                /*
                window.draw(rect);
                Button back;
                back.setText("BACK");
                back.setPosition({400, 425});
                back.setSize({200, 71});
                back.setColor(sf::Color(0,0,0));
                back.setColorTextHover(sf::Color::Green);
                back.setColorTextNormal(sf::Color::Red);
                window.draw(back);
                */

               sf::RectangleShape partyMem1(sf::Vector2f(128.0f, 128.0f));
               partyMem1.setFillColor(sf::Color::Blue);
               partyMem1.setSize({300, 50});
               
               partyMem1.setPosition({400, 100});
               partyMem1.setOrigin(partyMem1.getLocalBounds().width/2, partyMem1.getLocalBounds().height/2);
               sf::Text pm1Text;
               pm1Text.setFont(mFont);
               pm1Text.setString("Party member 1");
               pm1Text.setOrigin({pm1Text.getLocalBounds().width/2, pm1Text.getLocalBounds().height/2});
               pm1Text.setPosition(partyMem1.getPosition().x, partyMem1.getPosition().y-10);
               //pm1Text.setCharacterSize(24);
               window.draw(partyMem1);
               window.draw(pm1Text);
               
               sf::RectangleShape partyMem2(sf::Vector2f(128.0f, 128.0f));
               partyMem2.setFillColor(sf::Color::Blue);
               partyMem2.setSize({300, 50});
               
               partyMem2.setPosition({400, 200});
               partyMem2.setOrigin(partyMem2.getLocalBounds().width/2, partyMem2.getLocalBounds().height/2);
               sf::Text pm2Text;
               pm2Text.setFont(mFont);
               pm2Text.setString("Party member 2");
               pm2Text.setOrigin({pm2Text.getLocalBounds().width/2, pm2Text.getLocalBounds().height/2});
               pm2Text.setPosition(partyMem2.getPosition().x, partyMem2.getPosition().y-10);
               //pm2Text.setCharacterSize(24);
               window.draw(partyMem2);
               window.draw(pm2Text);

               sf::RectangleShape partyMem3(sf::Vector2f(128.0f, 128.0f));
               partyMem3.setFillColor(sf::Color::Blue);
               partyMem3.setSize({300, 50});
               
               partyMem3.setPosition({400, 300});
               partyMem3.setOrigin(partyMem3.getLocalBounds().width/2, partyMem3.getLocalBounds().height/2);
               sf::Text pm3Text;
               pm3Text.setFont(mFont);
               pm3Text.setString("Party member 3");
               pm3Text.setOrigin({pm3Text.getLocalBounds().width/2, pm3Text.getLocalBounds().height/2});
               pm3Text.setPosition(partyMem3.getPosition().x, partyMem3.getPosition().y-10);
               //pm3Text.setCharacterSize(24);
               window.draw(partyMem3);
               window.draw(pm3Text);

               sf::RectangleShape partyMem4(sf::Vector2f(128.0f, 128.0f));
               partyMem4.setFillColor(sf::Color::Blue);
               partyMem4.setSize({300, 50});
               
               partyMem4.setPosition({400, 400});
               partyMem4.setOrigin(partyMem4.getLocalBounds().width/2, partyMem4.getLocalBounds().height/2);
               sf::Text pm4Text;
               pm4Text.setFont(mFont);
               pm4Text.setString("Party member 4");
               pm4Text.setOrigin({pm4Text.getLocalBounds().width/2, pm4Text.getLocalBounds().height/2});
               pm4Text.setPosition(partyMem4.getPosition().x, partyMem4.getPosition().y-10);
               //pm4Text.setCharacterSize(24);
               window.draw(partyMem4);
               window.draw(pm4Text);
            }
            else
            {
                
            }
        }
    }
}

void Button::updateItems(sf::Event& e, sf::RenderWindow& window)
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
                sf::RectangleShape rect(sf::Vector2f(128.0f, 128.0f));
                rect.setFillColor(sf::Color::Black);
                rect.setScale(800.0f, 500.0f);
                window.draw(rect);

                sf::RectangleShape item1(sf::Vector2f(128.0f, 128.0f));
                item1.setSize({300, 50});
                item1.setFillColor(sf::Color::Red);
                item1.setPosition({400, 100});
                item1.setOrigin(item1.getLocalBounds().width/2, item1.getLocalBounds().height/2);
                sf::Text i1text;
                i1text.setFont(mFont);
                i1text.setString("Item 1");
                i1text.setOrigin(i1text.getLocalBounds().width/2, i1text.getLocalBounds().height/2);
                i1text.setPosition(item1.getPosition().x, item1.getPosition().y-10);
                window.draw(item1);
                window.draw(i1text);

                //second section
                sf::RectangleShape item2(sf::Vector2f(128.0f, 128.0f));
                item2.setSize({300, 50});
                item2.setFillColor(sf::Color::Red);
                item2.setPosition({400, 200});
                item2.setOrigin(item2.getLocalBounds().width/2, item2.getLocalBounds().height/2);
                sf::Text i2text;
                i2text.setFont(mFont);
                i2text.setString("Item 2");
                i2text.setOrigin(i2text.getLocalBounds().width/2, i2text.getLocalBounds().height/2);
                i2text.setPosition(item2.getPosition().x, item2.getPosition().y-10);
                window.draw(item2);
                window.draw(i2text);

                //third section
                sf::RectangleShape item3(sf::Vector2f(128.0f, 128.0f));
                item3.setSize({300, 50});
                item3.setFillColor(sf::Color::Red);
                item3.setPosition({400, 300});
                item3.setOrigin(item3.getLocalBounds().width/2, item3.getLocalBounds().height/2);
                sf::Text i3text;
                i3text.setFont(mFont);
                i3text.setString("Item 3");
                i3text.setOrigin(i3text.getLocalBounds().width/2, i3text.getLocalBounds().height/2);
                i3text.setPosition(item3.getPosition().x, item3.getPosition().y-10);
                window.draw(item3);
                window.draw(i3text);

                //fourth section
                sf::RectangleShape item4(sf::Vector2f(128.0f, 128.0f));
                item4.setSize({300, 50});
                item4.setFillColor(sf::Color::Red);
                item4.setPosition({400, 400});
                item4.setOrigin(item4.getLocalBounds().width/2, item4.getLocalBounds().height/2);
                sf::Text i4text;
                i4text.setFont(mFont);
                i4text.setString("Item 4");
                i4text.setOrigin(i4text.getLocalBounds().width/2, i4text.getLocalBounds().height/2);
                i4text.setPosition(item4.getPosition().x, item4.getPosition().y-10);
                window.draw(item4);
                window.draw(i4text);

            }
            else
            {
                
            }
        }
    }
}

void Button::updateMagic(sf::Event& e, sf::RenderWindow& window)
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
                sf::RectangleShape rect(sf::Vector2f(128.0f, 128.0f));
                rect.setFillColor(sf::Color::Black);
                rect.setScale(800.0f, 500.0f);
                window.draw(rect);

                sf::RectangleShape item1(sf::Vector2f(128.0f, 128.0f));
                item1.setSize({300, 50});
                item1.setFillColor(sf::Color::Magenta);
                item1.setPosition({400, 100});
                item1.setOrigin(item1.getLocalBounds().width/2, item1.getLocalBounds().height/2);
                sf::Text i1text;
                i1text.setFont(mFont);
                i1text.setString("Spell 1");
                i1text.setOrigin(i1text.getLocalBounds().width/2, i1text.getLocalBounds().height/2);
                i1text.setPosition(item1.getPosition().x, item1.getPosition().y-10);

                sf::CircleShape icon1(20);
                icon1.setFillColor(sf::Color::Magenta);
                icon1.setPosition({200, 100});
                icon1.setOrigin(icon1.getLocalBounds().width/2, icon1.getLocalBounds().height/2);

                window.draw(item1);
                window.draw(i1text);
                window.draw(icon1);

                //second section
                sf::RectangleShape item2(sf::Vector2f(128.0f, 128.0f));
                item2.setSize({300, 50});
                item2.setFillColor(sf::Color::Magenta);
                item2.setPosition({400, 200});
                item2.setOrigin(item2.getLocalBounds().width/2, item2.getLocalBounds().height/2);
                sf::Text i2text;
                i2text.setFont(mFont);
                i2text.setString("Spell 2");
                i2text.setOrigin(i2text.getLocalBounds().width/2, i2text.getLocalBounds().height/2);
                i2text.setPosition(item2.getPosition().x, item2.getPosition().y-10);

                sf::CircleShape icon2(20);
                icon2.setFillColor(sf::Color::Magenta);
                icon2.setPosition({200, 200});
                icon2.setOrigin(icon2.getLocalBounds().width/2, icon2.getLocalBounds().height/2);

                window.draw(item2);
                window.draw(i2text);
                window.draw(icon2);

                //third section
                sf::RectangleShape item3(sf::Vector2f(128.0f, 128.0f));
                item3.setSize({300, 50});
                item3.setFillColor(sf::Color::Magenta);
                item3.setPosition({400, 300});
                item3.setOrigin(item3.getLocalBounds().width/2, item3.getLocalBounds().height/2);
                sf::Text i3text;
                i3text.setFont(mFont);
                i3text.setString("Spell 3");
                i3text.setOrigin(i3text.getLocalBounds().width/2, i3text.getLocalBounds().height/2);
                i3text.setPosition(item3.getPosition().x, item3.getPosition().y-10);

                sf::CircleShape icon3(20);
                icon3.setFillColor(sf::Color::Magenta);
                icon3.setPosition({200, 300});
                icon3.setOrigin(icon3.getLocalBounds().width/2, icon3.getLocalBounds().height/2);

                window.draw(item3);
                window.draw(i3text);
                window.draw(icon3);

                //fourth section
                sf::RectangleShape item4(sf::Vector2f(128.0f, 128.0f));
                item4.setSize({300, 50});
                item4.setFillColor(sf::Color::Magenta);
                item4.setPosition({400, 400});
                item4.setOrigin(item4.getLocalBounds().width/2, item4.getLocalBounds().height/2);
                sf::Text i4text;
                i4text.setFont(mFont);
                i4text.setString("Spell 4");
                i4text.setOrigin(i4text.getLocalBounds().width/2, i4text.getLocalBounds().height/2);
                i4text.setPosition(item4.getPosition().x, item4.getPosition().y-10);

                sf::CircleShape icon4(20);
                icon4.setFillColor(sf::Color::Magenta);
                icon4.setPosition({200, 400});
                icon4.setOrigin(icon4.getLocalBounds().width/2, icon4.getLocalBounds().height/2);

                window.draw(item4);
                window.draw(i4text);
                window.draw(icon4);
            }
            else
            {
                
            }
        }
    }
}

void Button::updateQuit(sf::Event& e, sf::RenderWindow& window)
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
                exit(1);
            }
            else
            {
                
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