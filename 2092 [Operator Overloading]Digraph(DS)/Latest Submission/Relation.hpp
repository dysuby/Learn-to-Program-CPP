#ifndef RELATION_HPP
#define RELATION_HPP
#include "ProductSet.hpp"
#include "BooleanMatrix.hpp"
class Relation {
  private:
    BooleanMatrix rel;
  public:
    Relation(BooleanMatrix a);
    BooleanMatrix getRelation() const;
    int indegree(int c) const;
    int outdegree(int r) const;
    bool isreflexive() const;
    bool isirreflexive() const;
    bool issymmetric() const;
    bool isasymmetric() const;
    bool isantisymmetric() const;
    bool istransitive() const;
};
#endif