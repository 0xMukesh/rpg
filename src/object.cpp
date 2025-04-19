#include "object.h"
#include <cmath>

Object::Object(Vector2 position, Vector2 velocity, float mass, float radius,
               bool isAtRest)
    : position(position), velocity(velocity), mass(mass), radius(radius),
      isAtRest(isAtRest) {}

void Object::drawCircle() { DrawCircle(position.x, position.y, radius, WHITE); }

void Object::accelerate(Vector2 acc) {
  velocity.x += acc.x;
  velocity.y += acc.y;
}

void Object::updatePosition(float dt) {
  position.x += velocity.x * dt;
  position.y += velocity.y * dt;
}

void Object::handleCollision(Object &obj) {
  float dx = obj.position.x - position.x;
  float dy = obj.position.y - position.y;
  float dist = sqrt(dx * dx + dy * dy);

  float minDist = obj.radius + radius;

  if (dist < minDist) {
    float nx = dx / dist;
    float ny = dy / dist;

    float relVelX = obj.velocity.x - velocity.x;
    float relVelY = obj.velocity.y - velocity.y;

    float relVelDotNormal = relVelX * nx + relVelY * ny;

    if (relVelDotNormal > 0)
      return;

    float restitution = 0.7f;

    float impulseScalar = -(1 + restitution) * relVelDotNormal;
    impulseScalar /= (1 / mass) + (1 / obj.mass);

    float impulseX = impulseScalar * nx;
    float impulseY = impulseScalar * ny;

    velocity.x -= impulseX / mass;
    velocity.y -= impulseY / mass;
    obj.velocity.x += impulseX / obj.mass;
    obj.velocity.y += impulseY / obj.mass;

    float overlap = minDist - dist;
    float correction = overlap * 0.5f;

    position.x -= nx * correction;
    position.y -= ny * correction;
    obj.position.x += nx * correction;
    obj.position.y += ny * correction;
  }
}
