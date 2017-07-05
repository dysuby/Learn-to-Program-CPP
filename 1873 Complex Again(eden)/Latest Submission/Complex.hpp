 #ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
class Complex {
public:
  Complex(double real = 0.0, double imag = 0.0);
  ~Complex() = default;
  void SetReal(double re) {real = re;}
  void SetImag(double im) {imag = im;}
  Complex operator *(const Complex& b);
  Complex operator +(const Complex& b);
  Complex operator -(const Complex& b);
  Complex operator /(const Complex& b);
  Complex& operator *=(const Complex& b);
  Complex& operator -=(const Complex& b);
  Complex& operator /=(const Complex& b);
  Complex& operator +=(const Complex& b);
  bool operator ==(const Complex& b);
  bool operator !=(const Complex& b);
  friend ostream& operator <<(ostream& os, const Complex& a);
private:
  double real;
  double imag;
};
ostream& operator <<(ostream& os, const Complex& a);
#endif