#pragma once

#include "raylib.h"

class Object {
public:
  Vector2 position;
  Vector2 velocity;
  float radius;

  Object(Vector2 position, Vector2 velocity, float radius);
  void accelerate(float x, float y);
  void updatePosition();
  void drawCircle();
  bool resolveCollision(Object &a);
  void handleBoundaryCollision(float height, float width);
  void handleKeyboardInput();
};
