#include "List.hpp"

CycleList::CycleList(const vector<string> &food): _size(food.size()) {
  if (_size == 0)
    return;
  head = new node(food[0]);
  node *current = head;
  for (int index = 1; index < _size; ++index) {
    current -> next = new node(food[index], 0, current);
    current = current -> next;
  }
  current -> next = head;
  head -> front = current;
}

void CycleList::Eat() {
  Eat(0);
}  // remove head, head->front,head->next

void CycleList::Eat(int pos) {
  if (pos >= _size) {
    return;
  }
  else if (_size <= 3) {
    clear();
  } else {
    node *current = head;
    for (int index = 0; index < pos; ++index)
      current = current -> next;
    node *newhead = current -> next -> next;
    node *newtail = current -> front -> front;
    delete current -> next;
    delete current -> front;
    delete current;
    if (pos < 2 || pos > _size - 2)
      head = newhead;
    _size -= 3;
    if (_size >= 2) {
      newhead -> front = newtail;
      newtail -> next = newhead;
    } else if (_size == 1) {
      head -> next = NULL;
      head -> front = NULL;
    }
  }
} // remove pos, pos->next,pos->front

int CycleList::size() const {
  return _size;
}

void CycleList::clear() {
  for (int index = 0; index < _size; ++index) {
    node *temp = head;
    head = head -> next;
    delete temp;
  }
  head = NULL;
  _size = 0;
}

CycleList::~CycleList() {
  clear();
}

ostream& operator<<(ostream &os, const CycleList &tar) {
  CycleList::node *current = tar.head;
  for (int index = 0; index < tar._size; ++index) {
    os << current -> food << " ";
    current = current -> next;
  }
  return os;
}
