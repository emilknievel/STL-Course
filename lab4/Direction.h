/*
 * direction.h
 */

 // 1.
#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>

enum Direction { Up, Down, Left, Right };

// 2.
std::ostream& operator<<(std::ostream& os, const Direction& dir);

#endif /* DIRECTION_H */
