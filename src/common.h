#pragma once
#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define WORLD_WIDTH 100
#define WORLD_HEIGHT 100
#define TILE_HEIGHT 8
#define TILE_WIDTH 8
#define MAX_TEXTURES 1

enum TextureAssets { TEXTURE_TILEMAP = 0 };
enum TileType {
  TILE_TYPE_DIRT = 0,
  TILE_TYPE_GRASS,
  TILE_TYPE_DEFAULT_TREE,
  TILE_TYPE_PINE_TREE,
  TILE_TYPE_BEACH_TREE,
  TILE_TYPE_COIN,
};
enum GamePage {
  GAME_PAGE_WELCOME = 0,
  GAME_PAGE_CHARACTER_SELECTION,
  GAME_PAGE_IN_GAME
};
enum PlayerType { PLAYER_TYPE_MALE = 0, PLAYER_TYPE_FEMALE };

struct Tile {
  int x;
  int y;
  int type;
};

struct Player {
  Vector2 position;
  PlayerType type;
  int coins;
};
