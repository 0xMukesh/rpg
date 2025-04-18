#include "raylib.h"

#ifndef OBJECT
#define OBJECT

class Object {
public:
  Vector2 position;
  Vector2 velocity;
  float mass;
  float radius;

  Object(Vector2 position, Vector2 velocity, float mass, float radius);
  void accelerate(Vector2 acc);
  void updatePosition(float dt);
  void handleCollision(Object &obj);
  void drawCircle();
};

#endif
