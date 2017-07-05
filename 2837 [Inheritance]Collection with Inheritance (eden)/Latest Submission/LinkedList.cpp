 #include "LinkedList.hpp"
typedef LinkedList::node node;
typedef int E;

LinkedList::LinkedList(): head(NULL), tail(NULL), _size(0){}

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

node* Merge(node *head, node *mid) {
  node *temp = new node(0);
  node *current = temp;
  while (head && mid) {
    if (head -> data <= mid -> data) {
      current -> next = head;
      head -> prev = current;
      head = head -> next;
      if (head)
        head -> prev = NULL;
    }
    else {
      current -> next = mid;
      mid -> prev = current;
      mid = mid -> next;
      if (mid)
        mid -> prev = NULL;
    }
    current = current -> next;
  }
  if (mid) {
    current -> next = mid;
    mid -> prev = current;
  } else if (head) {
    current -> next = head;
    head -> prev = current;
  }
  node *p = temp;
  temp = temp -> next;
  delete p;
  return temp;
}

node* Mergesort(node *head) {
  if (head == NULL)
    return head;
  node *first(head);
  node *second(head);
  while (second -> next && second -> next -> next) {
    second = second -> next -> next;
    first = first -> next;
  }
  if (first -> next) {
    second = first -> next;
    second -> prev = NULL;
    first -> next = NULL;
    first = head;
  }
  if (first == second)
    return first;
  return Merge(Mergesort(first), Mergesort(second));
}

void LinkedList::sort() {
  if (_size == 0)
    return;
  head = Mergesort(head);
  tail = head;
  while (tail -> next)
    tail = tail -> next;
}

int LinkedList::size() {
  return _size;
}