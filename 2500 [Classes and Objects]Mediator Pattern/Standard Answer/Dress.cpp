#include "Dress.hpp"
Dress::Dress(const string & n, const int p):name(n),price(p){}

Dress::Dress(const Dress & oth) {
    this->name = oth.name;
    this->price = oth.price;
}

int Dress::getPrice() const {
    return price;
}

string Dress::getName() const {
    return name;
}