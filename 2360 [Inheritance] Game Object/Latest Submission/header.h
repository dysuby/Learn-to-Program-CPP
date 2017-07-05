#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;

typedef struct point {
  double x, y;
  point(double _x, double _y): x(_x), y(_y) {}
  point(const point& other): x(other.x), y(other.y) {}
} point; 

class gameobject {
  public:
    gameobject(point _pos, point _speed): 
      pos(_pos), speed(_speed), hp(10) {}
    int get_hp() {return hp;}
    virtual void select() = 0;
    virtual void move() = 0;
    void setHP(int i) {hp = i;}
  protected:
    point pos, speed;
    int hp;
};

class worker: public gameobject {
  public:
    worker(double x, double y): 
      gameobject(point(x, y), point(1, 1)) {}
    virtual void select() {
      cout << "Scv good to go, sir!" << endl;
    }
    virtual void move() {
      pos.x += speed.x;
      pos.y += speed.y;
      cout << "Worker moves to (" << pos.x
           << ", " << pos.y << ")" << endl;
    }
    void build(int h) {
      for (int i = 0; i < h; ++i) {
        for (int blank = 0; blank < h - i - 1; ++blank)
          cout << " ";
        for (int k = 0; k < 2 * i + 1; ++k)
          cout << "*";
        cout << endl;
      }
    }
    void repair(gameobject* tar) {
      tar -> setHP(10);
    }
};

class zealot: public gameobject {
  public:
    zealot(double x, double y): 
      gameobject(point(x, y), point(2, 2)) {}
    virtual void select() {
      cout << "My life for Aiur!" << endl;
    }
    virtual void move() {
      pos.x += speed.x;
      pos.y += speed.y;
      cout << "Zealot moves to (" << pos.x
           << ", " << pos.y << ")" << endl;
    }
    void attack(gameobject* tar) {
      tar -> setHP(tar -> get_hp() - 1);
    }
};

class tower: public gameobject {
  public:
    tower(double x, double y): 
      gameobject(point(x, y), point(0, 0)) {}
    virtual void select() {
      cout << "~" << endl;
    }
    virtual void move() {
      cout << "Tower cannot move." << endl;
    }
    void attack(gameobject* tar) {
      tar -> setHP(tar -> get_hp() - 1);
    }
};
#endif