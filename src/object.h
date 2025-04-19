#include "raylib.h"

#ifndef OBJECT
#define OBJECT

class Object {
public:
  Vector2 position;
  Vector2 velocity;
  float mass;
  float radius;
  Color color;
  bool isGrounded = false;

  Object(Vector2 position, Vector2 velocity, float mass, float radius,
         Color color);
  void accelerate(Vector2 acc);
  void updatePosition(float dt);
  void handleCollision(Object &obj, float width, float height);
  void drawCircle();
};

#endif
