#ifndef SOURCE_H
#define SOURCE_H
#include <iostream>
using namespace std;

class Vector {
  public:
    Vector(int x = 0, int y = 0): x_(x), y_(y) {}
  		Vector operator+(Vector &oth) {
        return Vector(x_ + oth.x_, y_ + oth.y_);
    	}
  		friend ostream& operator<<(ostream &os, Vector vec) {
        os << vec.x_ << " " << vec.y_;
        return os;
      }
  		int getX() {return x_;}
  		int getY() {return y_;}
  private:
  		int x_, y_;
};

class Point {
  public:
  		Point(int x = 0, int y = 0): x_(x), y_(y) {}
  		Point operator+(Vector &rhs) {
        return Point(x_ + rhs.getX(), y_ + rhs.getY());
      }
  		friend ostream& operator<<(ostream &os, Point poi) {
        os << poi.x_ << " " << poi.y_;
        return os;
      }
  private:
  		int x_, y_;
};

#endif