#pragma once

#include "common.h"
#include "raylib.h"

struct WelcomePageText {
  const char *title;
  const char *subtitle;
  Rectangle titleBounds;
  Rectangle subtitleBounds;
};

union PageState {
  WelcomePageText welcome;

  PageState() {}
  ~PageState() {}
};

struct GameContext {
  Texture2D textures[MAX_TEXTURES];
  Tile world[WORLD_WIDTH][WORLD_HEIGHT];
  Camera2D camera;
  Player player;
  GamePage page;

  PageState pageState;
};
