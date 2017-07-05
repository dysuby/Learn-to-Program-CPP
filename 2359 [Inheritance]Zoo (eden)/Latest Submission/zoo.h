 #ifndef ZOO_H
#define ZOO_H
#include "animal.h"
#include <iostream>
#include <vector>

class Cat: public Animal {
  public:
    Cat(): Animal(std::string(""), 0), _type(CAT) {}
    Cat(std::string name, int age): Animal(name, age), _type(CAT) {}
    virtual void Shout() const {
      std::cout << getName() << ": meow~~" << std::endl;
    }
    virtual Type getType() const {
      return _type;
    }
  private:
    Type _type;
};

class Dog: public Animal {
  public:
    Dog(): Animal(std::string(""), 0), _type(DOG) {}
    Dog(std::string name, int age): Animal(name, age), _type(DOG) {}    
    virtual void Shout() const {
      std::cout << getName() << ": bark!!" << std::endl;      
    }
    virtual Type getType() const {
      return _type;
    }
  private:
    Type _type;
};

class Zoo {
  public:
    void addAnimal(Animal* ani);
    int getDogCount();
    int getCatCount();
    void deleteAnimalByName(std::string name);
    void deleteAnimalByAge(int age);
    void print();
  private:
    std::vector<Animal*> animal;
};
#endif
