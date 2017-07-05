#ifndef COMPLEX_HPP
#define COMPLEX_HPP
class Complex {
  public:
    Complex();
    Complex(double real, double imaginary);
    void printComplex();
    void setComplexNumber(double rp, double ip);
    Complex add(const Complex &right);
    Complex subtract(const Complex &right);
  private:
    double realPart;
    double imaginaryPart;
};
#endif