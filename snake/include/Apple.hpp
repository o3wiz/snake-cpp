#pragma once

#include "Drawable.hpp"
#include "raylib.h"

namespace snake {

class Apple : public Drawable {
 public:
  explicit Apple(const Vector2& position = {});
  Vector2 GetPosition() const;
  void Draw() const override;

 private:
  Vector2 _position{};
};

}  // namespace snake
