#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct Component {};

// Define flags

typedef unsigned int f_componentList;
typedef unsigned short f_component;

const f_componentList F_PHYSICS = 0x1; // 00000001
const f_componentList F_GRAPHICS = 0x2; // 00000010
const f_componentList F_COLLISION = 0x4; // 00000100
const f_componentList F_POSITION = 0x8;

const f_component F_CREMOVED = 0x1;
const f_component F_CANIMATED = 0x2;

struct EntityPointers;

struct component : public Position {
  f_component flags;
  EntityPointers* entity;
  float x;
  float y;
};

// --- Collision system ---
enum Collision_t {
  STICKS,
  BOUNCES,
  VANISHES,
  EXPLODES
};


// --- Physics system ---

struct Physics{
  f_component flags;
  EntityPointers* entity;
  float mass;
  float friction;
  Collision_t collision;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;
};

// --- Graphics system ---

// Base class. Always use the derived classes.
struct Graphics{
  f_component flags;
  EntityPointers* entity;
  bool hidden = false;
  sf::Vector2f scale;
  virtual void animateFrame(sf::RenderWindow& window, float time, sf::Vector2f position) {};
  Graphics() {};
};

// Animated graphics component.
struct Animation : public Graphics {
  std::vector<sf::Sprite> frames;
  std::vector<sf::Sprite>::iterator iterator;
  void animateFrame(sf::RenderWindow& window, float time, sf::Vector2f position);
  float frameTime = 0;
  float currentTime = 0;
  Animation(std::vector<sf::Sprite>);
};


  // Static graphics component
struct Static : public Graphics {
  sf::Sprite sprite;
  Static();
};

struct Sound {
sf::SoundBuffer buffer;
sf::Sound sound;
};

struct Visual {
  sf::Texture texture;
  sf::Sprite sprite;
};

// --- Collision system ---
struct Collision{
  f_component flags;
  EntityPointers* entity;
};

struct EntityPointers {
  f_componentList componentFlags = 0;
  Physics* physics = 0;
  Graphics* graphics = 0;
  Collision* collision = 0;
  Position* position = 0;
};
