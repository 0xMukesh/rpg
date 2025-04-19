#include "utils.h"
#include <cstdlib>

namespace utils {
float randomFloat(float min, float max) {
  float r = float(std::rand()) / RAND_MAX;
  return min + r * (max - min);
}

Object randomObject(Vector2 position) {
  Color color = Color{(unsigned char)randomFloat(0, 255),
                      (unsigned char)randomFloat(0, 255),
                      (unsigned char)randomFloat(0, 255), 255};

  Object obj = Object(position, Vector2{0, 0}, randomFloat(10, 100),
                      randomFloat(10, 100), color);
  return obj;
}
} // namespace utils
