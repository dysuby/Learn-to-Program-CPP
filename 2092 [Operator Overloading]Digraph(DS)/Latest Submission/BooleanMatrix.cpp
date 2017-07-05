#include "BooleanMatrix.hpp"
typedef bool matrix_element_type;
BooleanMatrix::BooleanMatrix(const BooleanMatrix& source): Matrix(source) {}
BooleanMatrix::BooleanMatrix(int r, int c): Matrix(r, c) {}
bool BooleanMatrix::replace(matrix_element_type e, int r, int c) {
  return Matrix::replace(e, r, c);
}
BooleanMatrix BooleanMatrix::operator&(const BooleanMatrix& b) {
  BooleanMatrix result(getRow(), getColums());
  if (getRow() == b.getRow() && getColums() == b.getColums()) {
    for (int r = 1; r <= getRow(); ++r) {
      for (int c = 1; c <= getColums(); ++c) {
        if (getElement(r, c) && b.getElement(r, c))
          result.replace(1, r, c);
      }
    }
  }
  return result;
}
BooleanMatrix BooleanMatrix::operator|(const BooleanMatrix& b) {
  BooleanMatrix result(getRow(), getColums());
  if (getRow() == b.getRow() && getColums() == b.getColums()) {
    for (int r = 1; r <= getRow(); ++r) {
      for (int c = 1; c <= getColums(); ++c) {
        if (getElement(r, c) || b.getElement(r, c))
          result.replace(1, r, c);
      }
    }
  }
  return result;
}
BooleanMatrix BooleanMatrix::BooleanProduct(const BooleanMatrix& b) const {
  BooleanMatrix result(getRow(), b.getColums());
  if (getColums() == b.getRow()) {
    for (int r = 1; r <= result.getRow(); ++r) {
      for (int c = 1; c <= result.getColums(); ++c) {
        for (int index = 1; index <= getColums(); ++index) {
          if (getElement(r, index) && b.getElement(index, c))
            result.replace(1, r, c);
        }
      }
    }
  }
  return result;
}