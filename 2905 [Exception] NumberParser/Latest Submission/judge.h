#ifndef JUDGE_H
#define JUDGE_H
#include <exception>
#include <sstream>
#include <string>
using std::string;
using std::istringstream; 

class NumberParseException {
  private:
    int what;
};
bool isNumber(const char* str) {
  if (str == NULL)
    throw NumberParseException();
  if ((str[0] != '+' && str[0] != '-' &&
        (str[0] < '0' || str[0] > '9')) ||
      ((str[0] == '+' || str[0] == '-') && str[1] == '\0'))
    throw NumberParseException();
  for (int index = 1; str[index] != '\0'; ++index)
    if (str[index] < '0' || str[index] > '9')
      throw NumberParseException();
  return true;
}
int parseNumber(const char *str) {
  try {
    if (isNumber(str)) {
      istringstream res(str);
      long int temp;
      res >> temp;
      return temp;
    }
  } catch(NumberParseException) {
    throw;
  }
}
#endif