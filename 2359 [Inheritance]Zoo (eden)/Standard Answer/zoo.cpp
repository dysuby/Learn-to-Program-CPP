#include "zoo.h"

bool Zoo::addAnimal(Animal* animal) {
    std::vector<Animal*>::iterator it;
    for (it = collection.begin(); it != collection.end(); it++) {
        if (*it == animal)
            return false;
    }
    if (animal->getType() == CAT)
        catCnt++;
    if (animal->getType() == DOG)
        dogCnt++;
    collection.push_back(animal);
};
 
void Zoo::deleteAnimalByName(const std::string& name) {
    std::vector<Animal*>::iterator it;
    for (it = collection.begin(); it != collection.end();) {
        if ((*it)->getName() == name) {
            if ((*it)->getType() == CAT) catCnt--;
            if ((*it)->getType() == DOG) dogCnt--;
            it = collection.erase(it);
        } else {
            it++;
        }
    }
}
 
void Zoo::deleteAnimalByAge(int age) {
    std::vector<Animal*>::iterator it;
    for (it = collection.begin(); it != collection.end();) {
        if ((*it)->getAge() == age) {
            if ((*it)->getType() == CAT) catCnt--;
            if ((*it)->getType() == DOG) dogCnt--;
            it = collection.erase(it);
        } else {
            it++;
        }
    }
}
 
int Zoo::getCatCount() const {
    return catCnt;
}
 
int Zoo::getDogCount() const {
    return dogCnt;
}
 
void Zoo::print() {
    std::vector<Animal*>::iterator it;
    for (it = collection.begin(); it != collection.end(); it++) {
        (*it)->Shout();
    }
}
 
Zoo::~Zoo() {
    collection.clear();
}