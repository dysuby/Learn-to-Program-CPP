#include "user.hpp"
#include "global.hpp"
#include <cstring>
using namespace Alipay;
user::user(const char* username, const char* password) {
  int index;
  for (index = 0; username[index]; ++index)
    this -> username[index] = username[index];
  this -> username[index] = '\0';
  for (index = 0; password[index]; ++index)
    this -> password[index] = password[index];
  this -> password[index] = '\0';
  balance = 0;
}
user::~user() {
  memset(username, 0, 21);
  memset(password, 0, 21);
  balance = 0;
}
const char* user::getUsername() const {
  return username;
}
const char* user::getPassword() const {
  return password;
}
const void user::setUsername(const char* username) {
  memset(this -> username, 0, 21);
  for (int index = 0; username[index] && index < 21; ++index)
    this -> username[index] = username[index];
}
const void user::setPassword(const char* password) {
  memset(this -> username, 0, 21);
  for (int index = 0; username[index] && index < 21; ++index)
    this -> username[index] = username[index];
}
double user::getBalance() {
  return balance;
}
bool user::withdraw(double amount) {
  if (amount <= balance) {
    balance -= amount;
    return true;
  } else {
    return false;
  }
}
bool user::deposite(double amount) {
  if (amount >= 0.0) {
    balance += amount;
    return true;
  }
  return false;
}