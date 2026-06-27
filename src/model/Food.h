#ifndef FOOD_H
#define FOOD_H

#include "Point.h"
#include <memory>

class Food {
 private:
  PointType position_;
  bool      eaten_ = true;

 public:
  Food() = default;
  void      Yield(const PointType point);
  void      Disappear();
  bool      IfEaten() const;
  PointType GetPosition() const;
};

#endif