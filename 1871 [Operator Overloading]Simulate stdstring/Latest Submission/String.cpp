#include "String.h"
#include <cstring>
char String::_error_sign = 'N';
String::String() {
  _buff = NULL;
  _length = 0;
  _size = 0;
}
String::String(const char *src) {
  _size = strlen(src) + 1;
  _buff = new char[_size];
  memset(_buff, 0, _size);
  for (_length = 0; _length < _size; ++_length) 
    _buff[_length] = src[_length];
  --_length;
}
String::String(const String &src) {
  _size = src._size;
  _length = src._length;
  _buff = new char[_size];
  memset(_buff, 0, _size);
  for (int index = 0; index < _size; ++index) 
    _buff[index] = src._buff[index];
}
String::~String() {
  delete[] _buff;
  _size = 0;
  _length = 0;
}
void String::assign(const char *src) {
  int size = strlen(src) + 1;
  if (size > _size) {
    delete[] _buff;
    _buff = new char[size];
    memset(_buff, 0, size);
    _size = size;
    _length = size - 1;
    for (int index = 0; index < _size; ++index) 
      _buff[index] = src[index];
  } else {
    _length = size - 1;
    memset(_buff, 0, _size);
    for (int index = 0; index < size; ++index)
      _buff[index] = src[index];
  }
}
void String::append(const char &other) {
  if (_length + 1 >= _size) {
    char *temp = new char[++_size];
    memset(temp, 0, _size);
    for (int index = 0; index <= _length; ++index) 
      temp[index] = _buff[index];
    temp[_length] = other;
    delete[] _buff;
    _buff = temp;
    ++_length;
  } else {
    ++_length;
    _buff[_length - 1] = other;
    _buff[_length] = '\0';
  }
}
void String::clear() {
  memset(_buff, 0, _size);
  _length = 0;
}
int String::compare(const String &other) const {
  for (int index = 0; index <= _length && index <= other._length; ++index) {
    if (_buff[index] > other._buff[index]) 
      return 1;
    else if (_buff[index] < other._buff[index])
      return -1;
  }
  if (_length < other._length)
    return -1;
  else if (_length > other._length)
    return 1;
  return 0;
}
const char* String::c_str() const {
  return _buff;
}
bool String::empty() const {
  return !_length;
}
int String::find(const String &other, int pos) const {
  for (int index = pos; index <= _length; ++index) {
    if (_buff[index] == other._buff[0]) {
      int k = 1;
      for (int i = index + 1; _buff[i] && other._buff[k]; ++i, ++k) {
        if (_buff[i] != other._buff[k])
          break;
      }
      if (!other._buff[k])
        return index;
    }
  }
  return _length;
}
int String::length() const {
  return _length;
}
String String::substr(const int &pos, const int &count) const {
  char ch[_size] = {0};
  for (int index = 0; index < count; ++index)
    ch[index] = _buff[index + pos];
  return String(ch);
}
char& String::operator[](const int &index) {
  return _buff[index];
}
void String::operator=(const String &other) {
  if (_buff)
    delete[] _buff;
  _size = other._size;
  _length = other._length;
  _buff = new char[_size];
  memset(_buff, 0, _size);
  for (int index = 0; index < _size; ++index) 
    _buff[index] = other._buff[index];
}
void String::operator=(const char *src) {
  if (_buff)
    delete[] _buff;
  _size = strlen(src) + 1;
  _buff = new char[_size];
  memset(_buff, 0, _size);
  for (_length = 0; _length < _size; ++_length) 
    _buff[_length] = src[_length];
  --_length;
}
String String::operator+(const String &other) const {
  String result(*this);
  for (int index = 0; index < other._length; ++index)
    result.append(other._buff[index]);
  result.append('\0');
  --result._length;
  return result;
}
bool String::operator<(const String &other) const {
  if (compare(other) < 0)
    return true;
  return false;
}
bool String::operator<=(const String &other) const {
  if (compare(other) <= 0)
    return true;
  return false;
}
bool String::operator>(const String &other) const {
  if (compare(other) > 0)
    return true;
  return false;
}
bool String::operator>=(const String &other) const {
  if (compare(other) >= 0)
    return true;
  return false;
}
bool String::operator==(const String &other) const {
  if (compare(other) == 0)
    return true;
  return false;
}
bool String::operator!=(const String &other) const {
  if (compare(other) != 0)
    return true;
  return false;
}
std::ostream& operator<<(std::ostream& out, const String &str) {
  if (str._buff)
    out << str._buff;
  return out;
}