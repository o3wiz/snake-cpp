#pragma once

#include <deque>

#include "Drawable.hpp"
#include "raylib.h"

namespace snake {

enum class Direction {
  None = 0,
  Up,
  Right,
  Down,
  Left,
};

enum class Collision {
  None = 0,
  Food,
  Self,
  Wall,
};

class Snake : public Drawable {
 public:
  Snake(const Vector2& initialHeadPosition);
  Collision Move(const Direction newDirection, const Vector2& foodPosition);
  void Draw() const override;

 private:
  std::deque<Vector2> _body;
  Direction _headDirection = Direction::None;
};

}  // namespace snake
