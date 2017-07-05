#include "list.hpp"
#include <string>
#include <sstream>
#include <assert.h>
 list::list() { this->clear(); }
 list::list(const list& another) { *(this) = another; }
 list::~list() {}
 list& list::operator=(const list& another) {
  this->clear();
  for (int i = 0; i < MAX_STORAGE; i++) {
    storage[i] = another.storage[i];
  }
  this->head = another.head;
  this->empty_head = another.empty_head;
  this->_size = another._size;
  return *(this);
}
 bool list::empty(void) const { return this->_size == 0; }
 list::size_type list::size(void) const { return this->_size; }
 std::string list::toString(void) const {
  pointer p = this->head;
  std::string ret;
  while (p != nullpointer) {
    std::stringstream ss;
    ss << this->storage[p].data;
    ret += ss.str();
    ret += "->";
    p = this->storage[p].next;
  }
  ret += "NULL";
  return ret;
}
 void list::insert(int position, const int& data) {
  if (position >= 0 && position <= this->_size) {
    if (this->_size + 1 <= MAX_STORAGE) {
      pointer freeNode = empty_head;
      empty_head = storage[empty_head].next;
      storage[freeNode].data = data;
      if (position == 0) {
        storage[freeNode].next = head;
        head = freeNode;
      } else {
        pointer p = head;
        for (int i = 0; i < position - 1; i++) {
          p = storage[p].next;
        }
        storage[freeNode].next = storage[p].next;
        storage[p].next = freeNode;
      }
      this->_size++;
    }
  }
}
 void list::erase(int position) {
  if (position >= 0 && position < this->_size) {
    if (position == 0) {
      pointer temp = head;
      head = storage[head].next;
      storage[temp].next = empty_head;
      empty_head = temp;
    } else {
      pointer p = head;
      for (int i = 0; i < position - 1; i++) {
        p = storage[p].next;
      }
      pointer temp = storage[p].next;
      assert(storage[p].next != nullpointer);
      storage[p].next = storage[storage[p].next].next;
      storage[temp].next = empty_head;
      empty_head = temp;
    }
    this->_size--;
  }
}
 void list::clear(void) {
  this->head = nullpointer;
  this->_size = 0;
  this->empty_head = 0;
  for (int i = 0; i < MAX_STORAGE - 1; i++) {
    storage[i].next = i + 1;
  }
  storage[MAX_STORAGE - 1].next = nullpointer;
}
 list& list::sort(void) {
  if (this->head != nullpointer && this->storage[head].next != nullpointer) {
    pointer slow = head;
    pointer fast = storage[head].next;
    while (fast != nullpointer) {
      if (storage[fast].data >= storage[slow].data) {
        fast = storage[fast].next;
        slow = storage[slow].next;
      } else {
        pointer pre = this->head;
        if (storage[head].data > storage[fast].data) {
          storage[slow].next = storage[fast].next;
          storage[fast].next = this->head;
          this->head = fast;
        } else {
          while (storage[storage[pre].next].data <= storage[fast].data) {
            pre = storage[pre].next;
          }
          storage[slow].next = storage[fast].next;
          storage[fast].next = storage[pre].next;
          storage[pre].next = fast;
        }
        fast = storage[slow].next;
      }
    }
  }
  return *(this);
}
 