#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <list>
#include "global.hpp"

class snake {
  std::list<point> body;

 public:
  snake(point& head) { body.push_back(head); }
  const std::list<point>& getBody(void) const { return body; }
  void move(direction d) {
    point head = body.front();
    body.push_front(head.move(d));
    body.pop_back();
  }
  void eat(point& food) { body.push_front(food); }
};

#endif  // !_SNAKE_H_

