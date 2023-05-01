/*
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Green);
    shape.setSize({200, 71});
    //shape.setPosition({400, 300});
    shape.setOrigin(shape.getGlobalBounds().height/2, shape.getGlobalBounds().width/2);
    shape.setPosition({400, 300});
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
*/