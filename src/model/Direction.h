#ifndef DIRECTION_H
#define DIRECTION_H

#include <array>
#include "Delta.h"

enum class Direction { UP, DOWN, LEFT, RIGHT };
constexpr std::array<Delta, 4> MoveDir = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};


#endif