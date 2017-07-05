#ifndef EXCHANG_H
#define EXCHANG_H
#include <string>
std::string change1(char* st) {
  std::string result = "";
  result += st;
  return result;
}
void change2(std::string st1, char* st2) {
  int index = 0;
  for (auto ch: st1) {
    st2[index++] = ch;
  }
}
#endif