#include "EasyString.hpp"
void Assign(char * &str, int &length) {
  str = new char[length + 1];
}
void AddTwo(string & res, char * & str1, char * & str2) {
  res = res + str1 + str2;
  delete[] str1;
  delete[] str2;
}