#ifndef INHERITANCE_HPP
#define INHERITANCE_HPP
#include <iostream>
using namespace std;
class baseA {
public:
  baseA();
  ~baseA();
};
class baseB {
public:
  baseB();
  ~baseB();
};
class derivedA : public baseA {
public:
  derivedA();
  ~derivedA();
};
class derivedB : baseA, baseB{
public:
  derivedB();
  ~derivedB();
};
class C : derivedA, derivedB{
public:
  C();
  ~C();
};
#endif