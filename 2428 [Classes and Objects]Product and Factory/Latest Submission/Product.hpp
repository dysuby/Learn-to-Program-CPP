#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <iostream>

class Laptop {
  public:
    virtual void compileCppProgram() = 0;
    virtual ~Laptop() = default;
};

class AppleLaptop: public Laptop {
  public:
    virtual void compileCppProgram() {
      std::cout << "Apple Laptop compiles a cpp program."
                << std::endl;
    }
    virtual ~AppleLaptop() = default;

};

class XiaomiLaptop: public Laptop {
  public:
    virtual void compileCppProgram() {
      std::cout << "Xiaomi Laptop compiles a cpp program."
                << std::endl;
    }
    virtual ~XiaomiLaptop() = default;
};

class MobilePhone {
  public:
    virtual void sendShortMessage() = 0;
    virtual ~MobilePhone() = default;
};

class AppleMobilePhone: public MobilePhone {
  public:
    virtual void sendShortMessage() {
      std::cout << "Apple MobilePhone sends a short message."
                << std::endl;
    }
    virtual ~AppleMobilePhone() = default;
};

class XiaomiMobilePhone: public MobilePhone {
  public:
    virtual void sendShortMessage() {
      std::cout << "Xiaomi MobilePhone sends a short message."
                << std::endl;
    }
    virtual ~XiaomiMobilePhone() = default;
};
#endif