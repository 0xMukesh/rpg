#pragma once

#include "context.h"
#include <raylib.h>

namespace utils {
void DrawHoverableText(const char *title, float x, float y, float fontSize,
                       Color normalColor, Color hoverColor);
} // namespace utils

namespace utils::game_pages {
void ChangeGamePage(GameContext &ctx, GamePage newPage);
void InitializeWelcomePage(GameContext &ctx);
} // namespace utils::game_pages

namespace utils::text_bounds {
Rectangle GetWelcomePageTitleRectBounds(const char *title);
Rectangle GetWelcomePageSubtitleRectBounds(const char *subtitle);
} // namespace utils::text_bounds
