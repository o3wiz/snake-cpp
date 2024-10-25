#include "Apple.hpp"

#include "Specs.hpp"
#include "raylib.h"

using namespace snake;

Apple::Apple(const Vector2& position) : _position(position) {}

Vector2 Apple::GetPosition() const { return _position; }

void Apple::Draw() const {
  const int xPos = specs::cellSize * (_position.x + 0.5F);
  const int yPos = specs::cellSize * (_position.y + 0.5F);
  DrawCircle(xPos, yPos, specs::cellSize / 2.0F, specs::appleColor);
}
