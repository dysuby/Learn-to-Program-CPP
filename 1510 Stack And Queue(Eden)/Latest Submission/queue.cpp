#include "queue.hpp"
void queue::push(int element) {
  if (!isFull()) {
    storage[rear] = element;
    (rear == MAX_SIZE) ? rear = 0 : ++rear;
  }
}
void queue::pop(void) {
  if (!isEmpty()) {
    (head == MAX_SIZE) ? head = 0 : ++head;
  }
}
int queue::front(void) {
  if (isEmpty()) {
    return 0;
  }
  return storage[head];
}
int queue::back(void) {
  if (isEmpty()) {
    return 0;
  }
  return storage[rear ? rear - 1 : MAX_SIZE];
}
bool queue::isFull(void) {
  if (head - rear == 1 || rear - head == MAX_SIZE) 
    return true;
  return false;
}
bool queue::isEmpty(void) {
  if (rear == head) 
    return true;
  return false;
}
void queue::clear(void) {
  head = rear;
}