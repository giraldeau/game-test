#include "systems/systems.hpp"
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Stick Duels V3");
    sf::Clock Clock;
    State state;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      float time = Clock.restart().asSeconds();
      state = physicsHandler(state, time);
      window.clear();
        //drawHandler(window, state.graphics);
        window.display();
    }
    return 0;
}

// Drawing system
