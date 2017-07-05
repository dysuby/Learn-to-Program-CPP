#include "Relation.hpp"

Relation::Relation(BooleanMatrix const &b): matrix(b) {}

BooleanMatrix Relation::getBooleanMatrix() const {
  return matrix;
}

Relation Relation::complementary() const {
  BooleanMatrix res(matrix.getRow(), matrix.getColums());
  for (int i = 1; i <= matrix.getRow(); ++i) {
    for (int j = 1; j <= matrix.getColums(); ++j) {
      if (!matrix.getElement(i, j))
        res.replace(1, i, j);
    }
  }
  return Relation(res);
}

Relation Relation::inverse() const {
  BooleanMatrix res(matrix.getRow(), matrix.getColums());
  res = matrix.transpose();
  return Relation(res);
}

Relation Relation::operator&(const Relation &b) {
  BooleanMatrix res(matrix.getRow(), matrix.getColums());
  res = matrix & b.matrix;
  return Relation(res);
}

Relation Relation::operator|(const Relation &b) {
  BooleanMatrix res(matrix.getRow(), matrix.getColums());
  res = matrix | b.matrix;
  return Relation(res);
}
