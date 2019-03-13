#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

struct Entity{
  int index;
  int generation;
};

typedef collision_type char;
const collision_type STICKS = 0;
const collision_type BOUNCES = 1;
const collision_type VANISHES = 2;
const collision_type EXPLODES = 3;

struct Physics{
  float mass;
  float friction;
  collision_type collision;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;
  sf::Vector2f pos;
};


struct Graphics{
  bool hidden;
  sf::Sprite sprite;
  sf::Vector2f scale;
};
