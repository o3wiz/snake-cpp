#include "Utils.hpp"

#include "Specs.hpp"
#include "raylib.h"

using namespace snake;

bool utils::inBounds(const Vector2 &position) {
  const auto [x, y] = position;
  return (0 <= x && x < specs::cellsPerRow) &&
         (0 <= y && y < specs::cellsPerColumn);
}

Vector2 utils::generateRandomPosition(const int xMax, const int yMax) {
  Vector2 vec;
  vec.x = GetRandomValue(0, xMax);
  vec.y = GetRandomValue(0, yMax);
  return vec;
}
