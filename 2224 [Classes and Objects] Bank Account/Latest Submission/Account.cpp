#include "Account.h"
#include <iostream>
#include <cstdio>
using std::string;

int Account::_total_account = 0;

Account::Account(): _id(0), _balance(0), _valid(false) {
  ++_total_account;
}

Account::~Account() {
  --_total_account;
}

int Account::id() const {
  return _id;
}

double Account::balance() const {
  return _balance;
}

bool Account::valid() const {
  return _valid;
}

string Account::profile() const {
  char res[100] = {0};
  snprintf(res, 99, "ID:%d\nBALANCE:%.6lf\nVALID:N\n", _id, _balance);
  return string(res); 
}

void Account::reset() {
  _balance = 0;
  _valid = false;
}

bool Account::deposit(const double &num) {
  if (num > 0.0) {
    _balance += num;
    return true;
  }
  return false;
}

bool Account::draw(const double &num) {
  if (num < _balance - 0.01) {
    _balance -= num;
    return true;
  }
  return false;
}

int Account::get_total_account() {
  return _total_account;
}