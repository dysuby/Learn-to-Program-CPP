#include "Mediator.hpp"
Mediator* Mediator::Ins = NULL;
void Mediator::RegisterHandler(User * u) {
    for (auto i = users.begin(); i != users.end(); ++i) {
        if (u->getId() == (*i)->getId())
            return;
    }
    users.push_back(u);
}

void Mediator::ChatHandler(const int & to, const string & msg) {
    for (auto i = users.begin(); i != users.end(); ++i) {
        if ((*i)->getId() == to) {
            (*i)->GetMessage(msg);
            return;
        }
    }
    cout << "Are you kidding ? There is no such a guy!" << endl;
}

pair<int, string> Mediator::TradeHandler(const int & to, const int & pay, const string & dressName) {
    for (auto i = users.begin(); i != users.end(); ++i) {
        if ((*i)->getId() == to) {
            pair<int, string> t = (*i)->SellBeautifulDress(pay, dressName);
            return t;
        }
    }
    cout << "There is no Such a guy!" << endl;
    return std::make_pair(-1, "");
}

void Mediator::DressInfoHandler(const int & to) {
    for (auto i = users.begin(); i != users.end(); ++i) {
        if ((*i)->getId() == to) {
            (*i)->ShowMyCuteDresses();
            return;
        }
    }
    cout << "Are you kidding ? Or you just wanna to see air ?" << endl;
}