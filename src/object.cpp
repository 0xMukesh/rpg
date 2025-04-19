#include "object.h"
#include "constants.h"
#include "raylib.h"
#include <cmath>

Object::Object(Vector2 position, Vector2 velocity, float mass, float radius,
               Color color)
    : position(position), velocity(velocity), mass(mass), radius(radius),
      color(color) {}

void Object::drawCircle() { DrawCircle(position.x, position.y, radius, color); }

void Object::accelerate(Vector2 acc) {
  velocity.x += acc.x;
  velocity.y += acc.y;
}

void Object::updatePosition(float dt) {
  position.x += velocity.x * dt;
  position.y += velocity.y * dt;
}

void Object::handleCollision(Object &obj, float width, float height) {
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

    isGrounded = std::abs(velocity.y) < constants::REST_THRESHOLD &&
                 position.y + radius >= height;
    obj.isGrounded = std::abs(obj.velocity.y) < constants::REST_THRESHOLD &&
                     obj.position.y + obj.radius >= height;

    const float percent = 0.8f;
    const float slop = 0.01f;
    float overlap = minDist - dist;

    float correctionMag =
        std::max(overlap - slop, 0.0f) / (1 / mass + 1 / obj.mass) * percent;

    float correctionX = correctionMag * nx;
    float correctionY = correctionMag * ny;

    position.x -= correctionX / mass;
    position.y -= correctionY / mass;
    obj.position.x += correctionX / obj.mass;
    obj.position.y += correctionY / obj.mass;
  }
}
