#include <iostream>
#include "source.h"
#define struct FORBIDDEN
using std::cin;
using std::cout;
using std::endl;

int main() {
  int data[6];
  for (int i = 0; i < 6; ++i)
    cin >> data[i];

  Vector vect1(data[0], data[1]);
  Vector vect2(data[2], data[3]);
  Point point1(data[4], data[5]);
  cout << vect1 << endl
       << vect2 << endl
       << point1 << endl;

  cout << endl;

  Vector vect3;
  Point point2;
  vect3 = vect1 + vect2;
  point2 = point1 + vect3 + vect1;
  cout << vect3 << endl
       << point2 << endl;
  return 0;
}
