#include "systems.hpp"
#include <iostream>

void Animation::animateFrame(sf::RenderWindow& window,  int frameCount, sf::Vector2f position) {
  iterator->setPosition(position);
  std::cout << frameCount << std::endl;
  window.draw(*iterator);
  if (frameCount % frameRate == 0) {
    iterator++;
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

void drawHandler(State& state, sf::RenderWindow& window) {
  window.clear();
  for(vector<Entity>::iterator it = state.entities.begin(); it != state.entities.end(); ++it) {
    if (it->hasGraphics) {
      if ((it->graphics)->isAnimated) (it->graphics)->animateFrame(window, state.frameCount, it->position);
    }
  }

  window.display();
  state.frameCount++;
}
