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

/**
 * @brief Construct a new Button and set its default values
 * 
 */
Button::Button()
{
    if (!mTexture.loadFromFile("button.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    // create sprite that look like a button
    mButton.setTexture(mTexture);

    // get size of image
    sf::Vector2u imageSize = mTexture.getSize();
    // change origin to the center of the image (makes rotation easy)
    mButton.setOrigin(imageSize.x / 2, imageSize.y / 2);
    // set position
    mButton.setPosition(300, 100);
    // choose color
    mButton.setColor(sf::Color::White);
    // set size as a ration of original size
    // mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
    // Make label
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout << "Error opening file\n";
        exit(2);
    }

    mText.setFont(mFont);
    // choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mText.setCharacterSize(fontSize);
    // set label
    mText.setString("Push me!");
    // set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
    // set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y - fontSize / 4);
    // choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Red;
    mText.setFillColor(mTextNormal);
}

/**
 * @brief Construct a new Button thats parameters arent set by member functions
 * 
 * @param s is the string that will be set for the button
 * @param position is the coordinates that the button will be located at
 * @param size is the dimensions of the button
 * @param color is the background color that the button will have set
 */
Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    if (!mTexture.loadFromFile("button.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    // create sprite that look like a button
    mButton.setTexture(mTexture);

    // get size of image
    sf::Vector2u imageSize = mTexture.getSize();
    // change origin to the center of the image (makes rotation easy)
    mButton.setOrigin(imageSize.x / 2, imageSize.y / 2);
    // set position
    mButton.setPosition(position.x, position.y);
    // choose color
    mButton.setColor(color);
    // set size as a ration of original size
    mButton.setScale(size.x / imageSize.x, size.y / imageSize.y);
    // Make label
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout << "Error opening file\n";
        exit(2);
    }

    mText.setFont(mFont);
    // choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mText.setCharacterSize(fontSize);
    // set label
    mText.setString(s);
    // set origin to the middle
    mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
    // set position at the middle of the button
    mText.setPosition(position.x, position.y - fontSize / 4);
    // choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Red;
    mText.setFillColor(mTextNormal);
}

/**
 * @brief updates the menu button in the main menu
 * @param window 
 */
void Button::updateMenu(sf::RenderWindow &window)
{
    mText.setFillColor(mTextNormal);
}

void Button::updateParty(sf::RenderWindow &window, int choice)
{

    if (choice == 1)
    {
        mText.setFillColor(mTextHover);
    }
    else
    {
        mText.setFillColor(mTextNormal);
    }
    if (choice == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {

        sf::RectangleShape rect(sf::Vector2f(1600.0f, 900.0f));

        rect.setFillColor(sf::Color::Black);
        rect.setScale(1600.0f, 900.0f);
        window.draw(rect);

        sf::RectangleShape partyMem1(sf::Vector2f(128.0f, 128.0f));
        partyMem1.setFillColor(sf::Color::Blue);
        partyMem1.setSize({300, 50});

        partyMem1.setPosition(sf::Vector2f(window.getSize().x / 2, 2 * window.getSize().y / 9));
        partyMem1.setOrigin(partyMem1.getLocalBounds().width / 2, partyMem1.getLocalBounds().height / 2);
        sf::Text pm1Text;
        pm1Text.setFont(mFont);
        pm1Text.setString("Paladin");
        pm1Text.setOrigin({pm1Text.getLocalBounds().width / 2, pm1Text.getLocalBounds().height / 2});
        pm1Text.setPosition(partyMem1.getPosition().x, partyMem1.getPosition().y - 10);
        // pm1Text.setCharacterSize(24);
        window.draw(partyMem1);
        window.draw(pm1Text);

        sf::RectangleShape partyMem2(sf::Vector2f(128.0f, 128.0f));
        partyMem2.setFillColor(sf::Color::Blue);
        partyMem2.setSize({300, 50});

        partyMem2.setPosition(sf::Vector2f(window.getSize().x / 2, 3 * window.getSize().y / 9));
        partyMem2.setOrigin(partyMem2.getLocalBounds().width / 2, partyMem2.getLocalBounds().height / 2);
        sf::Text pm2Text;
        pm2Text.setFont(mFont);
        pm2Text.setString("White Mage");
        pm2Text.setOrigin({pm2Text.getLocalBounds().width / 2, pm2Text.getLocalBounds().height / 2});
        pm2Text.setPosition(partyMem2.getPosition().x, partyMem2.getPosition().y - 10);
        // pm2Text.setCharacterSize(24);
        window.draw(partyMem2);
        window.draw(pm2Text);

        sf::RectangleShape partyMem3(sf::Vector2f(128.0f, 128.0f));
        partyMem3.setFillColor(sf::Color::Blue);
        partyMem3.setSize({300, 50});

        partyMem3.setPosition(sf::Vector2f(window.getSize().x / 2, 4 * window.getSize().y / 9));
        partyMem3.setOrigin(partyMem3.getLocalBounds().width / 2, partyMem3.getLocalBounds().height / 2);
        sf::Text pm3Text;
        pm3Text.setFont(mFont);
        pm3Text.setString("Black Mage");
        pm3Text.setOrigin({pm3Text.getLocalBounds().width / 2, pm3Text.getLocalBounds().height / 2});
        pm3Text.setPosition(partyMem3.getPosition().x, partyMem3.getPosition().y - 10);
        // pm3Text.setCharacterSize(24);
        window.draw(partyMem3);
        window.draw(pm3Text);

        sf::RectangleShape partyMem4(sf::Vector2f(128.0f, 128.0f));
        partyMem4.setFillColor(sf::Color::Blue);
        partyMem4.setSize({300, 50});

        partyMem4.setPosition(sf::Vector2f(window.getSize().x / 2, 5 * window.getSize().y / 9));
        partyMem4.setOrigin(partyMem4.getLocalBounds().width / 2, partyMem4.getLocalBounds().height / 2);
        sf::Text pm4Text;
        pm4Text.setFont(mFont);
        pm4Text.setString("Fighter");
        pm4Text.setOrigin({pm4Text.getLocalBounds().width / 2, pm4Text.getLocalBounds().height / 2});
        pm4Text.setPosition(partyMem4.getPosition().x, partyMem4.getPosition().y - 10);
        // pm4Text.setCharacterSize(24);
        window.draw(partyMem4);
        window.draw(pm4Text);
        // window.display();
    }
    else
    {
    }
}

void Button::updateItems(sf::RenderWindow &window, int choice)
{
    if (choice == 2)
    {
        mText.setFillColor(mTextHover);
    }
    else
    {
        mText.setFillColor(mTextNormal);
    }
    if (choice == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        sf::RectangleShape rect(sf::Vector2f(128.0f, 128.0f));
        rect.setFillColor(sf::Color::Black);
        rect.setScale(1600.0f, 900.0f);
        window.draw(rect);

        sf::RectangleShape item1(sf::Vector2f(128.0f, 128.0f));
        item1.setSize({300, 50});
        item1.setFillColor(sf::Color::Red);
        item1.setPosition(sf::Vector2f(window.getSize().x / 2, 2 * window.getSize().y / 9));
        item1.setOrigin(item1.getLocalBounds().width / 2, item1.getLocalBounds().height / 2);
        sf::Text i1text;
        i1text.setFont(mFont);
        i1text.setString("Potion");
        i1text.setOrigin(i1text.getLocalBounds().width / 2, i1text.getLocalBounds().height / 2);
        i1text.setPosition(item1.getPosition().x, item1.getPosition().y - 10);
        window.draw(item1);
        window.draw(i1text);

        // second section
        sf::RectangleShape item2(sf::Vector2f(128.0f, 128.0f));
        item2.setSize({300, 50});
        item2.setFillColor(sf::Color::Red);
        item2.setPosition(sf::Vector2f(window.getSize().x / 2, 3 * window.getSize().y / 9));
        item2.setOrigin(item2.getLocalBounds().width / 2, item2.getLocalBounds().height / 2);
        sf::Text i2text;
        i2text.setFont(mFont);
        i2text.setString("-----");
        i2text.setOrigin(i2text.getLocalBounds().width / 2, i2text.getLocalBounds().height / 2);
        i2text.setPosition(item2.getPosition().x, item2.getPosition().y - 10);
        window.draw(item2);
        window.draw(i2text);

        // third section
        sf::RectangleShape item3(sf::Vector2f(128.0f, 128.0f));
        item3.setSize({300, 50});
        item3.setFillColor(sf::Color::Red);
        item3.setPosition(sf::Vector2f(window.getSize().x / 2, 4 * window.getSize().y / 9));
        item3.setOrigin(item3.getLocalBounds().width / 2, item3.getLocalBounds().height / 2);
        sf::Text i3text;
        i3text.setFont(mFont);
        i3text.setString("-----");
        i3text.setOrigin(i3text.getLocalBounds().width / 2, i3text.getLocalBounds().height / 2);
        i3text.setPosition(item3.getPosition().x, item3.getPosition().y - 10);
        window.draw(item3);
        window.draw(i3text);

        // fourth section
        sf::RectangleShape item4(sf::Vector2f(128.0f, 128.0f));
        item4.setSize({300, 50});
        item4.setFillColor(sf::Color::Red);
        item4.setPosition(sf::Vector2f(window.getSize().x / 2, 5 * window.getSize().y / 9));
        item4.setOrigin(item4.getLocalBounds().width / 2, item4.getLocalBounds().height / 2);
        sf::Text i4text;
        i4text.setFont(mFont);
        i4text.setString("-----");
        i4text.setOrigin(i4text.getLocalBounds().width / 2, i4text.getLocalBounds().height / 2);
        i4text.setPosition(item4.getPosition().x, item4.getPosition().y - 10);
        window.draw(item4);
        window.draw(i4text);
        window.display();
    }
    else
    {
    }
}

void Button::updateMagic(sf::RenderWindow &window, int choice)
{
    if (choice == 3)
    {
        mText.setFillColor(mTextHover);
    }
    else
    {
        mText.setFillColor(mTextNormal);
    }
    if (choice == 3 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        sf::RectangleShape rect(sf::Vector2f(128.0f, 128.0f));
        rect.setFillColor(sf::Color::Black);
        rect.setScale(1600.0f, 900.0f);
        window.draw(rect);

        sf::RectangleShape item1(sf::Vector2f(128.0f, 128.0f));
        item1.setSize({300, 50});
        item1.setFillColor(sf::Color::Magenta);
        item1.setPosition(sf::Vector2f(window.getSize().x / 2, 2 * window.getSize().y / 9));
        item1.setOrigin(item1.getLocalBounds().width / 2, item1.getLocalBounds().height / 2);
        sf::Text i1text;
        i1text.setFont(mFont);
        i1text.setString("Smite");
        i1text.setOrigin(i1text.getLocalBounds().width / 2, i1text.getLocalBounds().height / 2);
        i1text.setPosition(item1.getPosition().x, item1.getPosition().y - 10);

        window.draw(item1);
        window.draw(i1text);

        // second section
        sf::RectangleShape item2(sf::Vector2f(128.0f, 128.0f));
        item2.setSize({300, 50});
        item2.setFillColor(sf::Color::Magenta);
        item2.setPosition(sf::Vector2f(window.getSize().x / 2, 3 * window.getSize().y / 9));
        item2.setOrigin(item2.getLocalBounds().width / 2, item2.getLocalBounds().height / 2);
        sf::Text i2text;
        i2text.setFont(mFont);
        i2text.setString("Cure");
        i2text.setOrigin(i2text.getLocalBounds().width / 2, i2text.getLocalBounds().height / 2);
        i2text.setPosition(item2.getPosition().x, item2.getPosition().y - 10);

        window.draw(item2);
        window.draw(i2text);

        // third section
        sf::RectangleShape item3(sf::Vector2f(128.0f, 128.0f));
        item3.setSize({300, 50});
        item3.setFillColor(sf::Color::Magenta);
        item3.setPosition(sf::Vector2f(window.getSize().x / 2, 4 * window.getSize().y / 9));
        item3.setOrigin(item3.getLocalBounds().width / 2, item3.getLocalBounds().height / 2);
        sf::Text i3text;
        i3text.setFont(mFont);
        i3text.setString("Fire");
        i3text.setOrigin(i3text.getLocalBounds().width / 2, i3text.getLocalBounds().height / 2);
        i3text.setPosition(item3.getPosition().x, item3.getPosition().y - 10);

        window.draw(item3);
        window.draw(i3text);

        // fourth section
        sf::RectangleShape item4(sf::Vector2f(128.0f, 128.0f));
        item4.setSize({300, 50});
        item4.setFillColor(sf::Color::Magenta);
        item4.setPosition(sf::Vector2f(window.getSize().x / 2, 5 * window.getSize().y / 9));
        item4.setOrigin(item4.getLocalBounds().width / 2, item4.getLocalBounds().height / 2);
        sf::Text i4text;
        i4text.setFont(mFont);
        i4text.setString("Slash");
        i4text.setOrigin(i4text.getLocalBounds().width / 2, i4text.getLocalBounds().height / 2);
        i4text.setPosition(item4.getPosition().x, item4.getPosition().y - 10);

        window.draw(item4);
        window.draw(i4text);
        window.display();
    }
    else
    {

    }
}

void Button::updateQuit(sf::RenderWindow &window, int choice)
{
    if (choice == 4)
    {
        mText.setFillColor(mTextHover);
    }
    else
    {
        mText.setFillColor(mTextNormal);
    }
    if (choice == 4 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        exit(1);
    }
    window.display();
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}

void Button::setText(std::string s)
{
    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mText.setCharacterSize(fontSize);
    mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
    // set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y - fontSize / 4);
    mText.setString(s);
}

void Button::setPosition(sf::Vector2f position)
{
    mPosition = position;
    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mButton.setPosition(position.x, position.y);
    mText.setCharacterSize(fontSize);
    mText.setPosition(position.x, position.y - fontSize / 4);
    mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
    // set position at the middle of the button
}

void Button::setSize(sf::Vector2f size)
{
    mButton.setScale(size.x / mButton.getGlobalBounds().width, size.y / mButton.getGlobalBounds().height);
    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mText.setCharacterSize(fontSize);
    mText.setPosition(mPosition.x, mPosition.y - fontSize / 4);
    mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
    // set position at the middle of the button
}

void Button::setColor(sf::Color btnColor)
{
    mButton.setColor(btnColor);
}

void Button::updateStart(sf::Event &e, sf::RenderWindow &window, int mainChoice)
{
    if (mainChoice == 1)
    {
        mText.setFillColor(mTextHover);
    }
    else
    {
        mText.setFillColor(mTextNormal);
    }
    if (mainChoice == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        // michaels overworld loop
    }
    window.display();
}

void Button::updateExit(sf::Event &e, sf::RenderWindow &window, int mainChoice)
{
    if (mainChoice == 2)
    {
        mText.setFillColor(mTextHover);
    }
    else
    {
        mText.setFillColor(mTextNormal);
    }
    if (mainChoice == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        exit(1);
    }
    window.display();
}