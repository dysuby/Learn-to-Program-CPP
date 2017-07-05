#include "user.hpp"
#include <iostream>
#include <cctype>
inline bool alipay::User::verifyPasswordFormat(const std::string & password) {
  for (auto ch : password) {
    if (!isalnum(ch)) {
      return false;
    }
  }
  if (password.size() >= 8 || password.empty()) {
    return true;
  }
}
inline bool alipay::User::verifyUsernameFormat(const std::string & username) {
  for (auto ch : username) {
    if (!isalnum(ch)) {
      return false;
    }
  }
  if (username.size() >= 6) {
    return true;
  }
}
inline bool alipay::User::verifyPhoneFormat(const std::string & phone) {
  if (phone.size() != 13) {
    return false;
  }
  return true;
}
bool alipay::User::setUsername(const char *username) {
  if (verifyUsernameFormat(username)) {
    alipay::User::username = username;
    return true;
  }
  return false;
}
bool alipay::User::setPassword(const char * new_password, const char * old_password) {
  if (verifyPasswordFormat(new_password) &&
    verifyPasswordFormat(old_password) &&
    old_password == alipay::User::password) {
    alipay::User::password = new_password;
    return true;
  }
  return false;
}
bool alipay::User::setPhone(const char * new_phone) {
  if (verifyPhoneFormat(new_phone)) {
    alipay::User::phone = new_phone;
    return true;
  }
  return false;
}
bool alipay::User::setGender(Gender::Gender gender) {
  if (gender != alipay::User::gender) {
    alipay::User::gender = gender;
  }
}
std::string alipay::User::getUsername(void) {
  return alipay::User::username;
}
std::string alipay::User::getPhone(void) {
  return alipay::User::phone;
}
alipay::Gender::Gender alipay::User::getGender(void) {
  return alipay::User::gender;
}
long long int alipay::User::getMoneyAmount(const char * password) {
  bool isCorrect = true;
  int index = 0;
  for (auto ch : alipay::User::password) {
    if (ch != password[index++]) {
      isCorrect = false;
    }
  }
  if (isCorrect) {
    return -1;
  }
  return 0;
}
bool alipay::User::deposit(long long int amount) {
  alipay::User::balance += amount;
}
bool alipay::User::withdraw(long long int amount, const char *password) {
  if (amount >= 0 && amount <= alipay::User::balance) {
    bool isCorrect = true;
    int index = 0;
    for (auto ch : alipay::User::password) {
      if (ch != password[index++]) {
        isCorrect = false;
      }
    }
    if (isCorrect) {
      alipay::User::balance -= amount;
    }
    return isCorrect;
  }
  return false;
}