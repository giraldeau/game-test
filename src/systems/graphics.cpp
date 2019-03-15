#include "systems.hpp"

void drawHandler(sf::RenderWindow& window, State state) {
  sf::Texture texture;
  texture.loadFromFile("resources/sprites/kappa.png", sf::IntRect(10, 10, 1080, 1080));
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(state.entities[0].position);
  sprite.setScale(sf::Vector2f(0.1f, 0.1f));
  window.clear();
  window.draw(sprite);
  window.display();
}
