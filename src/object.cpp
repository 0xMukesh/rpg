#include "object.h"
#include <cmath>

Object::Object(Vector2 position, Vector2 velocity, float radius)
    : position(position), velocity(velocity), radius(radius) {}

void Object::accelerate(float x, float y) {
  velocity.x += x;
  velocity.y += y;
}

void Object::updatePosition() {
  position.x += velocity.x;
  position.y += velocity.y;
}

void Object::drawCircle() { DrawCircle(position.x, position.y, radius, WHITE); }

bool Object::doesCollide(Object &a) {
  float dx = position.x - a.position.x;
  float dy = position.y - a.position.y;
  float dist = sqrt(dx * dx + dy * dy);
  return dist <= radius + a.radius;
}

void Object::handleBoundaryCollision(float height, float width) {
  if (position.y + radius > height) {
    position.y = height - radius;
    velocity.y *= -0.7;
  }

  if (position.x + radius < 0) {
    position.x = radius;
    velocity.x *= -0.5;
  }

  if (position.x + radius > width) {
    position.x = width - radius;
    velocity.x *= 0.5;
  }
}

void Object::handleKeyboardInput() {
  if (IsKeyDown(KEY_LEFT)) {
    velocity.x -= 0.1;
  }

  if (IsKeyDown(KEY_RIGHT)) {
    velocity.x += 0.1;
  }
}
