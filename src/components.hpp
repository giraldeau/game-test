#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

typedef sf::Vector2f Pos;

// --- Collision system ---
enum Collision_t {
  STICKS,
  BOUNCES,
  VANISHES,
  EXPLODES
};

// --- Physics system ---
struct Physics{
  float mass;
  float friction;
  Collision_t collision;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;
};

// --- Graphics system ---

// Base class. Always use the derived classes.
struct Graphics{
  bool isAnimated;
  bool hidden = false;
  sf::Vector2f scale;
  virtual void animateFrame(sf::RenderWindow& window,  int frameCount, sf::Vector2f position) {std::cout << "woopsie" << std::endl;};
  Graphics() {};
};

// Animated graphics component.
struct Animation : public Graphics {
  std::vector<sf::Sprite> frames;
  std::vector<sf::Sprite>::iterator iterator;
  void animateFrame(sf::RenderWindow& window,  int frameCount, sf::Vector2f position);
  int16_t frameRate = 0;
  Animation(std::vector<sf::Sprite>);
};


  // Static graphics component
struct Static : public Graphics {
  sf::Sprite sprite;
  Static();
};
