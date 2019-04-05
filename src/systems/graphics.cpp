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


Static::Static() : Graphics () {
  isAnimated = false;
};

Animation::Animation(vector<sf::Sprite> f) : Graphics () {
  frames = f;
  isAnimated = true;
  iterator = frames.begin();
};

void drawHandler(State& state, sf::RenderWindow& window, float time) {
  window.clear();
  for(vector<Entity>::iterator it = state.entities.begin(); it != state.entities.end(); ++it) {
    if (it->hasGraphics) {
      if ((it->graphics)->isAnimated) (it->graphics)->animateFrame(window, state.time, it->position);
    }
  }
  window.display();
  state.time = time;
}
