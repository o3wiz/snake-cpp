#pragma once

#include <cstddef>
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
  Apple,
  Self,
  Wall,
};

class Snake : public Drawable {
 public:
  Snake(const Vector2& initialHeadPosition = {});
  Collision Move(const Direction newDirection, const Vector2& applePosition);
  bool CollidesWith(const Vector2& position) const;
  void Draw() const override;
  std::size_t SnakeLength() const;

 private:
  Vector2 getDirectionVector(const Direction direction);
  Vector2 getHeadPosition() const;
  void removeTail();
  bool hasDirection() const;
  Collision detectCollision(const Vector2& applePosition) const;

 private:
  std::deque<Vector2> _body;
  Direction _headDirection = Direction::None;
};

}  // namespace snake
