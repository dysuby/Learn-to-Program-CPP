#include "User.hpp"
#include "Mediator.hpp"
#include <algorithm>
#include <utility>

int User::Count = 0;

User::User(const string & name, const int & money, 
          const vector<pair<string, int> > & dresses): name(name), 
          money(money), id(Count) {
  for (auto dress: dresses) {
    (this -> dresses).push_back(Dress(dress.first, dress.second));
  }
  ++Count;
}

void User::BuyBeautifulDress(const int & id, const int & pay, const string & name) {
  if (pay > money) {
    cout << this->name << " : " << "Forget to Check Wallet!" << endl;
  } else {
    pair<int, string> res = Mediator::getInstance() -> 
                            TradeHandler(id, pay, name);
    if (res.first) {
      cout << this->name << " : " << "So happy to get new Dress!" << endl;
      money -= res.first;
      dresses.push_back(Dress(name, res.first));
    } else if (res.second == "Can't afford it") {
      cout << this->name << " : " <<  "OMG! Why it is so Expensive!" << endl;
    } else {
      cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
    }
  }
}

pair<int, string> User::SellBeautifulDress(const int & pay, const string & dname) {
  auto f = [dname](Dress i) -> bool {return i.getName() == dname;};
  auto d = std::find_if(dresses.begin(), dresses.end(), f);
  if (d == dresses.end()) {
    cout << this->name <<" : " << "I never have this Dress stupid!" << endl;
    return std::make_pair(0, string("No such a dress"));
  } else if (pay < d -> getPrice()) {
    cout << this->name << " : " <<  "No monry then no talking" << endl;
    return std::make_pair(0, string("Can't afford it"));
  } else {
    cout << this->name << " : " << "What a good taste you have !" << endl;
    dresses.erase(d);
    return std::make_pair(d -> getPrice(), string("Success"));
  }
}

void User::GetDressInfo(const int & id) {
  cout << this->name << " : " << "I wanna see your beautiful suits!" << endl;
  Mediator::getInstance() -> DressInfoHandler(id);
}

void User::SendMessage(const int & to, const string & msg) {
  Mediator::getInstance() -> ChatHandler(to, msg);
}

void User::GetMessage(const string & msg) {
  cout << this->name <<" : I got a Msg - " << msg << endl;
}

void User::ShowMyCuteDresses() {
  cout << this->name << " : ok,these are all I have : "<<endl;
  for (auto dress: dresses) {
    cout << dress.getName() << "-" << dress.getPrice() << endl;
  }
}
