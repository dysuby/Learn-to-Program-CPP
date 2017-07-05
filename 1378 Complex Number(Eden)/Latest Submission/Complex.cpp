 #include "Complex.hpp"
#include <iostream>
using namespace std;
void Complex::setComplexNumber(double rp, double ip) {
  realPart = rp;
  imaginaryPart = ip;
}
Complex::Complex() {
  realPart = 0;
  imaginaryPart = 0;
}
Complex::Complex(double real, double imaginary) {
  setComplexNumber(real, imaginary);
}
void Complex::printComplex() {
  cout << '(' << realPart << ", " << imaginaryPart << ')';
}
Complex Complex::add(const Complex &right) {
  realPart += right.realPart;
  imaginaryPart += right.imaginaryPart;
  return *this;
}
Complex Complex::subtract(const Complex &right) {
  realPart -= right.realPart;
  imaginaryPart -= right.imaginaryPart;
  return *this;
}