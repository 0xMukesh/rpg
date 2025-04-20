#include "startup.h"
#include "../common.h"
#include "raylib.h"

Texture2D textures[MAX_TEXTURES];

void GameStartup(GameContext &ctx) {
  Image image = LoadImage("../resources/tilemap.png");
  ctx.textures[TEXTURE_TILEMAP] = LoadTextureFromImage(image);
  UnloadImage(image);
}
