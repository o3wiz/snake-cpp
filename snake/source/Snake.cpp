#include "Snake.hpp"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <unordered_map>

#include "Specs.hpp"
#include "Utils.hpp"
#include "raylib.h"
#include "raymath.h"

using namespace snake;

namespace {

bool isPerpDirections(const Direction dirA, const Direction dirB) {
  return ((dirA == Direction::Up || dirA == Direction::Down) &&
          (dirB == Direction::Right || dirB == Direction::Left)) ||
         ((dirB == Direction::Up || dirB == Direction::Down) &&
          (dirA == Direction::Right || dirA == Direction::Left));
}

} // namespace

Snake::Snake(const Vector2 &initialHeadPosition) {
  for (std::size_t i = 0; i < specs::initialSnakeBodyLength; ++i) {
    Vector2 bodyPart = initialHeadPosition;
    bodyPart.x += static_cast<float>(i);
    _body.push_back(bodyPart);
  }
}

Collision Snake::Move(const Direction newDirection,
                      const Vector2 &applePosition) {
  if (newDirection == Direction::None)
    return Collision::None;

  if (!this->hasDirection() && newDirection == Direction::Left)
    return Collision::None; // ignore invalid initial head movement

  const Vector2 moveVec = this->getDirectionVector(newDirection);
  if (!this->hasDirection() || isPerpDirections(newDirection, _headDirection))
    _headDirection = newDirection;

  const Vector2 newHeadPosition = Vector2Add(this->getHeadPosition(), moveVec);
  _body.push_back(newHeadPosition);

  const Collision coll = this->detectCollision(applePosition);
  if (coll != Collision::Apple)
    this->removeTail();

  return coll;
}

Vector2 Snake::getDirectionVector(const Direction direction) {
  const Direction dir =
      this->hasDirection() && !isPerpDirections(direction, _headDirection)
          ? _headDirection
          : direction;

  switch (dir) {
  case Direction::None:
    return Vector2{0, 0};
  case Direction::Up:
    return Vector2{0, -1};
  case Direction::Right:
    return Vector2{1, 0};
  case Direction::Down:
    return Vector2{0, 1};
  case Direction::Left:
    return Vector2{-1, 0};
  }

  return {}; // unnecessary
}

Vector2 Snake::getHeadPosition() const { return _body.back(); }

void Snake::removeTail() { _body.pop_front(); }

bool Snake::hasDirection() const { return _headDirection != Direction::None; }

Collision Snake::detectCollision(const Vector2 &applePosition) const {
  const Vector2 headPosition = this->getHeadPosition();

  if (Vector2Equals(headPosition, applePosition))
    return Collision::Apple;

  if (!utils::inBounds(headPosition))
    return Collision::Wall;

  const auto collidesWithHead = [&headPosition](const auto &pos) {
    return Vector2Equals(pos, headPosition);
  };
  if (this->hasDirection() &&
      std::any_of(std::next(_body.rbegin()), _body.rend(), collidesWithHead))
    return Collision::Self;

  return Collision::None;
}

bool Snake::CollidesWith(const Vector2 &position) const {
  return std::ranges::any_of(_body, [&position](const auto &bodyPos) {
    return Vector2Equals(position, bodyPos);
  });
}

void Snake::Draw() const {
  constexpr float bodyPartRoundness{.5F};
  constexpr int bodyPartSegments{6};
  for (std::size_t idx = 0; const auto &[x, y] : _body) {
    const Rectangle snakeBodyPart{
        .x = x * specs::cellSize,
        .y = y * specs::cellSize,
        .width = specs::cellSize,
        .height = specs::cellSize,
    };
    const Color color = idx == 0                  ? specs::snakeHeadColor
                        : idx + 1 == _body.size() ? specs::snakeTailColor
                                                  : specs::snakeColor;
    DrawRectangleRounded(snakeBodyPart, bodyPartRoundness, bodyPartSegments,
                         color);
    ++idx;
  }
}

std::size_t Snake::SnakeLength() const { return _body.size(); }
