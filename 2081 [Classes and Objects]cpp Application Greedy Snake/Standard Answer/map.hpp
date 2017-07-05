#ifndef _MAP_H_
#define _MAP_H_

#include "global.hpp"
#include "snake.hpp"
#include <iostream>
#include <sstream>

// class randomGenerator {
// public:
//     static int getRandomNumber(int from, int to) {
// #include <cstdlib>
// #include <cstdio>
//         srand(0);
//         return rand() % (to - from) + from;
//     }
//#include <string>
//    static std::string getRandomString(std::string src, int length) {
//        return "";
//    }
//    static double getRandomFloatNumber(double from, double to) {
//        return 0.0;
//    }
//    static int getRandomNumber(int from, int to) {
//        int n;
//        std::cin >> n;
//        return n / (to - from + 1) + from;
//    }
// };

#define MAX_SIZE 15

class map {
 private:
  snake player;
  std::list<point> foods;
  point size;
  direction last_direction;
  bool gameOver;
  char wrap[MAX_SIZE][MAX_SIZE];

 public:
  map(point& size, point& player_position, std::list<point>& foods)
      : player(player_position) {
    this->size = size;
    this->foods = foods;
    last_direction = freeze;
    gameOver = false;
    this->update();
  }
  ~map() {}

 public:
  bool isGameOver(void) { return gameOver; }
  // movement
  bool move(direction d) {
    point food = check_food(d);
    if (food.x != -1 && food.y != -1) {
      player.eat(food);
      this->update();
      return true;
    }
    if (d == freeze) {
      d = last_direction;
    }
    player.move(d);
    last_direction = d;
    if (!check_collison()) {
      gameOver = true;
      return false;
    }
    this->update();
    return true;
  }
  void print(void) {
    for (int i = 0; i < size.x; i++) {
      for (int j = 0; j < size.y; j++) {
        std::cout << wrap[i][j];
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

 protected:
  void update(void) {
    for (int i = 0; i < size.x; i++) {
      for (int j = 0; j < size.y; j++) {
        // can we use memset here?
        wrap[i][j] = EMPTY;
      }
    }
    std::list<point>::const_iterator it = player.getBody().begin();
    // print head
    wrap[it->x][it->y] = HEAD;
    it++;
    for (; it != player.getBody().end(); it++) {
      wrap[it->x][it->y] = BODY;
    }
    for (it = foods.begin(); it != foods.end(); it++) {
      wrap[it->x][it->y] = FOOD;
    }
  }

  // void produce_food();

  point check_food(direction d) {
    std::list<point>::iterator it = foods.begin();
    point new_head = player.getBody().front();
    new_head.move(d);
    point ret(-1, -1);
    for (it; it != foods.end(); it++) {
      if (*it == new_head) {
        ret = *it;
        foods.erase(it);
        return ret;
      }
    }
    return ret;
  }

  bool check_collison(void) const {
    const std::list<point> body = player.getBody();
    const point& head = body.front();
    // check wall collision
    if (head.x < 0 || head.x >= size.x || head.y < 0 || head.y >= size.y) {
      return false;
    }
    // check body collision
    std::list<point>::const_iterator it = body.begin();
    // skip head
    it++;
    for (; it != body.end(); it++) {
      if (*it == head) {
        return false;
      }
    }
    return true;
  }
};
#endif  // !_MAP_H_

