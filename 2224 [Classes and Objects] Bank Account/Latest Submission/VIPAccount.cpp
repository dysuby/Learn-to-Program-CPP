#include "VIPAccount.h"
#include <cstdio>

int VIPAccount::_total_vip_account = 0;
int VIPAccount::_acc_id_ptr = 12050000;

VIPAccount::VIPAccount(): _loan_limit(1000), _loan(0) {
  _id = _acc_id_ptr;
  _balance = 10;
  _valid = true;
  ++_total_vip_account;
  ++_acc_id_ptr;
}

VIPAccount::~VIPAccount() {
  --_total_vip_account;
}

bool VIPAccount::loan(const double &num) {
  if (_loan + num < _loan_limit) {
    _loan += num;
    _balance += num;
    return true;
  }
  return false;
}

bool VIPAccount::repay(const double &num) {
  if (num < _balance + 0.01 && num <= _loan) {
    _balance -= num;
    _loan -= num;
    return true;
  }
  return false;
}
std::string VIPAccount::profile() const {
  char res[100] = {0};
  snprintf(res, 99, "ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:VIP\nLOAN:%.6lf,LIMIT:%.6lf\n", 
         _id, _balance, _loan, _loan_limit);
  return std::string(res);
}

void VIPAccount::reset() {
  _balance = 10;
  _valid = true;
  _loan = 0;
}

int VIPAccount::get_total_vip_account() {
  return _total_vip_account;
}