#ifndef MAP_H
#define MAP_H

#include "Point.h"

class Map {
 private:
  int width_;
  int height_;

 public:
  Map(int width, int height);
  int  GetWidth();
  int  GetHeight();
  bool IsOutOfMap(const PointType& point) const;
};

#endif