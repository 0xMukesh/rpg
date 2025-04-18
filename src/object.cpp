#include "object.h"
#include <cmath>

Object::Object(Vector2 position, Vector2 velocity, float radius, float mass)
    : position(position), velocity(velocity), radius(radius), mass(mass) {}

void Object::accelerate(float x, float y) {
  velocity.x += x;
  velocity.y += y;
}

void Object::updatePosition() {
  position.x += velocity.x;
  position.y += velocity.y;
}

void Object::drawCircle() { DrawCircle(position.x, position.y, radius, WHITE); }

bool Object::resolveCollision(Object &a) {
  float dx = position.x - a.position.x;
  float dy = position.y - a.position.y;
  float dist = sqrt(dx * dx + dy * dy);

  float minDist = radius + a.radius;

  if (dist < minDist && dist > 0.0f) {
    float overlap = minDist - dist;

    float nx = dx / dist;
    float ny = dy / dist;

    position.x += nx * (overlap / 2);
    position.y += ny * (overlap / 2);
    a.position.x -= nx * (overlap / 2);
    a.position.y -= ny * (overlap / 2);

    std::swap(velocity, a.velocity);

    return true;
  }

  return false;
}

void Object::handleBoundaryCollision(float height, float width) {
  if (position.y + radius < 0) {
    position.y = radius;
    velocity.y *= -0.5;
  }

  if (position.y + radius > height) {
    position.y = height - radius;
    velocity.y *= -0.5;
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
