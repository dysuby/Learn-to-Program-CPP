 #ifndef LIST_HPP
#define LIST_HPP
#include "Collection.hpp"
#include <iostream>
using namespace std;

class List: public Collection {
public:
  virtual int& get(int index) = 0;
  virtual int& operator[](int index) = 0;
  virtual int indexOf(int e) = 0;
  virtual void sort() = 0;
  virtual ~List() {}
};
#endif