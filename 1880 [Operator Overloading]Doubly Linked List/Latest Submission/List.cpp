#include "List.hpp"
#include <sstream>
using std::ostringstream;
typedef int data_type;
typedef list::node listNode;
typedef list::node* listPointer;
typedef unsigned int size_type;
list::list(): head(NULL), tail(NULL), _size(0) {}
list::list(const data_type array[], int length): head(NULL), tail(NULL), _size(0) {
  assign(array, length);
}
list::list(const list& source): head(NULL), tail(NULL), _size(0) {
  *this = source;
}
list& list::operator=(const list& source) {
  clear();
  listPointer ptr = source.head;
  int index = 0;
  while (ptr) {
    insert(index, ptr -> data);
    ++index;
    ptr = ptr -> next;
  }
  return *this;
}
list::~list() {
  clear();
}
bool list::empty(void) const {
  return !_size;
}
size_type list::size(void) const {
  return _size;
}
data_type& list::front(void) const {
  if (head)
    return head -> data;
  return *reinterpret_cast<data_type*>(NULL);
}
data_type& list::back(void) const {
  if (tail)
    return tail -> data;
  return *reinterpret_cast<data_type*>(NULL);
}
std::string list::toString(void) const {
  ostringstream s;
  if (!head)
    return std::string("NULL");
  s << "NULL<-";
  listPointer ptr = head;
  while (ptr) {
    s << ptr -> data;
    ptr = ptr -> next;
    if (ptr)
      s << "<->";
  }
  s << "->NULL";
  return s.str();
}
void list::assign(const list& source) {
  clear();
  *this = source;
}
void list::assign(const data_type datas[], int length) {
  clear();
  for (int index = 0; index < length; ++index) {
    insert(index, datas[index]);
  }
  _size = length;
}
void list::push_front(const data_type& data) {
  insert(0, data);
}
void list::push_back(const data_type& data) {
  if (_size)
    insert(_size - 1, data);
  else
    insert(0, data);
}
void list::pop_front(void) {
  if (head)
    erase(0);
}
void list::pop_back(void) {
  if (tail)
    erase(_size - 1);
}
void list::insert(int position, const data_type& data) {
  if (!position) {
    listPointer ptr = head;
    head = new listNode(data, ptr);
    if (!head -> next)
      tail = head;
    ++_size;
    return;
  }
  if (position <= _size) {
    listPointer father = at(position - 1);
    listPointer son = at(position);
    listPointer newnode = new listNode(data, son, father);
    if (father)
      father -> next = newnode;
    if (son)
      son -> prev = newnode;
    if (position == _size) {
      tail = newnode;
    }
    ++_size;
  }
}
void list::erase(int position) {
  if (!_size || position >= _size) {
    return;
  } else {
    listPointer ptr = at(position);
    if (!position) {
      head = head -> next;
      if (!head)
        tail = NULL;
    } else if (position == _size - 1) {
      tail = tail -> prev;
      tail -> next = NULL;
    } else {
      listPointer father = at(position - 1);
      listPointer son = at(position + 1);
      father -> next = son;
      if (son)
        son -> prev = father;
    }
    delete ptr;
    --_size;
  }
}
void list::clear(void) {
  listPointer ptr = head;
  while (ptr) {
    listPointer son = ptr -> next;
    delete ptr;
    ptr = son;
  }
  head = NULL;
  tail = NULL;
  _size = 0;
}
void list::split(int position, list* des1, list* dest2) {
  des1 -> clear();
  dest2 -> clear();
  listPointer temp = at(position);
  listPointer beg = head;
  int index = 0;
  while (beg != temp) {
    des1 -> insert(index, beg -> data);
    beg = beg -> next;
    ++index;
  }
  listPointer end = temp;
  index = 0;
  while (end) {
    dest2 -> insert(index, end -> data);
    end = end -> next;
    ++index;
  }
}
list& list::merge(const list& src1, const list& src2) {
  list temp = *this;
  temp.clear();
  listPointer ptr = src1.head;
  int index = 0;
  while (ptr) {
    temp.insert(index, ptr -> data);
    ++index;
    ptr = ptr -> next;
  }
  ptr = src2.head;
  while (ptr) {
    temp.insert(index, ptr -> data);
    ++index;
    ptr = ptr -> next;
  }
  *this = temp;
  return *this;
}
list& list::remove_if(bool (*condition)(listPointer)) {
  listPointer ptr = head;
  int index = 0;
  while (ptr) {
    listPointer old = ptr -> next;
    if (condition(ptr))
      erase(index);
    else
      ++index;
    ptr = old;
  }
  return *this;
}
list& list::unique(void) {
  if (_size == 0)
    return *this;
  int data[_size] = {0}, index = 0;
  for (listPointer ptr = head; ptr; ptr = ptr -> next) {
    int i;
    for (i = 0; i < index; ++i) {
      if (ptr -> data == data[i]) {
        break;
      }
    }
    if (i == index) {
      data[index] = ptr -> data;
      ++index;
    }
  }
  this -> assign(data, index);
  return *this;
}
list& list::reverse(void) {
  listPointer beg = head;
  listPointer end = tail;
  int index = 0;
  while (beg != end && index < (size() / 2)) {
    int temp = beg -> data;
    beg -> data = end -> data;
    end -> data = temp;
    end = end -> prev;
    beg = beg -> next;
    ++index;
  }
  return *this;
}
data_type& list::operator[](int index) {
  if (at(index))
    return at(index) -> data;
}
list& list::operator+=(const list& behind) {
  listPointer ptr = behind.head;
  int index = size();
  while (ptr) {
    insert(index, ptr -> data);
    ptr = ptr -> next;
    ++index;
  }
  return *this;
}
std::ostream& operator<<(std::ostream& os, const list& li) {
  os << li.toString();
  return os;
}