#pragma once

#include "common.h"
#include "raylib.h"

struct GameContext {
  Texture2D textures[MAX_TEXTURES];
  Tile world[WORLD_WIDTH][WORLD_HEIGHT];
  Camera2D camera;
  Player player;
};
