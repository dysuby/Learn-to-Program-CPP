#ifndef __ZOO_H__
#define __ZOO_H__
#include <vector>
#include "animal.h"
 
class Zoo {
 public:
    Zoo() : dogCnt(0), catCnt(0) {}
    bool addAnimal(Animal* animal);
    void deleteAnimalByName(const std::string& name);
    void deleteAnimalByAge(int age);
    int getDogCount() const;
    int getCatCount() const;
    void print();
    ~Zoo();
 
 private:
    std::vector<Animal*> collection;
    int dogCnt;  // count of dogs
    int catCnt;  // count of cats
};

#endif