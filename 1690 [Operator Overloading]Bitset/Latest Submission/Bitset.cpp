#include "Bitset.h"
#include <cstring>
#define S (sizeof(int) * 8)
bitset::bitset() {
  for (int index = 0; index < N; ++index) {
    a[index] = 0;
  }
}
void bitset::set(int pos) {
  int index = pos / S;
  int bitpos = pos % S;
  a[index] |= (1 << bitpos);
}
void bitset::reset(int pos) {
  int index = pos / S;
  int bitpos = pos % S;
  a[index] &= ~(1 << bitpos);
}
int bitset::count() const {
  int count = 0;
  for (int index = 0; index < N; ++index) {
    for (int bitindex = 0; bitindex < S; ++bitindex) {
      if (a[index] & (1 << bitindex))
        ++count;
    }
  }
  return count;
}
bool bitset::test(int pos) const {
  int index = pos / S;
  int bitpos = pos % S;
  return (a[index] & (1 << bitpos));
}
bool bitset::any() const {
  return count();
}
bool bitset::none() const {
  return !count();
}
bool bitset::all() const {
  for (int index = 0; index < N; ++index) {
    if (a[index] ^ (~0) != 0)
      return false;
  }
  return true;
}
bitset& bitset::operator&= (const bitset& b) {
  for (int index = 0; index < N; ++index) {
    a[index] &= b.a[index];
  }
  return *this;
}
bitset& bitset::operator|= (const bitset& b) {
  for (int index = 0; index < N; ++index) {
    a[index] |= b.a[index];
  }
  return *this; 
}
bitset& bitset::operator^= (const bitset& b) {
  for (int index = 0; index < N; ++index) {
    a[index] ^= b.a[index];
  }
  return *this;
}
bitset& bitset::operator= (const bitset& b) {
  for (int index = 0; index < N; ++index) {
    a[index] = b.a[index];
  }
  return *this;
}
bitset& bitset::operator <<= (int pos) {
  a[N - 1] <<= pos;
  for (int index = N - 2; index >= 0; --index) {
    int temp = 0;
    for (int bitindex = 0; bitindex < pos; ++bitindex) {
      temp |= (a[index] & (1 << (S - bitindex - 1)));
      a[index + 1] &= ~(1 << bitindex);
    }
    a[index] <<= pos;
    temp >>= (S - pos);
    for (int tindex = S - 1; tindex >= pos; --tindex) {
      temp &= ~(1 << tindex);
    }
    a[index + 1] |= temp;
  }
  return *this;
}
bitset& bitset::operator >>= (int pos) {
  a[0] >>= pos;
  for (int index = 1; index < N; ++index) {
    int temp = 0;
    for (int bitindex = 0; bitindex < pos; ++bitindex) {
      temp |= (a[index] & (1 << bitindex));
      a[index - 1] &= ~(1 << (S - bitindex - 1));
    }
    a[index - 1] |= temp << (S - pos);
    a[index] >>= pos;
  }
  return *this;
}
bitset bitset::operator~() const {
  bitset b = *this;
  for (int index = 0; index < N; ++index) {
    b.a[index] = ~a[index];
  }
  return b;
}
bitset bitset::operator&(const bitset& b) const {
  bitset c = *this;
  for (int index = 0; index < N; ++index) {
    c.a[index] &= b.a[index];
  }
  return c;
}
bitset bitset::operator|(const bitset& b) const {
  bitset c = *this;
  for (int index = 0; index < N; ++index) {
    c.a[index] = (a[index] | b.a[index]);
  }
  return c;
}
bitset bitset::operator^(const bitset& b) const {
  bitset c = *this;
  for (int index = 0; index < N; ++index) {
    c.a[index] = (a[index] ^ b.a[index]);
  }
  return c;
}
bitset bitset::operator<<(int pos) const {
  bitset res = *this;
  res.a[N - 1] <<= pos;
  for (int index = N - 2; index >= 0; --index) {
    int temp = 0;
    for (int bitindex = 0; bitindex < pos; ++bitindex) {
      temp |= (res.a[index] & (1 << (S - bitindex - 1)));
      res.a[index + 1] &= ~(1 << bitindex);
    }
    res.a[index] <<= pos;
    temp >>= (S - pos);
    for (int tindex = S - 1; tindex >= pos; --tindex) {
      temp &= ~(1 << tindex);
    }
    res.a[index + 1] |= temp;
  }
  return res;
}
bitset bitset::operator>>(int pos) const {
  bitset res = *this;
  res.a[0] >>= pos;
  for (int index = 1; index < N; ++index) {
    int temp = 0;
    for (int bitindex = 0; bitindex < pos; ++bitindex) {
      temp |= (res.a[index] & (1 << bitindex));
      res.a[index - 1] &= ~(1 << (S - bitindex - 1));
    }
    res.a[index - 1] |= temp << (S - pos);
    res.a[index] >>= pos;
  }
  return res;
}
bool bitset::operator!= (const bitset& b) const {
  for (int index = 0; index < N; ++index) {
    if (a[index] != b.a[index])
      return true;
  }
  return false;
}
bool bitset::operator== (const bitset& b) const {
  for (int index = 0; index < N; ++index) {
    if (a[index] != b.a[index])
      return false;
  }
  return true;
}
bool bitset::operator[] (int pos) const {
  int index = pos / S;
  int bitpos = pos % S;
  return a[index] & (1 << bitpos);
}