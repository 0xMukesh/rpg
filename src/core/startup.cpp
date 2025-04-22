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

      // 50% - dirt
      // 25% - grass
      // 10% - default tree
      // 8% - pine tree
      // 6% - beach tree
      // 1% - coins
      if (rand <= 50) {
        tileType = TILE_TYPE_DIRT;
      } else if (rand <= 50 + 25) {
        tileType = TILE_TYPE_GRASS;
      } else if (rand <= 50 + 25 + 10) {
        tileType = TILE_TYPE_DEFAULT_TREE;
      } else if (rand <= 50 + 25 + 10 + 8) {
        tileType = TILE_TYPE_PINE_TREE;
      } else if (rand <= 50 + 25 + 10 + 8 + 6) {
        tileType = TILE_TYPE_BEACH_TREE;
      } else {
        tileType = TILE_TYPE_COIN;
      }

      ctx.world[i][j] = {i, j, tileType};
    }
  }

  // start from welcome page
  ctx.page = GAME_PAGE_WELCOME;
  utils::game_pages::InitializeWelcomePage(ctx);

  // set player in the centre of the screen initially
  ctx.player.position = Vector2{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
  ctx.player.coins = 0;

  ctx.camera.target = ctx.player.position;
  // "offset" is where the "target" will appear on the screen
  ctx.camera.offset = Vector2{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
  ctx.camera.rotation = 0;
  ctx.camera.zoom = 3;
}
