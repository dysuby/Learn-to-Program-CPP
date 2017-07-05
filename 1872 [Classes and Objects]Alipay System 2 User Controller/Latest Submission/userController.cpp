#include "userController.hpp"
#include <cstring>
#include <cctype>
#include <sstream>
using namespace Alipay;
using std::string;
using std::ostringstream;
inline bool verifyUsername(const char* username) {
  if (strlen(username) < 6 || strlen(username) > 20)
    return false;
  for (int index = 0; username[index]; ++index) {
    if (!isalnum(username[index]))
      return false;
  }
  return true;
}
inline bool verifypassword(const char* password) {
  if (strlen(password) < 8 || strlen(password) > 20)
    return false;
  for (int index = 0; password[index]; ++index) {
    if (!isalnum(password[index]))
      return false;
  }
  return true;
}
int userController::getUserIndex(const char* username) const {
  for (int index = 0; index < usercount; ++index) {
    const char* name = users[index] -> getUsername();
    if (!strcmp(name, username))
      return index;
  }
  return usercount;
}
userController::userController(double interest_rate) {
  this -> interest_rate = interest_rate;
  usercount = 0;
}
userController::~userController() {
  for (int index = 0; index < usercount; ++index)
    delete users[index];
  usercount = 0;
  interest_rate = 0;
}
bool userController::createUser(const char* username, const char* password) {
  if (usercount < MAX_USER && verifyUsername(username) && verifypassword(password)) {
    users[usercount] = new user(username, password);
    ++usercount;
    return true;
  }
  return false;
}
bool userController::deposite(const char* username, double amount) {
  int index = getUserIndex(username);
  if (index != usercount) {
    bool flag = users[index] -> deposite(amount);
    return flag;
  }
  return false;
}
bool userController::withdraw(const char* username, double amount) {
  int index = getUserIndex(username);
  if (index != usercount) {
    bool flag = users[index] -> withdraw(amount);
    return flag;
  }
  return false;
}
string userController::getUserInfoByName(const char* username) const {
  int index = getUserIndex(username);
  if (index != usercount) {
    ostringstream s;
    s << "username:" << users[index] -> getUsername() << '\n' ;
    s << "password:*********\n";
    s << "balance:" << users[index] -> getBalance();
    return s.str();
  }
  return string("No such user!");
}
int userController::getUserCount(void) const {
  return usercount;
}
bool userController::removeUserByUsername(const char* username) {
  int index = getUserIndex(username);
  if (index != usercount) {
    delete users[index];
    for (int i = index; i < usercount; ++i) 
      users[i] = users[i + 1];
    --usercount;
    return true;
  }
  return false;
}
bool userController::setInterest(double interest) {
  if (interest >= 0) {
    interest_rate = interest;
    return true;
  } 
  return false;
}
void userController::payInterest(void) {
  for (int index = 0; index < usercount; ++index) {
    double amount = users[index] -> getBalance();
    users[index] -> deposite(amount * interest_rate);
  }
}