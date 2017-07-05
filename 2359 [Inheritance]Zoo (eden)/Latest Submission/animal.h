#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
enum Type {
    CAT,
    DOG
};

class Animal {
 public:
    Animal(std::string _name, int _age) : name(_name), age(_age) {}
    virtual void Shout() const = 0;
    virtual Type getType() const = 0;
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
#endif
