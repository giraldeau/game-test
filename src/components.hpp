#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

struct Entity{
  int index;
  int generation;
};

typedef sf::Vector2f Pos;

struct Physics{
  float mass;
  float friction;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;
};


struct Graphics{
  bool hidden;
  sf::Sprite sprite;
  sf::Vector2f scale;
};
