#include "system.hpp"

using sf::Keyboard;
using sf::Keyboard::isKeyPressed;

void handleInputs(State& state, sf::RenderWindow& window){
  // Handle events
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }

  // Handle keyboard state
  if (isKeyPressed(Keyboard::Right)){
   state.entities[0].position.x += 20.0;
  }
  if (isKeyPressed(Keyboard::Left)){
    state.entities[0].position.x += -20.0;
  }
  if (isKeyPressed(Keyboard::Up)){
    state.entities[0].position.y += -20.0;
  }
  if (isKeyPressed(Keyboard::Down)){
    state.entities[0].position.y += 20.0;
  }
  if (state.entities[0].position.y > 300) {
    state.entities[0].physics.velocity.y = -state.entities[0].physics.velocity.y;
  }
  if (isKeyPressed(Keyboard::D)){
    state.entities[1].position.x += 20.0;
  }
  if (isKeyPressed(Keyboard::A)){
    state.entities[1].position.x += -20.0;
  }
  if (isKeyPressed(Keyboard::W)){
    state.entities[1].position.y += -20.0;
  }
  if (isKeyPressed(Keyboard::S)){
    state.entities[1].position.y += 20.0;
  }
  if (isKeyPressed(Keyboard::Space)){
    state.entities[1].hasPhysics = true;
    state.entities[1].hasGraphics = true;
  }
}
