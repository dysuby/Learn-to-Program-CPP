#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "Collection.hpp"

class List : virtual public Collection {
 public:
  List() {}
  virtual ~List() {}
  virtual E& operator[](int index) = 0;
  virtual E& get(int index) = 0;
  virtual int indexOf(E element) = 0;
  virtual void sort(void) = 0;
};

#endif

