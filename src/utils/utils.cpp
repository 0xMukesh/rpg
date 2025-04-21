#include "utils.h"

void utils::DrawHoverableText(const char *text, float x, float y,
                              float fontSize, Color normalColor,
                              Color hoverColor) {
  float textWidth = MeasureText(text, fontSize);
  float textHeight = fontSize;

  Rectangle bounds = Rectangle{x, y, textWidth, textHeight};
  Vector2 mousePos = GetMousePosition();
  bool hovering = CheckCollisionPointRec(mousePos, bounds);

  DrawText(text, x, y, fontSize, hovering ? hoverColor : normalColor);
}
