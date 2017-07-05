# Complex Class

Please design a Complex class.
```
class Complex{
 private:
  double real;
  double imag;
 public:
  Complex(double x=0, double y=0);
  friend ostream &operator <<(ostream& os, const Complex&c);//e.g 2+3i  -2-5i
  friend istream &operator >>(istream& is, Complex &c);
  Complex operator +(const Complex &obj);
  Complex operator -(const Complex &obj);
  Complex operator *(const Complex &obj);
};
```