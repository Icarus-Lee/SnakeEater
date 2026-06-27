#include "Map.h"

Map::Map(int width, int height) : width_(width), height_(height) {}

int Map::GetWidth() {
  return width_;
}

int Map::GetHeight() {
  return height_;
}

bool Map::IsOutOfMap(const PointType& point) const {
  return point.x < 0 || point.y < 0 || point.x >= height_ || point.y >= width_;
}