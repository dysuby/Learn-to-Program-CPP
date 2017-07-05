#include "array.hpp"
typedef int* pointer;
typedef unsigned int size_t;
typedef int data_type;
array::array(size_t size) {
  _size = size;
  _data = new int[_size];
}
array::~array() {
  delete[] _data;
  _size = 0;
}
size_t array::max_size() {
  return _size;
}
data_type& array::at(const data_type& i) {
  return *(_data + i);
}
data_type& array::front() {
  return *_data;
}
data_type& array::back() {
  return *(_data + _size - 1);
}
pointer array::data() {
  return _data;
}
void array::fill(const data_type& value) {
  for (size_t index = 0; index < _size; ++index) {
    *(_data + index) = value;
  }
}
void array::resize(int newSize) {
  pointer datatemp = new int[newSize];
  for (int index = 0; index < _size; ++index) {
    *(datatemp + index) = *(_data + index);
  }
  delete[] _data;
  _data = new int[newSize];
  for (int index = 0; index < _size; ++index) {
    *(_data + index) = *(datatemp + index);
  }
  delete[] datatemp;
  _size = newSize;
}
void array::sort(int from, int to) {
  for (int index = from; index < to; ++index) {
    for (int index_ = index + 1; index_ < to; ++index_) {
      data_type temp;
      if (*(_data + index) > *(_data + index_)) {
        temp = *(_data + index);
        *(_data + index) = *(_data + index_);
        *(_data + index_) = temp;
      }
    }
  }
}