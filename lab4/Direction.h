/*
 * direction.h
 */

 // 1.
#ifndef DIRECTION_H
#define DIRECTION_H

#include <ostream>
#include <stdexcept>

enum Direction { Up, Down, Left, Right };

// 2.
std::ostream& operator<<(std::ostream& os, const Direction& dir);

// 4.
class bad_direction : public std::logic_error
{
public:
   explicit bad_direction(const std::string& what_arg)
      : std::logic_error(what_arg) {}
   explicit bad_direction(const char* what_arg)
      : std::logic_error(what_arg) {}
};

#endif /* DIRECTION_H */
