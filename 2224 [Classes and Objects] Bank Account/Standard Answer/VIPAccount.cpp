#include "VIPAccount.h"
 #include <cstdio>
#include <cstring>
 int VIPAccount::_total_vip_account = 0;
int VIPAccount::_acc_id_ptr = 0;
 VIPAccount::VIPAccount() {
  _id = 12050000 + _acc_id_ptr++;
  _balance = 10;
  _valid = true;
  _loan = 0;
  _loan_limit = 1000;
  _total_vip_account++;
}
 VIPAccount::~VIPAccount() {
  _total_vip_account--;
}
 bool VIPAccount::loan(const double &num) {
  if (num > 0 && _loan + num < _loan_limit) {
    _loan += num;
    _balance += num;
    return true;
  } else {
    return false;
  }
}
 bool VIPAccount::repay(const double &num) {
  if (num < 0 || _balance - num < 0.01)
    return false;
  if (num > _loan) {
    _balance -= _loan;
    _loan = 0;
    return true;
  } else {
    _balance -= num;
    _loan -= num;
    return true;
  }
}
 std::string VIPAccount::profile() const {
  char t_buff[64];
  std::string ret = Account::profile();
  ret += "TYPE:VIP\n";
  std::snprintf(t_buff, sizeof(t_buff), "%.6lf", _loan);
  ret += "LOAN:" + std::string(t_buff);
  std::snprintf(t_buff, sizeof(t_buff), "%.6lf", _loan_limit);
  ret += ",LIMIT:"+ std::string(t_buff) + "\n";
  return ret;
}
 void VIPAccount::reset() {
  _balance = 10;
  _loan = 0;
  _loan_limit = 1000;
}
 int VIPAccount::get_total_vip_account() {
  return _total_vip_account;
}