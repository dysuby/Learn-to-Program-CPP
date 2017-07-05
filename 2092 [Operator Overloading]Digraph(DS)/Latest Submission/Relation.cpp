#include "Relation.hpp"
Relation::Relation(BooleanMatrix b): rel(b) {}
BooleanMatrix Relation::getRelation() const {
  return rel;
}
int Relation::indegree(int c) const {
  int num = 0;
  for (int index = 1; index <= rel.getRow(); ++index) 
    if (rel.getElement(index, c))
      ++num;
  return num;
}
int Relation::outdegree(int r) const {
  int num = 0;
  for (int index = 1; index <= rel.getColums(); ++index) 
    if (rel.getElement(r, index))
      ++num;
  return num;
}
bool Relation::isreflexive() const {
  for (int index = 1; index <= rel.getRow(); ++index)
    if (!rel.getElement(index, index))
      return false;
  return true;
}
bool Relation::isirreflexive() const {
  for (int index = 1; index <= rel.getRow(); ++index)
    if (rel.getElement(index, index))
      return false;
  return true;
}
bool Relation::issymmetric() const {
  return rel.isSymmetrix();
}
bool Relation::isasymmetric() const {
  for (int r = 1; r <= rel.getRow(); ++r) {
    for (int c = 1; c <= rel.getColums(); ++c) {
      if (rel.getElement(r, c) && rel.getElement(c, r))
        return false;
    }
  }
  return true;
}
bool Relation::isantisymmetric() const {
  for (int r = 1; r <= rel.getRow(); ++r) {
    for (int c = 1; c <= rel.getColums(); ++c) {
      if (rel.getElement(r, c) && rel.getElement(c, r) && c != r)
        return false;
    }
  }
  return true;
}
bool Relation::istransitive() const {
  for (int r = 1; r <= rel.getRow(); ++r) {
    for (int c = 1; c <= rel.getColums(); ++c) {
      for (int index = 1; index <= rel.getColums(); ++index) {
        if (rel.getElement(r, index) && rel.getElement(index, c) &&
          !rel.getElement(r, c))
          return false;
        }
    }
  }
  return true;
}