#include "systems/systems.hpp"
#include <iostream>

using namespace std;

const int framerateLimit = 20;

int main()
{
    State state;
    sf::RenderWindow window(sf::VideoMode(600, 600), "Stick Duels V3");
    window.setFramerateLimit(framerateLimit);
    sf::Clock Clock;
    // TESTING
    EntityPointers entityptrs;
    EntityPointers entityptrs2;
    Physics physics;
    Physics physics2;
    sf::Vector2f acceleration(0, 0);
    sf::Vector2f acceleration2(0, 0);
    sf::Vector2f velocity(0, 0);
    sf::Vector2f velocity2(50, 0);
    sf::Vector2f pos(200, 200);
    sf::Vector2f pos2 = pos;
    physics.acceleration = acceleration;
    physics2.acceleration = acceleration2;
    physics.velocity = velocity;
    physics2.velocity = velocity2;


    sf::SoundBuffer buffer;
    buffer.loadFromFile("resources/audio/REEE.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sf::Texture texture1;
    sf::Texture texture2;
    //sf::Texture texture3;
    texture1.loadFromFile("resources/sprites/justin.png", sf::IntRect(10, 10, 1080, 1080));
    texture2.loadFromFile("resources/sprites/kappa.png", sf::IntRect(10, 10, 1080, 1080));
    //texture3.loadFromFile("resources/sprites/REE.jpg", sf::IntRect(10, 10, 1080, 1080));
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    //sf::Sprite sprite3;
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    //sprite3.setTexture(texture3);
    sprite1.setScale(sf::Vector2f(0.4f, 0.4f));
    sprite2.setScale(sf::Vector2f(0.1f, 0.1f));
    //sprite3.setScale(sf::Vector2f(0.1f, 0.1f));
    vector<sf::Sprite> vec;
    vector<sf::Sprite> vec2;
    vec.push_back(sprite1);
    vec2.push_back(sprite2);
    //vec.push_back(sprite3);
    Animation animation(vec);
    Animation animation2(vec2);
    animation.frameTime = .5;
    animation2.frameTime = 1;

    addComponent(&physics, F_PHYSICS, entityptrs);
    addComponent(&pos, F_POSITION, entityptrs);
    addComponent(&animation, F_GRAPHICS, entityptrs);

    addComponent(&physics2, F_PHYSICS, entityptrs2);
    addComponent(&pos2, F_POSITION, entityptrs2);
    addComponent(&animation, F_GRAPHICS, entityptrs);

    state.registerEntity(entityptrs);
    state.registerEntity(entityptrs2);

    // END TESTING

    while (window.isOpen())
    {
      float time = Clock.restart().asSeconds();

      inputHandler(state, window);
      physicsHandler(state, time);
      drawHandler(state, window, time);
    }
    return 0;
}
