#include "object.h"
#include "raylib.h"
#include "scene.h"

int main() {
  float width = 1200;
  float height = 1000;

  InitWindow(width, height, "gravity-sim");

  Object ball1 = Object(Vector2{600, 700}, Vector2{0, 0}, 100, 20);
  Object ball2 = Object(Vector2{600, 800}, Vector2{0, 0}, 100, 20);

  Scene scene = Scene(width, height, {ball1, ball2});

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    scene.update(dt);
    scene.render();
    ClearBackground(BLACK);
    BeginDrawing();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}