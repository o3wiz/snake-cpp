#pragma once

#include "raylib.h"

namespace snake::utils {

bool inBounds(const Vector2& position);
Vector2 generateRandomPosition();

}
