#include "walking.h"
#include "gameWorld.h"
const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML window");
    // Load a sprite to display
    spriteWalk character(spriteSelection[3]);
    character.charSprite.scale(sf::Vector2f(4.f, 4.f));

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    GameWorld gameWorld;
    for(int i = 0; i < gameWorld.gridLength;i++)
        {
            for(int j = 0;j <gameWorld.gridLength;j++)
            {
            gameWorld.gameTiles[i][j]->sprite.scale(sf::Vector2f(4.f, 4.f));
            }
        }
    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        //  Process events
        sf::Time start = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen

        // Draw the sprite
        // sf::sleep(start + TIME_PER_FRAME - clock.getElapsedTime());
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            //
        }
        for(int i = 0; i < gameWorld.gridLength;i++)
        {
            for(int j = 0;j <gameWorld.gridLength;j++)
            {
                window.draw(gameWorld.gameTiles[i][j]->sprite);
            }
        }
        // Update the window
        characterWalking(character);
        window.draw(character.charSprite);
        window.display();
        window.clear();
    }
    return EXIT_SUCCESS;
}