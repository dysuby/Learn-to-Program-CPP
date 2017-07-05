#include "SimpleList.hpp"
#include <cstdio>
#include <cstring>
list::list() {
  head = NULL;
  _size = 0;
}
list::list(const list& source) {
  _size = source._size;
  head = new node(source.head -> data);
  node *newnode = head, *oldnode = source.head -> next;
  while (oldnode) {
    newnode -> next = new node(oldnode -> data);
    newnode = newnode -> next;
    oldnode = oldnode -> next;
  }
}
list& list::operator=(const list& source) {
  clear();
  _size = source._size;
  head = new node(source.head -> data);
  node *newnode = head, *oldnode = source.head -> next;
  while (oldnode) {
    newnode -> next = new node(oldnode -> data);
    newnode = newnode -> next;
    oldnode = oldnode -> next;
  }
  return *this;
}
list::~list() {
  clear();
}
bool list::empty(void) const {
  return _size;
}
int list::size(void) const {
  return _size;
}
std::string list::toString(void) const {
  std::string str = "";
  node* index = head;
  char temp[10] = {0};
  while (index) {
    memset(temp, 0, 10 * sizeof(char));
    snprintf(temp, 10 * sizeof(char), "%d->", index -> data);
    str += temp;
    index= index -> next;
  }
  str += "NULL";
  return str;
}
void list::insert(int position, const int& data) {
  if (position > _size) {
    return;
  } else if (position == 0){
    node *newnode = head;
    head = new node(data, newnode);
    ++_size;
    return;
  }
  node *father = head;
  for (int index = 0; index < position - 1; ++index) {
    father = father -> next;
  }
  node *son = father -> next;
  father -> next = new node(data, son);
  ++_size;
}
void list::erase(int position) {
  if (position >= _size) {
    return;
  } else if (position == 0){
    node *newnode = head;
    head = head -> next;
    delete newnode;
    --_size;
    return;
  }
  node *father = head;
  for (int index = 0; index != position - 1; ++index) {
    father = father -> next;
  }
  node *son = father -> next;
  father -> next = son -> next;
  delete son;
  --_size;
}
list& list::sort() {
  for (node *index = head; index; index = index -> next) {
    for (node *kindex = index -> next; kindex; kindex = kindex -> next) {
      if (index -> data > kindex -> data) {
        int temp = index -> data;
        index -> data = kindex -> data;
        kindex -> data =temp;
      }
    }
  }
  return *this;
}