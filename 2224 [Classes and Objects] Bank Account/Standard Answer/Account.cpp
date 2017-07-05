#include "Account.h"
 #include <cstdio>
#include <cstring>
 int Account::_total_account = 0;
 Account::Account() {
  _valid = false;
  _balance = _id = 0;
  _total_account++;
}
 Account::~Account() {
  _total_account--;
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
 std::string Account::profile() const {
  std::string ret = "";
  char t_buff[64];
  std::snprintf(t_buff, sizeof(t_buff), "%d", _id);
  ret += "ID:" + std::string(t_buff) + "\n";
  std::snprintf(t_buff, sizeof(t_buff), "%.6lf", _balance);
  ret += "BALANCE:" + std::string(t_buff) + "\n";
  ret += "VALID:" + std::string(this->valid() ? "Y" : "N") + "\n";
  return ret;
}
 void Account::reset() {
  _balance = 0;
}
 bool Account::deposit(const double &num) {
  if (num >= 0) {
    _balance += num;
    return true;
  } else {
    return false;
  }
}
 bool Account::draw(const double &num) {
  if (num >= 0 && _balance - num >= 0.01) {
    _balance -= num;
    return true;
  } else {
    return false;
  }
}
 int Account::get_total_account() {
  return _total_account;
}
 