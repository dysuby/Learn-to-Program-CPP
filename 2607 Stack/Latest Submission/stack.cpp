#include "stack.hpp"
#include <iostream>
typedef int E;

stack::~stack() {
  delete[] storage;
  storage = NULL;
}

void stack::push(E ele) {
  if (size < max_size) {
    storage[size] = ele;
    ++size;
  }
}

void stack::pop() {
  if (size != 0)
    --size;
}

E stack::top() {
  if (size != 0)
    return storage[size - 1];
  return 0;
}
bool stack::isEmpty() {
  return !size;
}

bool stack::isFull() {
  return size == max_size;
}

void stack::clear() {
  size = 0;
}