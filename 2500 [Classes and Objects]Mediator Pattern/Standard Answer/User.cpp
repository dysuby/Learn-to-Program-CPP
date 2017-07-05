#include "User.hpp"
#include "Mediator.hpp"
int User::Count = 0;

User::User(const string & na, const int & mon, const vector<pair<string, int> > & dresses):name(na), money(mon) {
    for (int i = 0; i < dresses.size(); i++) {
        this->dresses.push_back(Dress(dresses[i].first, dresses[i].second));
    }
    this->id = Count++;
}

void User::BuyBeautifulDress(const int & id, const int & pay, const string & name) {
    if (pay > money) {
        cout << this->name << " : " << "Forget to Check Wallet!" << endl;
        return;
    }
    Mediator* mediator = Mediator::getInstance();
    pair<int, string> t = mediator->TradeHandler(id, pay, name);
    if (t.first != -1 && t.first != 0) {
        cout << this->name << " : " << "So happy to get new Dress!" << endl;
        this->dresses.push_back(Dress(t.second, t.first));
        money -= pay;
    }
    else if (t.first == 0)
        cout << this->name << " : " <<  "OMG! Why it is so Expensive!" << endl;
    else
        cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
}

void User::GetDressInfo(const int & id) {
    Mediator* mediator = Mediator::getInstance();
    cout << this->name << " : " << "I wanna see your beautiful suits!" << endl;
    mediator->DressInfoHandler(id);
}

pair<int, string> User::SellBeautifulDress(const int & pay, const string & dname) {
    for(auto i = this->dresses.begin(); i != this->dresses.end(); ++i) {
        if ((*i).getName() == dname) {
            if (pay >= (*i).getPrice()) {
                pair<int, string> t = std::make_pair((*i).getPrice(), (*i).getName());
                dresses.erase(i);
                cout << this->name << " : " << "What a good taste you have !" << endl;
                money += pay;
                return t;
            } else {
               cout << this->name << " : " <<  "No money then no talking" << endl;
               return std::make_pair(0, "");
                break;
            }
        }
    }
    cout << this->name <<" : " << "I never have this Dress stupid!" << endl;
    return std::make_pair(-1, "");
}

void User::SendMessage(const int & to, const string & msg) {
    Mediator* mediator = Mediator::getInstance();
    mediator->ChatHandler(to, msg);
}

void User::GetMessage(const string & msg) {
    cout << this->name <<" : I got a Msg - " << msg << endl;
}

void User::ShowMyCuteDresses() {
    cout << this->name << " : ok,these are all I have : "<<endl;
    for(int i = 0; i < dresses.size(); i++) {
        cout << dresses[i].getName() << "-" << dresses[i].getPrice() << endl;
    }
}