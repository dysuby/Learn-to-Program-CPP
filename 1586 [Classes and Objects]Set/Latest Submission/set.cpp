#include "set.hpp"
Set::Set() {
  for (auto &mem : members) {
    mem = 0;
  }
  size = 0;
}
Set::Set(int* m, int s) {
  size  = 0;
  for (int index = 0; index < s; ++index) {
    append(*(m + index));
  }
}
bool Set::append(int e) {
  if (size != MAX_MEMBERS && !isInSet(e)) {
    members[size] = e;
    ++size;
    return true;
  }
  return false;
}
bool Set::remove(int e) {
  int index;
  for (index = 0; index < size; ++index) {
    if (members[index] == e)
      break;
  }
  if (index == size)
    return false;
  for (int beg = index; beg < size - 1; ++beg) {
    members[beg] = members[beg + 1];
  }
  --size;
  return true;
}
bool Set::isEmptySet() {
  return !size;
}
int* Set::getMembers() {
  return members;
}
int Set::getSize() {
  return size;
}
bool Set::isInSet(int e) {
  for (int index = 0; index < size; ++index) {
    if (members[index] == e)
      return true;
  }
  return false;
}
