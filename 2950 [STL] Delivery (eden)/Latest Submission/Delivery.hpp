 #ifndef DELIVERY_HPP
#define DELIVERY_HPP
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> getInfoSort(std::vector<string> info) {
  map<string, string> res;
  for (auto i: info) {
    string date(i.substr(0, 19));
    string name(i.substr(20, i.size() - 1));
    auto pos = find_if(res.begin(), res.end(), 
              [name](pair<string, string> i){return i.second == name;});
    if (pos == res.end())
      res[date] = name;
    else
      if (date < pos -> first) {
        res.erase(pos);
        res[date] = name;
      }
  }
  vector<string> r;
  for (auto i: res) {
    string str = i.first + " : " + i.second;
    r.push_back(str);
  }
  return r;
}

#endif