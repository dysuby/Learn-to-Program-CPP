#include "queue.hpp"
#include <cstring>
typedef int E;

queue::queue(): storage(0), max_size(MAX_SIZE + 1), head(0), rear(0) {
  storage = new int[max_size];
  memset(storage, 0, max_size * sizeof(int));
}

queue::~queue() {
  clear();
  delete[] storage;
}

void queue::clear() {
  memset(storage, 0, max_size * sizeof(int));
  head = 0;
  rear = 0;
}

void queue::push(E ele) {
  if (!isFull()) {
    if (rear == max_size - 1)
      rear = 0;
    storage[rear] = ele;
    if (rear < max_size - 1)
      ++rear;
    else
      rear = 0;
  }
}

void queue::pop() {
  if (!isEmpty()) {
    if (head == max_size - 1)
      head = 0;
    storage[head] = 0;
    if (head < max_size - 1)
      ++head;
    else
      head = 0;
  }
}

E queue::front() {
  if (!isEmpty())
    return storage[head];
  return 0;
}

E queue::back() {
  if (!isEmpty())
    return storage[rear - 1];
  return 0;
}

bool queue::isFull() {
  return (head - rear == 1) || (rear - head == MAX_SIZE);
}

bool queue::isEmpty() {
  return (rear == head);
}