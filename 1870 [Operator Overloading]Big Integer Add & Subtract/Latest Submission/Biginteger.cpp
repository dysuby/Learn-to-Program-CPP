#include "Biginteger.h"
#include <cstring>
BigInteger operator+(const BigInteger& left, const BigInteger& right) {
  BigInteger result;
  result.size_ = (left.size_ > right.size_ ? left.size_ : right.size_) + 1;
  result.data_ = new int[result.size_];
  memset(result.data_, 0, result.size_ * sizeof(int));
  int plus = 0, index = result.size_ - 1;
  int lindex = left.size_ - 1, rindex = right.size_ - 1;
  for ( ; lindex >= 0 && rindex >= 0; --lindex, --rindex) {
    result.data_[index] = ((left.data_[lindex] + right.data_[rindex]) % 10 + plus) % 10;
    plus = (left.data_[lindex] + right.data_[rindex] + plus) / 10;
    --index;
  }
  if (lindex >= 0) {
    for ( ; lindex >= 0; --lindex) {
      if (plus) {
        result.data_[index] = (left.data_[lindex] + plus) % 10;
        plus = (left.data_[lindex] + plus) / 10;
      } else {
        result.data_[index] = left.data_[lindex];
      }
      --index;
    }
  }
  if (rindex >= 0) {
    for ( ; rindex >= 0; --rindex) {
      if (plus) {
        result.data_[index] = (right.data_[rindex] + plus) % 10;
        plus = (right.data_[rindex] + plus) / 10;
      } else {
        result.data_[index] = right.data_[rindex];
      }
      --index;
    }
  }
  if (lindex < 0 && rindex < 0) {
    result.data_[index] = plus;
  }
  return result;
}
BigInteger operator-(const BigInteger& left, const BigInteger& right) {
  BigInteger result;
  result.size_ = (left.size_ > right.size_ ? left.size_ : right.size_) + 1;
  result.data_ = new int[result.size_];
  memset(result.data_, 0, result.size_ * sizeof(int));
  int borrow = 0, index = result.size_ - 1;
  int lindex = left.size_ - 1, rindex = right.size_ - 1;
  for ( ; lindex >= 0 && rindex >= 0; --lindex, --rindex) {
    if (left.data_[lindex] >= right.data_[rindex]) {
      result.data_[index] = left.data_[lindex] - right.data_[rindex];
      --index;
    } else {
      if (left.data_[lindex - 1]) {
        --left.data_[lindex - 1];
      } else {
        int i;
        for (i = lindex - 1; !left.data_[i]; --i) {
          left.data_[i] = 9;
        }
        --left.data_[i];
      }
      result.data_[index] = left.data_[lindex] + 10 - right.data_[rindex];
      --index;
    }
  }
  if (lindex >= 0) {
    for ( ; lindex >= 0; --lindex) {
      result.data_[index] = left.data_[lindex];
      --index;
    }
  }
  return result;
}
ostream& operator<<(ostream& out, const BigInteger& Bint) {
  int index = 0;
  for ( ; Bint.data_[index] == 0; ++index);
  for ( ; index < Bint.size_; ++index)
    out << Bint.data_[index];
  return out;
}
BigInteger::BigInteger() {
  size_ = 0;
  data_ = NULL;
}
BigInteger::BigInteger(const BigInteger& other) {
  size_ = other.size_;
  data_ = new int[size_];
  memset(data_, 0, size_ * sizeof(int));
  for (int index = 0; index < other.size_; ++index) {
    data_[index] = other.data_[index];
  }
}
BigInteger::~BigInteger() {
  delete[] data_;
  size_ = 0;
}
BigInteger::BigInteger(const string& number) {
  size_ = number.size();
  data_ = new int[size_];
  memset(data_, 0, size_ * sizeof(int));
  int index = 0;
  for (const auto &ch : number) {
    data_[index] = ch - '0';
    ++index;
  }
}