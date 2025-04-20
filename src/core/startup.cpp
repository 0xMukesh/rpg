#include "startup.h"
#include "../common.h"
#include "raylib.h"

Texture2D textures[MAX_TEXTURES];

void GameStartup(GameContext &ctx) {
  Image image = LoadImage("../resources/tilemap.png");
  ctx.textures[TEXTURE_TILEMAP] = LoadTextureFromImage(image);
  UnloadImage(image);

  for (int i = 0; i < WORLD_WIDTH; i++) {
    for (int j = 0; j < WORLD_HEIGHT; j++) {
      ctx.world[i][j] = {i, j,
                         GetRandomValue(TILE_TYPE_DIRT, TILE_TYPE_BEACH_TREE)};
    }
  }
}
