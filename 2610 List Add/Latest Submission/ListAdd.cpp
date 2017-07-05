#include "ListAdd.hpp"
#include <string>
#include <cstdio>
using std::string;
using std::endl;

List::List(): head(NULL), _size(0) {}
List::List(const List& other): head(NULL) {
  _size = other._size;
  if (_size == 0)
    return;
  head = new node(other.head -> val, NULL);
  node* now = head;
  for (node *oth = other.head -> next; oth; oth = oth -> next) {
    now -> next = new node(oth -> val);
    now = now -> next;
  }
}
List::List(const string & num): head(NULL) {
  _size = num.size();
  if (_size == 0)
    return;
  for (int index = 0; index < _size; ++index) {
    push_front(num[index] - '0');
  }
}
void List::clear() {
  node* now = head;
  while (now) {
    node *prev = now;
    now = now -> next;
    delete prev;
  }
  head = NULL;
  _size = 0;
}
void List::push_front(int val) {
  node* newhead = new node(val, head);
  head = newhead;
}
List List::operator+(const List& other) {
  List res(*this);
  int pos = 0;
  node *lhs = res.head, *rhs = other.head, *father = lhs;
  for ( ; rhs && lhs; lhs = lhs -> next) {
    father = lhs;
    lhs -> val = (lhs -> val + pos + rhs -> val);
    pos = lhs -> val / 10;
    lhs -> val %= 10;
    rhs = rhs -> next;
  }
  if (lhs == NULL && rhs) {
    father -> next = new node(0);
    father = father -> next;
    ++res._size;
  }
  while (rhs == NULL && lhs) {
    lhs -> val = (lhs -> val + pos);
    pos = lhs -> val / 10;
    lhs -> val %= 10;
    father = lhs;
    lhs = lhs -> next;
  }
  while (rhs) {
    if (father -> next == NULL && rhs -> next) {
      father -> next = new node(0);
      lhs = father -> next;
      ++res._size;
    }
    father -> val = (father -> val + pos + rhs -> val);
    pos = father -> val / 10;
    father -> val %= 10;
    rhs = rhs -> next;
    father = lhs;
  }
  if (pos) {
    ++res._size;
    father -> next = new node(pos);
  }
  return res;
}    //在这里进行链表加法实现
List& List::operator=(const List& other) {
  List temp(other);
  clear();
  _size = temp._size;
  head = new node(temp.head -> val, NULL);
  node* now = head;
  for (node *oth = temp.head -> next; oth; oth = oth -> next) {
    now -> next = new node(oth -> val);
    now = now -> next;
  }
  return *this;
}  // 赋值操作重载
int List::size() const {
  return _size;
}
List::~List() {
  clear();
}
ostream& operator<<(ostream & os, const List &  out) {
  string res;
  for (List::node *now = out.head; now; now = now -> next) {
    char temp[10] = {0};
    snprintf(temp, 9, "%d", now -> val);
    res = string(temp) + res;
  }
  os << res;
  return os;
}