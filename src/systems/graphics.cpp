#include "systems.hpp"
#include <iostream>

void Animation::animateFrame(sf::RenderWindow& window, float time, sf::Vector2f position) {
  iterator->setPosition(position);
  window.draw(*iterator);
  currentTime += time;
  if (currentTime > frameTime) {
    iterator++;
    currentTime -= frameTime;
    if (iterator == frames.end()) {
      iterator = frames.begin();
    }
  }
};


Static::Static() : Graphics () {};

Animation::Animation(vector<sf::Sprite> f) : Graphics () {
  frames = f;
  flags |= F_CANIMATED
  iterator = frames.begin();
};

void drawHandler(State& state, sf::RenderWindow& window, float time) {
  window.clear();
  size_t index = 0;
  for(vector<EntityPointers>::iterator it = state.entityPointers.begin(); it != state.entityPointers.end(); ++it) {
    if (state.hasComponents(index++, F_GRAPHICS)) {
      if (it->graphics->flags & F_CANIMATED) it->graphics->animateFrame(window, time, it->position);
    }
  }
  window.display();
}
