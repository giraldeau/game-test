#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

typedef sf::Vector2f Pos;

enum Collision_t {
  STICKS,
  BOUNCES,
  VANISHES,
  EXPLODES
};

struct Physics{
  float mass;
  float friction;
  Collision_t collision;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;
};

struct Graphics{
  bool hidden;
  sf::Sprite sprite;
  sf::Vector2f scale;
};
