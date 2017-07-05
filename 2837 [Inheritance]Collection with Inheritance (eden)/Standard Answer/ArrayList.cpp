#include "ArrayList.hpp"
#include <algorithm>
ArrayList::ArrayList() {
  this->storage = new E[65536]();
  this->_size = 0;
  this->_maxsize = 65536;
}

void ArrayList::extend(void) {
  int new_size = _maxsize * extend_factor;
  E* new_storage = new E[new_size]();
  for (int i = 0; i < this->_size; i++) {
    new_storage[i] = this->storage[i];
  }
  delete[] storage;
  storage = new_storage;
  _maxsize = new_size;
}

ArrayList::~ArrayList() {
  if (storage != NULL) {
    delete[] storage;
  }
}

void ArrayList::add(E e) {
  if (this->_size + 1 > this->_maxsize) {
    extend();
  }
  storage[this->_size] = e;
  _size++;
}

void ArrayList::clear(void) {
  delete this->storage;
  storage = new E[16]();
  _size = 0;
  _maxsize = 16;
}

bool ArrayList::contain(E e) {
  for (int i = 0; i < this->_size; i++) {
    if (this->storage[i] == e) {
      return true;
    }
  }
  return false;
}

bool ArrayList::isEmpty(void) { return (this->_size == 0); }

void ArrayList::remove(E e) {
  for (int i = 0; i < this->_size;) {
    if (this->storage[i] == e) {
      for (int j = i + 1; j < this->_size; j++) {
        this->storage[j - 1] = this->storage[j];
      }
      this->_size--;
    } else {
        i++;
    }
  }
}

E& ArrayList::operator[](int index) { return this->storage[index]; }

E& ArrayList::get(int index) { return this->storage[index]; }

int ArrayList::indexOf(E element) {
  for (int i = 0; i < this->_size; i++) {
    if (this->storage[i] == element) {
      return i;
    }
  }
  return -1;
}

int ArrayList::size(void) { return this->_size; }

static void swap(int* a, int* b) {
  if (a != b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
  }
}

static int partion(int* A, int from, int to) {
  // A[to] is the pivot
  int i = from, j = from - 1;
  for (; i < to; i++) {
    if (A[i] < A[to]) {
      j++;
      swap(&A[i], &A[j]);
    }
  }
  swap(&A[j + 1], &A[to]);
  return j + 1;
}

/*
 static int random_partion(int * A, int from, int to) {
    int r = getRandeomNum(from, to);
    swap(&A[r], &A[to]);
    return partion(A, from, to);
}
*/

static void qsort(int* A, int from, int to) {
  if (to > from) {
    int middle = partion(A, from, to);
    qsort(A, from, middle - 1);
    qsort(A, middle + 1, to);
  }
}

void ArrayList::sort(void) { qsort(this->storage, 0, this->_size - 1); }

