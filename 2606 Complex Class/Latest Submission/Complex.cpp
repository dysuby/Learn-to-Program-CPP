 #include <iostream>
using namespace std;

class Complex{
 private:
  double real;
  double imag;
 public:
  Complex(double x=0, double y=0): real(x), imag(y) {}
  friend ostream &operator <<(ostream& os, const Complex&c)  {
  if (c.real != 0) {
    os << c.real;
    if (c.imag > 0 && c.imag != 1)
      os << "+" << c.imag << "i";
    else if (c.imag == 1)
      os << "+i";
  		else if (c.imag < 0 && c.imag != -1)
      os << c.imag << "i";
    else if (c.imag == -1)
      os << "-i";
  } else if (c.imag != 0) {
    if (c.imag == 1)
      os << "i";
    else if (c.imag == -1)
      os << "-i";
    else
    		os << c.imag << "i";
  } else {
    os << "0";
  }
  return os; 
}//e.g 2+3i  -2-5i
  friend istream &operator >>(istream& is, Complex &c) {
  is >> c.real >> c.imag;
  return is;
}
  Complex operator +(const Complex &obj) {
    Complex res;
    res.real = real + obj.real;
    res.imag = imag + obj.imag;
    return res;
  }
  Complex operator -(const Complex &obj) {
    Complex res;
    res.real = real - obj.real;
    res.imag = imag - obj.imag;
    return res;
  }
  Complex operator *(const Complex &obj) {
    Complex res;
    res.real = real * obj.real - imag * obj.imag;
    res.imag = imag * obj.real + obj.imag * real;
    return res;
  }
};
