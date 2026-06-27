#include "Snake.h"



SnakeBody::SnakeBody(const PointType& point_start) {
  positions_.push_back(point_start);
}

void SnakeBody::PushHead(const PointType& point) {
  positions_.push_front(point);
}

PointType SnakeBody::PopTail() {
  PointType tail = positions_.back();
  positions_.pop_back();
  return tail;
}

const PointType& SnakeBody::GetHead() const {
  return positions_.front();
}

const std::deque<PointType>& SnakeBody::GetPositions() const {
  return positions_;
}


Snake::Snake(const PointType& point_start, Direction dir)
    : body_(SnakeBody(point_start)), dir_(dir) {}

const std::deque<PointType> Snake::GetPositions() const {
  return body_.GetPositions();
}

void Snake::ChangeDirection(const Direction new_dir) {
  if ((static_cast<int>(dir_) ^ 1) == static_cast<int>(new_dir))
    return;
  dir_ = new_dir;
}

void Snake::Move() {
  body_.PopTail();
  PointType new_head  = body_.GetHead();
  new_head.x         += MoveDir[static_cast<int>(dir_)].dx;
  new_head.y         += MoveDir[static_cast<int>(dir_)].dy;
  body_.PushHead(new_head);
}

void Snake::Grow() {
  PointType new_head  = body_.GetHead();
  new_head.x         += MoveDir[static_cast<int>(dir_)].dx;
  new_head.y         += MoveDir[static_cast<int>(dir_)].dy;
  body_.PushHead(new_head);
}