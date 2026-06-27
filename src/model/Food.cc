#include "Food.h"

void Food::Yield(const PointType point) {
  position_ = point;
  eaten_    = false;
}

void Food::Disappear() {
  eaten_    = true;
  position_ = {};
}

bool Food::IfEaten() const {
  return eaten_;
}

PointType Food::GetPosition() const {
  return position_;
}