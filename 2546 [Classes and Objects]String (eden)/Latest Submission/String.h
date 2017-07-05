 #ifndef STRING_H
#define STRING_H
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

class String {
  public:
    String(): _buff(NULL), _size(0) {}
    explicit String(const char *src) {
      _size = strlen(src);
      _buff = new char[_size + 1];
      memset(_buff, _size + 1, 0);
      snprintf(_buff, _size + 1, "%s", src);
    }
    String(const String &src) {
      _size = src._size;
      _buff = new char[_size + 1];
      memset(_buff, _size + 1, 0);
      snprintf(_buff, _size + 1, "%s", src._buff);
    }

    ~String() {
      delete[] _buff;
      _size = 0;
    }

    String& operator =(const String& src) {
      _size = src._size;
      char *buff = new char[_size + 1];
      memset(buff, _size + 1, 0);
      snprintf(buff, _size + 1, "%s", src._buff);
      delete[] _buff;
      _buff = buff;
      return *this;
    }
    const char* c_str() const {
      return _buff;
    }
    inline char& operator[](int i) {
      return _buff[i];
    }

    friend ostream& operator <<(ostream& os, const String& src);

  private:
    char *_buff;
    int _size;
};

ostream& operator <<(ostream& os, const String& src) {
  os << src.c_str();
  return os;
}

#endif