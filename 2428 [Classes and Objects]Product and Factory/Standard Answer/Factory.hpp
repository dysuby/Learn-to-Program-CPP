#ifndef FACTORY_HPP_
#define FACTORY_HPP_
#include "Product.hpp"

class Factory {
public:
  virtual Laptop* produceLaptop() = 0;
  virtual MobilePhone* produceMobilePhone() = 0;
  virtual ~Factory() {}
};

class AppleFactory : public Factory {
public:
  Laptop* produceLaptop() { return new AppleLaptop(); }
  MobilePhone* produceMobilePhone() { return new AppleMobilePhone(); }
};

class XiaomiFactory : public Factory {
public:
  Laptop* produceLaptop() { return new XiaomiLaptop(); }
  MobilePhone* produceMobilePhone() { return new XiaomiMobilePhone(); }
};

#endif
