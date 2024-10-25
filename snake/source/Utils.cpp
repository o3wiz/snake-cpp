#include "Utils.hpp"

#include "Specs.hpp"
#include "raylib.h"

using namespace snake;

bool utils::inBounds(const Vector2& position) {
  const auto [x, y] = position;
  return (0 <= x && x < specs::cellsPerRow) &&
         (0 <= y && y < specs::cellsPerColumn);
}

Vector2 utils::generateRandomPosition() {
  return Vector2(GetRandomValue(0, specs::cellsPerRow - 1),
                 GetRandomValue(0, specs::cellsPerColumn - 1));
}
