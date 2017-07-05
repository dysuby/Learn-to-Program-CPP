#include "LinkedList.hpp"
typedef int E;

LinkedList::LinkedList(): head(NULL), tail(NULL), _size(0) {}

LinkedList::~LinkedList() {
  clear();
}

void LinkedList::add(E e) {
  if (head == NULL) {
    head = new node(e);
    tail = head;
  } else {
    tail -> next = new node(e, NULL, tail);
    tail = tail -> next;
  }
  ++_size;
}

void LinkedList::remove(E e) {
  if (head == NULL || !contain(e))
    return;
  node *prev = NULL, *current = head, *next = current -> next;
  while (current) {
    if (current -> data == e) {
      if (next)
        next -> prev = prev;
      else
        tail = prev;
      if (prev)
        prev -> next = next;
      else
        head = next;
      delete current;
      --_size;
    } else {
      prev = current;
    }
    current = next;
    if (next)
      next = next -> next;
  }
}

void LinkedList::clear() {
  node *current = head;
  while (current) {
    node *temp = current;
    current = current -> next;
    delete temp;
  }
  head = NULL;
  tail = NULL;
  _size = 0;
}

bool LinkedList::contain(E e) {
  return (indexOf(e) != -1);
}

bool LinkedList::isEmpty() {
  return !_size;
}

E& LinkedList::operator[](int index) {
  return get(index);
}

E& LinkedList::get(int index) {
  if (index >= _size) {
    return *reinterpret_cast<E*>(NULL);
  }
  node *current = head;
  for (int i = 0; i < index; ++i) {
    current = current -> next;
  }
  return current -> data;
}

int LinkedList::indexOf(E element) {
  node *next_current = head;
  for (int index = 0; index < _size; ++index) {
    if (next_current -> data == element)
      return index;
    else
      next_current = next_current -> next;
  }
  return -1;
}

int LinkedList::size() {
  return _size;
}