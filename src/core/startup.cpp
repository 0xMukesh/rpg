#include "startup.h"
#include "../common.h"
#include "../utils/utils.h"
#include "raylib.h"

Texture2D textures[MAX_TEXTURES];

void GameStartup(GameContext &ctx) {
  Image image = LoadImage("../resources/tilemap.png");
  ctx.textures[TEXTURE_TILEMAP] = LoadTextureFromImage(image);
  UnloadImage(image);

  for (int i = 0; i < WORLD_WIDTH; i++) {
    for (int j = 0; j < WORLD_HEIGHT; j++) {
      int rand = GetRandomValue(1, 100);
      int tileType;

      if (rand <= 70) {
        tileType = TILE_TYPE_DIRT;
      } else if (rand <= 90) {
        tileType = TILE_TYPE_GRASS;
      } else if (rand <= 95) {
        tileType = TILE_TYPE_DEFAULT_TREE;
      } else if (rand <= 98) {
        tileType = TILE_TYPE_PINE_TREE;
      } else {
        tileType = TILE_TYPE_BEACH_TREE;
      }

      ctx.world[i][j] = {i, j, tileType};
    }
  }

  // start from welcome page
  ctx.page = GAME_PAGE_WELCOME;
  utils::game_pages::InitializeWelcomePage(ctx);

  // set player in the centre of the screen initially
  ctx.player.position = Vector2{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};

  ctx.camera.target = ctx.player.position;
  // "offset" is where the "target" will appear on the screen
  ctx.camera.offset = Vector2{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
  ctx.camera.rotation = 0;
  ctx.camera.zoom = 3;
}
