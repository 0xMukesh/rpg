#pragma once

#include "../context.h"
#include <raylib.h>

namespace utils {
void DrawHoverableText(const char *title, float x, float y, float fontSize,
                       Color normalColor, Color hoverColor);
} // namespace utils

namespace utils::text_bounds {
Rectangle GetWelcomePageSubtitleBounds(const char *subtitle);
Rectangle GetCharacterSelectionFemaleTextBounds(const char *femaleText);
Rectangle GetCharacterSelectionMaleTextBounds(const char *maleText);
} // namespace utils::text_bounds

namespace utils::game_pages {
void ChangeGamePage(GameContext &ctx, GamePage newPage);
void InitializeWelcomePage(GameContext &ctx);
void InitializeCharacterSelectionPage(GameContext &ctx);
} // namespace utils::game_pages
