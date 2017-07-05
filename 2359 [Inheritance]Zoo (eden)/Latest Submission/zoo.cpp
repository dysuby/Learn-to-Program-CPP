#include "zoo.h"
#include <algorithm>

void Zoo::addAnimal(Animal* ani) {
  animal.push_back(ani);
}

int Zoo::getDogCount() {
  return std::count_if(animal.begin(), animal.end(), 
    [](Animal* i) {return i -> getType() == DOG;});
}

int Zoo::getCatCount() {
  return std::count_if(animal.begin(), animal.end(), 
    [](Animal* i) {return i -> getType() == CAT;});
}

void Zoo::deleteAnimalByName(std::string name) {
  for (auto i = animal.begin(); i != animal.end(); ) {
    if ((*i) -> getName() == name) {
      animal.erase(i);
      i = animal.begin();
    } else {
      ++i;
    }
  }
}

void Zoo::deleteAnimalByAge(int age) {
  for (auto i = animal.begin(); i != animal.end(); ) {
    if ((*i) -> getAge() == age) {
      animal.erase(i);
      i = animal.begin();
    } else {
      ++i;
    }
  }
}

void Zoo::print() {
  std::for_each(animal.begin(), animal.end(),
    [](Animal* i) -> void {i -> Shout();});
}