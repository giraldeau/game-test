#include "systems/systems.hpp"
#include <iostream>

using namespace std;

const int framerateLimit = 20;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Stick Duels V3");
    window.setFramerateLimit(framerateLimit);
    sf::Clock Clock;
    State state;
    cout << state.frameCount << "dadwdi awd " << endl;
    // TESTING
    Physics physics;
    sf::Vector2f acceleration(0, -40.1);
    sf::Vector2f velocity(-10, 30);
    sf::Vector2f pos(300, 300);
    physics.acceleration = acceleration;
    physics.velocity = velocity;
    Entity entity;
    entity.position = pos;
    entity.physics = physics;
    entity.hasPhysics = true;
    entity.hasGraphics = true;
    sf::Texture texture1;
    sf::Texture texture2;
    texture1.loadFromFile("resources/sprites/justin.png", sf::IntRect(10, 10, 1080, 1080));
    texture2.loadFromFile("resources/sprites/kappa.png", sf::IntRect(10, 10, 1080, 1080));
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    sprite1.setScale(sf::Vector2f(0.5f, 0.5f));
    sprite2.setScale(sf::Vector2f(0.2f, 0.2f));
    vector<sf::Sprite> vec;
    vec.push_back(sprite1);
    vec.push_back(sprite2);
    Animation animation(vec);
    animation.frameRate = 4;
    entity.graphics = &animation;
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
      drawHandler(state, window);
    }
    return 0;
}
