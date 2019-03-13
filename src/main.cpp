#include "systems/systems.hpp"
#include <iostream>

struct State {
  std::vector<Entity> entities;
  std::vector<Physics> physics;
  std::vector<Graphics> graphics;
};
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Stick Duels V3");
    sf::Clock Clock;
    State state;
    std::cout << state.graphics.size();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      float time = Clock.GetElapsedTime();
      Clock.Reset();
      state.physics = handlePhysics(state.physiscs, time);
        window.clear();
        //drawHandler(window, state.graphics);
        window.display();
    }
    return 0;
}

// Drawing system
