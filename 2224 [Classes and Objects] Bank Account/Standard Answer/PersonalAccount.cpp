#include "PersonalAccount.h"
 int PersonalAccount::_total_per_account = 0;
int PersonalAccount::_acc_id_ptr = 0;
 PersonalAccount::PersonalAccount() {
  _id = 12010000 + _acc_id_ptr++;
  _balance = 10;
  _valid = true;
  _total_per_account++;
}
 PersonalAccount::~PersonalAccount() {
  _total_per_account--;
}
 std::string PersonalAccount::profile() const {
  std::string ret = Account::profile();
  ret += "TYPE:PERSONAL\n";
  return ret;
}
 void PersonalAccount::reset() {
  _balance = 10;
}
 int PersonalAccount::get_total_per_account() {
  return _total_per_account;
}
 