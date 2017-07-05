 #include "Complex.hpp"
using namespace std;
Complex::Complex(double real, double imag) {
  SetReal(real);
  SetImag(imag);
}
Complex Complex::operator *(const Complex& b) {
  Complex c;
  c.real = real * b.real - imag * b.imag;
  c.imag = real * b.imag + imag * b.real;
  return c;
}
Complex Complex::operator +(const Complex& b) {
  Complex c;
  c.real = real + b.real;
  c.imag = imag + b.imag;
  return c;
}
Complex Complex::operator -(const Complex& b) {
  Complex c;
  c.real = real - b.real;
  c.imag = imag - b.imag;
  return c;
}
Complex Complex::operator /(const Complex& b) {
  Complex c;
  c.real = (real * b.real + imag * b.imag) / (b.real * b.real + b.imag * b.imag);
  c.imag = (imag * b.real - real * b.imag) / (b.real * b.real + b.imag * b.imag);
  return c;
}
Complex& Complex::operator *=(const Complex& b) {
  Complex c;
  c.real = real * b.real - imag * b.imag;
  c.imag = real * b.imag + imag * b.real;
  *this = c;
  return *this;
}
Complex& Complex::operator -=(const Complex& b) {
  real = real - b.real;
  imag = imag - b.imag;
  return *this;
}
Complex& Complex::operator /=(const Complex& b) {
  Complex c;
  c.real = (real * b.real + imag * b.imag) / (b.real * b.real + b.imag * b.imag);
  c.imag = (imag * b.real - real * b.imag) / (b.real * b.real + b.imag * b.imag);
  *this = c;
  return *this;
}
Complex& Complex::operator +=(const Complex& b) {
  real = real + b.real;
  imag = imag + b.imag;
  return *this;
}
bool Complex::operator ==(const Complex& b) {
  if (real == b.real && imag == b.imag)
    return true;
  return false;
}
bool Complex::operator !=(const Complex& b) {
  if (real == b.real && imag == b.imag)
    return false;
  return true;
}
ostream& operator <<(ostream& os, const Complex& a) {
  if (a.real == 0 && a.imag == 0) {
    os << "0";
  }
  if (a.real == 0 && a.imag) {
    os << a.imag << "i\n";
  }
  if (a.real && a.imag == 0) {
    os << a.real;
  }
  if (a.real && a.imag) {
    if (a.imag > 0) 
      os << a.real << "+" << a.imag << "i\n";
    else
      os << a.real << a.imag << "i\n";
  }
  return os;
}