#include "systems/systems.hpp"
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;

const int framerateLimit = 20;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Stick Duels V3");
    window.setFramerateLimit(framerateLimit);
    sf::Clock Clock;
    sf::Clock animationClock;
    State state;
    sf::Keyboard keyboard;
    // TESTING
    Physics physics;
    sf::Vector2f acceleration(0, 0);
    sf::Vector2f velocity(0, 0);
    sf::Vector2f pos(200, 200);
    physics.acceleration = acceleration;
    physics.velocity = velocity;
    Entity entity;
    entity.position = pos;
    entity.physics = physics;
    entity.hasPhysics = true;
    entity.hasGraphics = true;
    Physics physics2;
    sf::Vector2f acceleration2(0, 0);
    sf::Vector2f velocity2(50, 0);
    sf::Vector2f pos2 = pos;
    physics.acceleration = acceleration2;
    physics.velocity = velocity2;
    Entity entity2;
    entity2.position = pos2;
    entity2.physics = physics2;
    entity2.hasPhysics = false;
    entity2.hasGraphics = false;
    sf::SoundBuffer buffer;
    buffer.loadFromFile("resources/audio/REEE.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    entity.hasSound = true;
    entity.sound = sound;
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
    entity.graphics = &animation;
    entity2.graphics = &animation2;
    state.registerEntity(entity);
    state.registerEntity(entity2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      float time = Clock.restart().asSeconds();
     if(state.entities[1].hasGraphics == false){
       state.entities[1].position.x = state.entities[0].position.x + 100.0;
       state.entities[1].position.y = state.entities[0].position.y;
       state.entities[1].physics.acceleration.x = 0.0;
     }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
       state.entities[0].position.x += 20.0;
       }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
         state.entities[0].position.x += -20.0;
         }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
           state.entities[0].position.y += -20.0;
         }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
             state.entities[0].position.y += 20.0;
             }
     if (state.entities[0].position.y > 300) {
        state.entities[0].physics.velocity.y = -state.entities[0].physics.velocity.y;
     }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
       state.entities[1].position.x += 20.0;

       }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
         state.entities[1].position.x += -20.0;
         }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
           state.entities[1].position.y += -20.0;
         }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
             state.entities[1].position.y += 20.0;
             }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
             state.entities[1].hasPhysics = true;
             state.entities[1].hasGraphics = true;
             }
      physicsHandler(state, time);
      drawHandler(state, window, time);
      soundHandler(state, keyboard);
      handleInput(state, keyboard);
    }
    return 0;
}
