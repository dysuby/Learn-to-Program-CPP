#include "dns.h"
#include <iostream>
using std::cout;
using std::endl;

dns::dns(string ip): _ip(ip) {}

vector<string>& dns::operator[](const string& domain) {
  return _map[domain];
}

void dns::nslookup(const string& domain) {
  cout << "Server: " << _ip << endl;
  if (_map.find(domain) != _map.end() && _map[domain].size()) {
    for (auto ad: _map[domain]) {
      cout << "Name: " << domain << endl;
      cout << "Address: " << ad << endl;
    }
  } else {
    cout << "Server can't find " << domain << endl;
  }
}