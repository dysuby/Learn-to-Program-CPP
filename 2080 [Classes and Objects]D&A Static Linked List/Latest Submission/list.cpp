#include "list.hpp"
#include <iostream>
#include <sstream>
using namespace std;
const list::pointer list::nullpointer;
list::list(): head(nullpointer), empty_head(0), _size(0) {
  for (int index = 0; index < MAX_STORAGE; ++index) 
    storage[index].next = index + 1;
}
list::list(const list& another): head(nullpointer), empty_head(0), _size(0) {
  for (int index = 0; index < MAX_STORAGE; ++index) 
    storage[index].next = index + 1;
  *this = another;
}
list& list::operator=(const list& another) {
  clear();
  int i = 0;
  for (int index = another.head; index != -1; index = another.storage[index].next) {
    insert(i, another.storage[index].data);
    ++i;
  }
  return *this;
}
list::~list() {
  clear();
}
// Capacity
bool list::empty(void) const {
  return !_size;
}
list::size_type list::size(void) const {
  return _size;
}
// output
// list: [1,2,3,4,5]
// output: 1->2->3->4->5->NULL
string list::toString(void) const {
  ostringstream os;
  for (int index = head; index != -1; index = storage[index].next) {
    os << storage[index].data << "->";
  }
  os << "NULL";
  return os.str();
}
void list::insert(int position, const int& data) {
  if (_size < MAX_STORAGE && position <= _size) {
    int temp = empty_head;
    empty_head = storage[empty_head].next; 
    if (!position) {
      storage[temp] = node(data, head);
      head = temp;
    } else {
      int pre = head;
      for (int index = 0; index < position - 1; ++index) 
        pre = storage[pre].next;
      storage[temp] = node(data, storage[pre].next);
      storage[pre].next = temp;
    }
    ++_size;  
  }
}
void list::erase(int position) {
  if ( _size && position >= 0 && position <= _size) {
    int pre = head, newhead = head;
    if (position) {
      for (int index = 0; index < position - 1; ++index) 
        pre = storage[pre].next;
      int temp = storage[pre].next;
      storage[pre].next = storage[temp].next;
      newhead = temp;
    } else {
      head = storage[head].next;
    }
    storage[newhead].next = empty_head;
    empty_head = newhead;
    --_size;
  }
}
void list::clear(void) {
  for (int index = 0; index <= _size; ++index) 
    storage[index].next = index + 1;
  empty_head = 0;
  _size = 0;
  head = nullpointer;
}
list& list::sort(void) {
  for (int index = head; index != -1; index = storage[index].next) {
    for (int next = storage[index].next; next != -1; next = storage[next].next) {
      if (storage[index].data > storage[next].data) {
        int temp = storage[index].data;
        storage[index].data = storage[next].data;
        storage[next].data = temp;
      }
    }
  }
  return *this;
}