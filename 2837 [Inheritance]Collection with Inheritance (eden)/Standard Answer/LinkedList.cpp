#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList() : head(NULL), tail(NULL), _size(0) {}

LinkedList::~LinkedList() { this->clear(); }

void LinkedList::add(E e) {
  if (tail == NULL) {
    this->head = this->tail = new node(e);
  } else {
    this->tail->next = new node(e, NULL, tail);
    tail = tail->next;
  }
  this->_size++;
}

void LinkedList::clear(void) {
  node* p = this->head;
  while (p != NULL) {
    node* next = p->next;
    delete p;
    p = next;
  }
  this->head = this->tail = NULL;
  this->_size = 0;
}

bool LinkedList::contain(E e) {
  node* p = this->head;
  while (p != NULL) {
    if (p->data == e) {
      return true;
    }
    p = p->next;
  }
  return false;
}

bool LinkedList::isEmpty(void) { return this->_size == 0; }

void LinkedList::remove(E e) {
  node* p = this->head;
  while (p != NULL) {
    if (p->data != e) {
      p = p->next;
    } else {
      if (p == this->head) {
        this->head = this->head->next;
        if (this->head != NULL) {
          this->head->prev = NULL;
        }
        delete p;
        p = head;
      } else if (p == this->tail) {
        tail = tail->prev;
        tail->next = NULL;
        delete p;
        p = NULL;
      } else {
        p->next->prev = p->prev;
        p->prev->next = p->next;
        node* temp = p;
        p = p->next;
        delete temp;
      }
      this->_size--;
    }
  }
}

E& LinkedList::operator[](int index) { return this->get(index); }

E& LinkedList::get(int index) {
  node* p = this->head;
  int counter = 0;
  while (p != NULL) {
    if (counter == index) {
      return p->data;
    }
    counter++;
    p = p->next;
  }
  return *reinterpret_cast<E*>(NULL);
}

int LinkedList::indexOf(E element) {
  node* p = this->head;
  int index = 0;
  while (p != NULL) {
    if (p->data == element) {
      return index;
    } else {
      p = p->next;
      index++;
    }
  }
  return -1;
}

int LinkedList::size(void) {
  return this->_size;
}

void LinkedList::sort(void) {
  if (this->size() > 1) {
    node* fast = this->head;
    node* slow = this->head;
    LinkedList li_left;
    LinkedList li_right;

    li_left.head = this->head;
    while (fast != NULL && fast->next != NULL) {
      li_left._size++;
      fast = fast->next->next;
      slow = slow->next;
    }
    li_left.tail = slow->prev;
    li_left.tail->next = NULL;

    li_right.head = slow;
    li_right.head->prev = NULL;
    li_right.tail = this->tail;
    li_right._size = this->_size - li_left._size;

    this->head = NULL;
    this->tail = NULL;

    li_left.sort();
    li_right.sort();

    node* pointer_left = li_left.head;
    node* pointer_right = li_right.head;

    node* pointer_head = NULL;
    node* pointer_tail = NULL;

    while (pointer_left != NULL && pointer_right != NULL) {
      node* temp;
      if (pointer_left->data <= pointer_right->data) {
        temp = pointer_left;
        pointer_left = pointer_left->next;
      } else {
        temp = pointer_right;
        pointer_right = pointer_right->next;
      }
      if (pointer_head == NULL) {
        pointer_head = pointer_tail = temp;
      } else {
        pointer_tail->next = temp;
        temp->prev = pointer_tail;
        pointer_tail = temp;
      }
      pointer_head->prev = NULL;
      pointer_tail->next = NULL;
    }

    while (pointer_left != NULL) {
      pointer_tail->next = pointer_left;
      pointer_left->prev = pointer_tail;
      pointer_tail = pointer_left;
      pointer_left = pointer_left->next;
    }

    while (pointer_right != NULL) {
      pointer_tail->next = pointer_right;
      pointer_right->prev = pointer_tail;
      pointer_tail = pointer_right;
      pointer_right = pointer_right->next;
    }

    this->head = pointer_head;
    this->tail = pointer_tail;

    li_left.head = li_left.tail = NULL;
    li_right.head = li_right.tail = NULL;
  }
}

