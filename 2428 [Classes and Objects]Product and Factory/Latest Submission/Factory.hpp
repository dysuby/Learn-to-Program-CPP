#ifndef FACTORY_HPP
#define FACTORY_HPP
#include "Product.hpp"

class Factory {
  public:
    virtual Laptop* produceLaptop() = 0;
    virtual MobilePhone* produceMobilePhone() = 0;
    virtual ~Factory() = default;
};

class AppleFactory: public Factory {
  public:
    virtual Laptop* produceLaptop() {
      return new AppleLaptop;
    }
    virtual MobilePhone* produceMobilePhone() {
      return new AppleMobilePhone;
    }
    virtual ~AppleFactory() = default;
};

class XiaomiFactory: public Factory {
  public:
    virtual Laptop* produceLaptop() {
      return new XiaomiLaptop;
    }
    virtual MobilePhone* produceMobilePhone() {
      return new XiaomiMobilePhone;
    }
    virtual ~XiaomiFactory() = default;
};
#endif