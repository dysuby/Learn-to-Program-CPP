#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include <iostream>
#include <string>
enum Type {
    CAT,
    DOG
};
 
class Animal {
 public:
    Animal(const std::string& _name, int _age) : name(_name), age(_age) {}
    virtual void Shout() const = 0;
    virtual Type getType() const = 0;  // get the type: CAT or DOG
    std::string getName() const {
        return name;
    }
 
    int getAge() const {
        return age;
    }
 
 private:
    std::string name;
    int age;
};
 
class Cat: public Animal {
 public:
    Cat(const std::string& _name = "", int _age = 0) : Animal(_name, _age) {}
    void Shout() const {
        std::cout << getName() << ": meow~~" << std::endl;
    }
    Type getType() const {
        return CAT;
    }
 
};
 
class Dog: public Animal {
 public:
    Dog(const std::string& _name = "", int _age = 0) : Animal(_name, _age) {}
    void Shout() const {
        std::cout << getName() << ": bark!!" << std::endl;
    }
 
    Type getType() const {
        return DOG;
    }
};
#endif