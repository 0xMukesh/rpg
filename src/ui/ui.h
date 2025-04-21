#pragma once

#include <raylib.h>

struct WelcomePageLayout {
  Rectangle titleBounds;
  Rectangle subtitleBounds;
};

struct CharacterSelectionPageLayout {
  Rectangle titleBounds;
  Rectangle maleTextBounds;
  Rectangle femaleTextBounds;
};

namespace ui {
WelcomePageLayout ComputeWelcomePageLayout(const char *title,
                                           const char *subtitle);
CharacterSelectionPageLayout
ComputeCharacterSelectionPageLayout(const char *title, const char *maleText,
                                    const char *femaleText);

} // namespace ui