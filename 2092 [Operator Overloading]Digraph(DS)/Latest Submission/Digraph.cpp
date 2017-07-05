#include "Digraph.hpp"
Digraph::Digraph(BooleanMatrix const& m, Set const& s): set(s), Relation(m) {}
int Digraph::getSetElePos(int ele) {
  int pos(0);
  while (pos < set.getSize()) {
    if (set.get(pos) == ele)
      return pos;
    ++pos;
  }
  return -1;
}
int Digraph::inDegree(int ele) { 
  int index = 1;
  for ( ; index <= set.getSize(); ++index)
    if (set.get(index) == ele)
      break;
  if (index <= set.getSize())
    return this -> Relation::indegree(index);
  return -1;
}
int Digraph::outDegree(int ele) {
  int index = 1;
  for ( ; index <= set.getSize(); ++index)
    if (set.get(index) == ele)
      break;
  if (index <= set.getSize())
    return this -> Relation::outdegree(index);
  return -1;
}
Digraph Digraph::pathOfLength(int len) {
  BooleanMatrix temp(Relation::getRelation());
  BooleanMatrix result(Relation::getRelation());
  for (int i = len; i > 1; --i) {
    result = result.BooleanProduct(temp);
  }
  return Digraph(result, set);
}

// Properties of Relations.    
bool Digraph::isReflexive() const {
  return this -> Relation::isreflexive();
}
bool Digraph::isIrreflexive() const {
  return this -> Relation::isirreflexive();
}
bool Digraph::isSymmetric() const {
  return this -> Relation::issymmetric();
}
bool Digraph::isAsymmetric() const {
  return this -> Relation::isasymmetric();
}
bool Digraph::isAntisymmetric() const {
  return this -> Relation::isantisymmetric();
}
bool Digraph::isTransitive() const {
  return this -> Relation::istransitive();
}
BooleanMatrix Digraph::getBooleanMatrix() const {
  return this -> Relation::getRelation();
}