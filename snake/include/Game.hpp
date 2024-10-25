#pragma once

#include "Apple.hpp"
#include "Drawable.hpp"
#include "Snake.hpp"

namespace snake {

class Game : public Drawable {
 public:
  Game();
  ~Game();
  void Run();

 private:
  void Draw() const override;
  void update();
  bool shouldMoveSnake() const;
  void handleSnakeMovement(const Collision collision);
  void handleSnakeKeyPress();
  void createSnake();
  void spawnNewApple();
  void reset();

 private:
  Apple _apple;
  Snake _snake;
  Direction _nextSnakeDirection = Direction::None;
  bool _isRunning = false;
};

}  // namespace snake
