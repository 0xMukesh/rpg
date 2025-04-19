#include "object.h"
#include "raylib.h"
#include "scene.h"

int main() {
  float width = 1200;
  float height = 1000;

  InitWindow(width, height, "gravity-sim");
  SetTargetFPS(120);

  Object ball1 = Object(Vector2{600, 600}, Vector2{0, 0}, 100, 20, WHITE);
  Object ball2 = Object(Vector2{600, 500}, Vector2{0, 0}, 100, 100, WHITE);

  Scene scene = Scene(width, height, {ball1, ball2});

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    scene.update(dt);

    BeginDrawing();
    ClearBackground(BLACK);
    scene.render();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}