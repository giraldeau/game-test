#include "systems/systems.hpp"

struct State {
  std::vector<Entity> entities;
  std::vector<Physics> physics;
  std::vector<Graphics> graphics;
  std::vector<Pos> positions;
};

int draw(sf::RenderWindow, State);

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Stick Duels V3");
  
    State state;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawHandler(window, state.graphics);
        window.display();
    }
    return 0;
}

// Drawing system
