#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include "global.hpp"
using std::vector;
class snake {
  private:
    point head;
    vector<point> body;
  public:
    snake(point _head): head(_head) {}
    ~snake() {}
    void move(const point& newhead, bool ate);
    point gethead();
    const vector<point>& getbody();
};
void snake::move(const point& newhead, bool ate) {
  point temp(head);
  head = newhead;
  if (body.size()) { 
    if (!ate)
      body.pop_back();
    body.insert(body.begin(), temp);
  } else if (ate) {
    body.insert(body.begin(), temp);
  }
}
point snake::gethead() {
  return head;
}
const vector<point>& snake::getbody() {
  return body;
}
#endif