#include "MyInteger.hpp"   
MyInteger::MyInteger(int val) {
  value = val;
}
int MyInteger::getValue() const {
  return value;
}
bool MyInteger::isEven() const {
  return !(value % 2);
}
bool MyInteger::isOdd() const {
  return value % 2;
}
bool MyInteger::isPrime() const {
  if (isEven() && value != 2 || value == 1)
    return false;
  for (int index = 2; index < value; ++index) {
    if (!(value % index))
      return false;
  }
  return  true;
}
bool MyInteger::isEven(int value_) {
  return !(value_ % 2);
}
bool MyInteger::isOdd(int value_) {
  return value_ % 2;
}
bool MyInteger::isPrime(int value_) {
  if (isEven(value_) && value_ != 2 || value_ == 1)
    return false;
  for (int index = 2; index < value_ ; ++index) {
    if (!(value_ % index))
      return false;
  }
  return  true;
}
bool MyInteger::isEven(const MyInteger& test) {
  return !(test.value % 2);
}
bool MyInteger::isOdd(const MyInteger& test) {
  return (test.value % 2);
}
bool MyInteger::isPrime(const MyInteger& test) {
  if (isEven(test) && test.value != 2 || test.value == 1)
    return false;
  for (int index = 2; index < test.value; ++index) {
    if (!(test.value % index))
      return false;
  }
  return  true;
}
bool MyInteger::equals(int val) {
  return val == value;
}
bool MyInteger::equals(const MyInteger& test) {
  return value == test.value;
}
int MyInteger::parseInt(const std::string& str) {
  return std::stoi(str);
}