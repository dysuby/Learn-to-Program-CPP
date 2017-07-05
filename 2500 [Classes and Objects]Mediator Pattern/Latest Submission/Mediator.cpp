#include "Mediator.hpp"
#include <algorithm>

Mediator* Mediator::Ins = NULL;

void Mediator::RegisterHandler(User* u) {
  users.push_back(u);
}

void Mediator::ChatHandler(const int & to, const string & msg) {
  auto f = [to](User* i) -> bool {return i -> getId() == to;};
  if (to >= users.size())
    cout << "Are you kidding ? There is no such a guy!" << endl;
  else 
    (*std::find_if(users.begin(), users.end(), f)) -> GetMessage(msg);
}

pair<int, string> Mediator::TradeHandler(const int & to, const int & pay, 
                            const string & dressName) {
  auto f = [to](User* i) -> bool {return i -> getId() == to;};
  if (to >= users.size()) {
    cout << "There is no Such a guy!" << endl;
    return std::make_pair(-1, "No such a guy");
  } else {
    return (*std::find_if(users.begin(), users.end(), f)) -> SellBeautifulDress(pay, dressName);
  }
}

void Mediator::DressInfoHandler(const int & to) {
  auto f = [to](User* i) -> bool {return i -> getId() == to;};
  if (to >= users.size()) 
    cout << "Are you kidding ? Or you just wanna to see air ?" << endl;
  else 
    (*std::find_if(users.begin(), users.end(), f)) -> ShowMyCuteDresses();
}
