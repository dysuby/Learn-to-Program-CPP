#ifndef MAP_H
#define MAP_H
#include "global.hpp"
#include "snake.hpp"
#include <list>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define body player.getbody()
using std::list;
using std::cout;
using std::string;
using std::vector;
using std::endl;
class map {
  private:
    point size;
    snake player;
    list<point> foods;
    bool gameover;
  public:
    map(point _size, point head, list<point> _foods): size(_size), 
    player(head), foods(_foods), gameover(true) {}
    ~map() {}
    void print();
    void move(direction action);
    bool isGameOver();
};
void map::print() {
  string _map[size.x];
  for (int x_index = 0; x_index < size.x; ++x_index) {
    for (int y_index = 0; y_index < size.y; ++y_index) {
      point temp(x_index, y_index);
      if (find(foods.begin(), foods.end(), temp) != foods.end())
        _map[x_index] += FOOD;
      else if (player.gethead() == temp)
        _map[x_index] += HEAD;
      else if (find(body.begin(), body.end(), temp) != body.end())
        _map[x_index] += BODY;
      else
        _map[x_index] += EMPTY;
    }
    cout << _map[x_index] << endl;
  }
  cout << endl;
}
void map::move(direction action) {
  point temp(player.gethead());
  temp.move(action);
  if (temp.x < 0 || temp.y < 0 ||
      temp.y >= size.y || temp.x >= size.x ||
      (find(body.begin(), body.end(), temp) != body.end() &&
        ++find(body.begin(), body.end(), temp) != body.end())) {
    gameover = false;
  }
  else if (find(foods.begin(), foods.end(), temp) != foods.end()) {
    auto found = find(foods.begin(), foods.end(), temp);
    player.move(temp, true);
    foods.erase(found);
  }
  else {
    player.move(temp, false);
  }
}
bool map::isGameOver() {
  return !gameover;
}
#endif