#include "Vector.h"
#include <iostream>

Vector::Vector(string name_, int dim, int vec[]): 
      name(name_), dimension(dim) {
  param = new int[dim];
  for (int index = 0; index < dim; ++index)
    param[index] = vec[index];
  cout << "construct a vector called " << name << "." << endl;
}

Vector::Vector(const Vector &otherVec): 
      name(otherVec.name), dimension(otherVec.dimension) {
  param = new int[otherVec.dimension];
  for (int index = 0; index < otherVec.dimension; ++index)
    param[index] = otherVec.param[index];
  cout << "copy a vector called " << name << "." << endl;
}

Vector::~Vector() {
  delete[] param;
  cout <<  "release memory from a vector called " << name << "." <<endl;
}
void Vector::isEqual(const Vector &other) {
  string nameEqual("different name"), valueEqual(", different value.");
  if (dimension == other.dimension) {
    int index = 0;
    for ( ; index < dimension; ++index)
      if (param[index] != other.param[index])
        break;
    if (index == dimension)
      valueEqual = ", same value.";
  }
  if (name == other.name)
    nameEqual = "same name";
  cout << nameEqual << valueEqual << endl;
}
void Vector::setName(string name_) {
  name = name_;
}
void Vector::print() {
  cout << name << "(" << param[0];
  for (int index = 1; index < dimension; ++index)
    cout << ", " << param[index];
  cout << ")" << endl;
}