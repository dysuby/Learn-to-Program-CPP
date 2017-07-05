#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

int main() {
  int size(0);
  cin >> size;
  map<string, set<string>> all_qq;
  map<string, set<string>> all_ip;
  string qq, ip;
  for (int index = 0; index < size; ++index) {
    cin >> qq >> ip;
    all_qq[qq].insert(ip);
    all_ip[ip].insert(qq);
  }
  cin >> ip >> qq;
  if (all_ip[ip].size() == 0) {
    cout << "no qq" << endl;
  } else {
    cout << ip << " ==> [ ";
    for (auto i = all_ip[ip].begin(); i != all_ip[ip].end(); ++i) {
      cout << *i << " ";
    }
    cout << "]" << endl;   
  }
  if (all_qq[qq].size() == 0) {
    cout << "no ip" << endl;
  } else {
    cout << qq << " ==> [ ";
    for (auto i = all_qq[qq].begin(); i != all_qq[qq].end(); ++i) {
      cout << *i << " ";
    }
    cout << "]" << endl; 
  }
  return 0;
}