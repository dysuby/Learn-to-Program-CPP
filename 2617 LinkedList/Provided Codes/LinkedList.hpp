#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_
#include <iostream>
typedef int E;

class LinkedList {
public:
  typedef struct node {
    E data;
    struct node* next;
    struct node* prev;
    node(E data, struct node* next = NULL, struct node* prev = NULL)
        : data(data), next(next), prev(prev) {}
  } node;
  LinkedList();
  ~LinkedList();

  void add(E e);
  void remove(E e);
  void clear();

  bool contain(E e);
  bool isEmpty();
  E& operator[](int index);
  E& get(int index);
  int indexOf(E element);
  int size();

private:
  node* head;
  node* tail;
  int _size;
};

#endif
