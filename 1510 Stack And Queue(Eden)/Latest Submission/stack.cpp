#include "stack.hpp"
void stack::push(int element) {
  if (!isFull()) {
    storage[++top] = element;
  }
}
void stack::pop(void) {
  if (!isEmpty()) {
    --top;
  }
}
int stack::peek(void) {
  if (!isEmpty())
    return storage[top];
  return -1;
}
bool stack::isEmpty(void) {
  if (top == -1)
    return true;
  return false;
}
bool stack::isFull(void) {
  if (top == MAX_SIZE - 1) 
    return true;
  return false;
}
void stack::clear(void) {
  top = -1;
}