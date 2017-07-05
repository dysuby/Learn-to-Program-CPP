#include "Set.hpp"
Set::Set() {
  size = 0;
  for (int& a : members) {
    a = 0;
  }
}
Set::Set(int* m, int s) {
  size = s;
  for (int index = 0; index < size; ++index) {
    members[index] = m[index];
  }
}
Set::Set(Set const& s) {
  for (int index = 0; index < s.size; ++index) {
    members[index] = s.members[index];
  }
  size = s.size;
}
bool Set::append(int e) {
  if (size < MAX_MEMBERS) {
    for (int index = 0; index < size; ++index) {
      if (members[index] == e)
        return false;
    }
    members[size] = e;
    ++size;
    return true;
  }
  return false;
}
bool Set::remove(int e) {
  if (size) {
    int index;
    for (index = 0; index < size; ++index) {
      if (members[index] == e) {
        break;
      }
    }
    if (index != size) {
      for (int index_ = index; index_ < size; ++index_) {
        members[index_] = members[index_ + 1];
      }
      --size;
      return true;
    }
  }
  return false;
}
bool Set::isEmptySet() {
  return !size;
}
bool Set::isInSet(int e) {
  for (int index = 0; index < size; ++index) {
    if (members[index] == e)
      return true;
  }
  return false;
}
Set Set::operator&(const Set &s) {
  int* result = new int[MAX_MEMBERS];
  int rindex = 0;
  for (int index = 0; index < size; ++index) {
    for (int sindex = 0; sindex < s.size; ++sindex) {
      if (s.members[sindex] == members[index]) {
        result[rindex] = members[index];
        ++rindex;
        break;
      }
    }
  }
  Set res(result, rindex);
  delete[] result;
  return res;
}
Set Set::operator|(const Set &s) {
  int* result = new int[MAX_MEMBERS];
  int rsize = 0;
  for (int index = 0; index < size; ++index) {
    result[index] = members[index];
    ++rsize;
  }
  for (int index = 0; index < s.size; ++index) {
    int rindex;
    for (rindex = 0; rindex < rsize; ++rindex) {
      if (result[rindex] == s.members[index])
        break;
    }
    if (rindex == rsize) {
      result[rsize] = s.members[index];
      ++rsize;
    }
  }
  Set res(result, rsize);
  delete[] result;
  return res;
}
Set Set::operator-(const Set &s) {
  int* result = new int[MAX_MEMBERS];
  int rsize = 0;
  for (int index = 0; index < size; ++index) {
    int sindex;
    for (sindex = 0; sindex < s.size; ++sindex) {
      if (members[index] == s.members[sindex]) {
        break;
      }
    }
    if (sindex == s.size) {
      result[rsize] =members[index];
      ++rsize;
    }
  }
  Set res(result, rsize);
  delete[] result;
  return res;
}
Set Set::operator+(const Set &s) {
  int *result = new int[MAX_MEMBERS];
  int rsize = 0;
  for (int index = 0; index < size; ++index) {
    bool flag = true;
    for (int sindex = 0; sindex < s.size; ++sindex) {
      if (members[index] == s.members[sindex]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      result[rsize] = members[index];
      ++rsize;
    }
  }
  for (int sindex = 0; sindex < s.size; ++sindex) {
    bool flag = true;
    for (int index = 0; index < size; ++index) {
      if (members[index] == s.members[sindex]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      result[rsize] = s.members[sindex];
      ++rsize;
    }
  }
  Set res(result, rsize);
  delete[] result;
  return res;
}
int* Set::getMembers() {
  return members;
}
int Set::getSize() {
  return size;
}