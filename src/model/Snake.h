#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "Point.h"
#include "Direction.h"

class SnakeBody {
 private:
  std::deque<PointType> positions_;

 public:
  SnakeBody(const PointType& point_start);
  const PointType&             GetHead() const;
  const std::deque<PointType>& GetPositions() const;
  PointType                    PopTail();
  void                         PushHead(const PointType& point);
  void                         PushTail(const PointType& point);
};

class Snake {
 private:
  SnakeBody body_;
  Direction dir_;

 public:
  Snake(const PointType& point_start, Direction dir);
  const std::deque<PointType> GetPositions() const;
  void                        ChangeDirection(const Direction new_dir);
  void                        Move();
  void                        Grow();
};

#endif