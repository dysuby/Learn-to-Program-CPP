#ifndef CMP_H
#define CMP_H
#include <string>
using std:: string;

bool cmp(const int &lhs, const int &rhs) {
  return lhs == rhs;
}
bool cmp(const double &lhs, const double &rhs) {
  return lhs == rhs;
}
bool cmp(const string &lhs, const string &rhs) {
  return lhs == rhs;
}
bool cmp(const int *lhs, const int *rhs) {
  return *lhs == *rhs;
}
bool cmp(const double *lhs, const double *rhs) {
  return *lhs == *rhs;
}
bool cmp(const char *lhs, const char *rhs) {
  string a(lhs), b(rhs);
  return a == b;
}
#endif