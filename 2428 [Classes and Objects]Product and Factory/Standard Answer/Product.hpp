#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_
#include <iostream>
using std::cout;
using std::endl;

class Laptop {
public:
  virtual void compileCppProgram() = 0;
  virtual ~Laptop() {}
};

class AppleLaptop : public Laptop {
public:
  void compileCppProgram() {
    cout << "Apple Laptop compiles a cpp program." << endl;
  }
};

class XiaomiLaptop : public Laptop {
public:
  void compileCppProgram() {
    cout << "Xiaomi Laptop compiles a cpp program." << endl;
  }
};


class MobilePhone {
public:
  virtual void sendShortMessage() = 0;
  virtual ~MobilePhone() {}
};

class AppleMobilePhone : public MobilePhone {
public:
  void sendShortMessage() {
    cout << "Apple MobilePhone sends a short message." << endl;
  }
};

class XiaomiMobilePhone : public MobilePhone {
public:
  void sendShortMessage() {
    cout << "Xiaomi MobilePhone sends a short message." << endl;
  }
};

#endif
