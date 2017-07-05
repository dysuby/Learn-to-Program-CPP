#include "BinaryRelation.hpp"

BinaryRelation::BinaryRelation(BooleanMatrix const &m, Set const &s): 
                              Relation(m), set(s) {}
int BinaryRelation::getSetElePos(int e) {
  for (int index = 1; index <= set.getSize(); ++index)
    if (set.get(index) == e)
      return index;
  return -1;
}

int BinaryRelation::inDegree(int e) {
  int pos = getSetElePos(e);
  if (pos > 0) {
    int num = 0;
    for (int i = 1; i <= matrix.getRow(); ++i)
      if (matrix.getElement(i, pos))
        ++num;
    return num;
  }
}

int BinaryRelation::outDegree(int e) {
  int pos = getSetElePos(e);
  if (pos > 0) {
    int num = 0;
    for (int i = 1; i <= matrix.getColums(); ++i)
      if (matrix.getElement(pos, i))
        ++num;
    return num;
  }
}

BinaryRelation BinaryRelation::pathOfLength(int len) {
  BooleanMatrix res(matrix);
  for (int i = 1; i < len; ++i) {
    res = res.BooleanProduct(matrix);
  }
  return BinaryRelation(res, set);
}

bool BinaryRelation::isReflexive() const {
  if (matrix.getRow() == matrix.getColums()) {
    for (int i = 1; i <= matrix.getRow(); ++i)
      if (!matrix.getElement(i, i))
        return false;
    return true;
  }
  return false;
}

bool BinaryRelation::isIrreflexive() const {
  if (matrix.getRow() == matrix.getColums()) {
    for (int i = 1; i <= matrix.getRow(); ++i)
      if (matrix.getElement(i, i))
        return false;
    return true;
  }
  return false;
}

bool BinaryRelation::isSymmetric() const {
  for (int i = 1; i <= matrix.getRow(); ++i) {
    for (int j = 1; j <= matrix.getColums(); ++j) {
      if (matrix.getElement(i, j) != matrix.getElement(j, i))
        return false;
    }
  }
  return true;
}

bool BinaryRelation::isAsymmetric() const {
  for (int i = 1; i <= matrix.getRow(); ++i) {
    for (int j = 1; j <= matrix.getColums(); ++j) {
      if (matrix.getElement(i, j) && matrix.getElement(j, i))
        return false;
    }
  }
  return true;
}

bool BinaryRelation::isAntisymmetric() const {
  for (int i = 1; i <= matrix.getRow(); ++i) {
    for (int j = 1; j <= matrix.getColums(); ++j) {
      if (matrix.getElement(i, j) && matrix.getElement(j, i) && i != j)
        return false;
    }
  }
  return true;
}

bool BinaryRelation::isTransitive() const {
  for (int i = 1; i <= matrix.getRow(); ++i) {
    for (int j = 1; j <= matrix.getColums(); ++j) {
      for (int k = 1; k <= matrix.getColums(); ++k) {
        if (matrix.getElement(i, k) && matrix.getElement(k, j) &&
            !matrix.getElement(i, j))
          return false;
      }
    }
  }
  return true;
}

bool BinaryRelation::isEquivalence() const {
  return this -> isReflexive() && this -> isSymmetric() 
          && this -> isTransitive();
}

BinaryRelation BinaryRelation::composition(const BinaryRelation &b) {
  return BinaryRelation(matrix.BooleanProduct(b.matrix), set);
}

BinaryRelation BinaryRelation::reflexiveClosure() const {
  BooleanMatrix res(matrix);
  for (int i = 1; i <= matrix.getRow(); ++i)
    res.replace(1, i, i);
  return BinaryRelation(res, set);
}

BinaryRelation BinaryRelation::symmetricClosure() const {
  BooleanMatrix res(matrix);
  for (int i = 1; i <= matrix.getRow(); ++i) {
    for (int j = 1; j <= matrix.getColums(); ++j) {
      if (matrix.getElement(i, j))
        res.replace(1, j, i);
    }
  }
  return BinaryRelation(res, set);
}

BinaryRelation BinaryRelation::transitiveClosure() const {
  BooleanMatrix res(matrix);
  for (int k = 1; k <= matrix.getRow(); ++k) {
    for (int i = 1; i <= matrix.getRow(); ++i) {
      for (int j = 1; j <= matrix.getColums(); ++j) {
        bool temp = res.getElement(i, j) || 
                  (res.getElement(i, k) && res.getElement(k, j));
        res.replace(temp, i, j);
      }
    }
  }
  return BinaryRelation(res, set);
}