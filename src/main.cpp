#include "systems/systems.hpp"
#include <iostream>

using namespace std;

const unsigned int framerateLimit = 60;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Stick Duels V3");
    window.setFramerateLimit(framerateLimit);
    sf::Clock Clock;
    State state;
    // TESTING
    Physics physics;
    sf::Vector2f acceleration(0, 400.1);
    sf::Vector2f velocity(-150, -300);
    sf::Vector2f pos(300, 300);
    physics.acceleration = acceleration;
    physics.velocity = velocity;
    Entity entity;
    entity.position = pos;
    entity.physics = physics;
    entity.hasPhysics = true;
    state.registerEntity(entity);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      float time = Clock.restart().asSeconds();
      physicsHandler(state, time);
      drawHandler(window, state);
    }
    return 0;
}
