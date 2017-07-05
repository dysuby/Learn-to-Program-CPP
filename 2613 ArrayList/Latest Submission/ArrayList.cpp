 #include "ArrayList.hpp"
typedef int E;
ArrayList::ArrayList(): _size(0), _maxsize(0), storage(NULL) {}
ArrayList::~ArrayList() {
  clear();
}
  void ArrayList::add(E e) {
    if (_size == _maxsize)
      extend();
    storage[_size] = e;
    ++_size;
  }
  void ArrayList::remove(E e) {
    int *res = new int[_maxsize];
    int i = 0;
    for (int index = 0; index < _size; ++index) {
      if (storage[index] != e) {
        res[i] = storage[index];
        ++i;
      }
    }
    clear();
    storage = res;
    _size = i;
  }
  void ArrayList::clear() {
    delete[] storage;
    storage = NULL;
    _size = 0;
  }

  bool ArrayList::contain(E e) {
    int index = 0;
    for ( ; index < _size; ++index) {
      if (storage[index] == e)
        return true;
    }
    return false;
  }
  bool ArrayList::isEmpty() {
    return !_size;
  }
  E& ArrayList::operator[](int index) {
    return get(index);
  }
  E& ArrayList::get(int index) {
    if (index >= 0 && index < _size)
      return storage[index];
  }
  int ArrayList::indexOf(E element) {
    int index = 0;
    for ( ; index < _size; ++index) {
      if (storage[index] == element)
        return index;
    }
    return -1;
  }
  int ArrayList::size() {
    return _size;
  }
  void ArrayList::extend() {
    if (_maxsize == 0)
      _maxsize = 1;
    else
      _maxsize *= extend_factor;
    int *temp = new int[_maxsize];
    int index = 0;
    for ( ; index < _size; ++index) {
      temp[index] = storage[index];
    }
    clear();
    _size = index;
    storage = temp;
  }