 #ifndef POINTER_H
#define POINTER_H
#include <iostream>
using namespace std; 
class Point {
private:
    int *data;
    int dimension;
public:
    Point(int dim): dimension(dim), data(NULL) {
      if (dim == 0)
        return;
      data = new int[dim];
      for (int index = 0; index < dim; ++index)
        data[index] = 0;
    }
    Point(int* temp, int dim): dimension(dim), data(NULL) {
      if (dim == 0)
        return;
      data = new int[dim];
      for (int index = 0; index < dim; ++index)
        data[index] = temp[index];
    }
    Point operator+(const Point& oth) {
      int min = dimension < oth.dimension ? dimension : oth.dimension;
      int max = dimension > oth.dimension ? dimension : oth.dimension;
      Point res(max);
      int index;
      for (index = 0; index < min; ++index)
        res.data[index] = data[index] + oth.data[index];
      for ( ; index < max; ++index)
        if (min == dimension)
          res.data[index] = oth.data[index];
        else
          res.data[index] = data[index];
      return res;
    }
    Point operator-(const Point& oth) {
      int min = dimension < oth.dimension ? dimension : oth.dimension;
      int max = dimension > oth.dimension ? dimension : oth.dimension;
      Point res(max);
      int index;
      for (index = 0; index < min; ++index)
        res.data[index] = data[index] - oth.data[index];
      for ( ; index < max; ++index)
        if (min == dimension)
          res.data[index] =  -oth.data[index];
        else
          res.data[index] = data[index];
      return res;
    }
    Point& operator=(const Point& oth) {
      Point temp(oth.data, oth.dimension);
      delete data;
      dimension = temp.dimension;
      data = new int[dimension];
      for (int index = 0; index < dimension; ++index)
        data[index] = temp.data[index];
    }
    void print() {
      if (dimension == 0)
        return;
      cout << "(" << data[0];
      for (int index = 1; index < dimension; ++index)
        cout << "," << data[index];
      cout << ")" << endl;
    }
    ~Point() {
      delete[] data;
    }
};
#endif