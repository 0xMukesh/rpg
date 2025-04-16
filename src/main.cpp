#include "raylib.h"
#include <cmath>
#include <vector>

struct Ball {
  Vector2 position;
  Vector2 velocity;
  float radius;
  Color color;
};

class Object {
public:
  Vector2 position;
  Vector2 velocity;
  float radius;

  Object(Vector2 position, Vector2 velocity, float radius) {
    this->position = position;
    this->velocity = velocity;
    this->radius = radius;
  }

  void accelerate(float x, float y) {
    velocity.x += x;
    velocity.y += y;
  }

  void updatePosition() {
    position.x += velocity.x;
    position.y += velocity.y;
  }

  void drawCircle() { DrawCircle(position.x, position.y, radius, WHITE); }
};

bool checkCollision(const Object &a, const Object &b) {
  float dx = a.position.x - b.position.x;
  float dy = a.position.y - b.position.y;
  float dist = std::sqrt(dx * dx + dy * dy);
  return dist < a.radius + b.radius;
}

int main() {
  const float width = 800;
  const float height = 1000;

  InitWindow(width, height, "gravity sim");
  SetTargetFPS(120);

  std::vector<Object> objs = {
      Object((Vector2){width / 2 + 50, height * 0.2f}, (Vector2){0, 0}, 20),
      Object((Vector2){width / 2 - 50, height * 0.2f}, (Vector2){0, 0}, 20)};

  while (!WindowShouldClose()) {
    float time = GetFrameTime();

    for (auto &obj : objs) {
      obj.accelerate(0, 9.8 / 50);
      obj.updatePosition();

      if (obj.position.y + obj.radius > height) {
        obj.position.y = height - obj.radius;
        obj.velocity.y *= -0.7f;
      }

      if (obj.position.x + obj.radius < 0) {
        obj.position.x = obj.radius;
        obj.velocity.x *= -0.5;
      }

      if (obj.position.x + obj.radius > width) {
        obj.position.x = width - obj.radius;
        obj.velocity.x *= 0.5;
      }

      if (IsKeyDown(KEY_LEFT)) {
        obj.velocity.x -= 0.1;
      }

      if (IsKeyDown(KEY_RIGHT)) {
        obj.velocity.x += 0.1;
      }

      obj.drawCircle();
    }

    for (size_t i = 0; i < objs.size(); i++) {
      for (size_t j = i + 1; j < objs.size(); j++) {
        if (checkCollision(objs[i], objs[j])) {
          // You can handle collision response here
          DrawText("Collision!", 10, 10 + 20 * i, 20, RED);

          // Optional: simple elastic bounce by inverting velocity
          objs[i].velocity.x *= -1;
          objs[i].velocity.y *= -1;
          objs[j].velocity.x *= -1;
          objs[j].velocity.y *= -1;
        }
      }
    }

    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}