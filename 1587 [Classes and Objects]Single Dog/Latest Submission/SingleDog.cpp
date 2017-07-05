#include "SingleDog.h"
int SingleDog::count = 0;
SingleDog::SingleDog(int id_, char* name_): id(id_) {
  name = new char[50];
  int index;
  for (index = 0; name_[index]; ++index) 
    name[index] = name_[index];
  name[index] = '\0';
  ++count;
}
SingleDog::SingleDog(const SingleDog &other): id(other.id) {
  name = new char[50];
  int index;
  for (index = 0; other.name[index]; ++index) 
    name[index] = other.name[index];
  name[index] = '\0';
  ++count;
}
int SingleDog::getCount() {
  return count;
}
SingleDog::~SingleDog() {
  delete[] name;
  name = NULL;
  --count;
}