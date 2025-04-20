#pragma once
#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_HEIGHT 8
#define TILE_WIDTH 8
#define MAX_TEXTURES 1

enum TextureAssets { TEXTURE_TILEMAP = 0 };

struct Tile {
  int x;
  int y;
};
