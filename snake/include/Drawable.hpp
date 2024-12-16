#pragma once

namespace snake
{

class Drawable
{
  public:
	virtual ~Drawable() = default;
	virtual void Draw() const = 0;
};

} // namespace snake
