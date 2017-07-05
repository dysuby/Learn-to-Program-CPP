#include "PersonalAccount.h"
#include <cstdio>

int PersonalAccount::_total_per_account = 0;
int PersonalAccount::_acc_id_ptr = 12010000;

PersonalAccount::PersonalAccount() {
   _id = _acc_id_ptr;
   _valid = true;
   _balance = 10;
  ++_total_per_account;
  ++_acc_id_ptr;
}

PersonalAccount::~PersonalAccount() {
  --_total_per_account;
}

std::string PersonalAccount::profile() const {
  char res[100] = {0};
  snprintf(res, 99, "ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:PERSONAL\n", _id, _balance);
  return std::string(res);
}

void PersonalAccount::reset() {
  _balance = 10;
  _valid = true;
}

int PersonalAccount::get_total_per_account() {
  return _total_per_account;
}