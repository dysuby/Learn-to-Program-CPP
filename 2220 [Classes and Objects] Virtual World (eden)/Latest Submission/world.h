#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
static int num = 0;
struct person {
  int id;
  person(): id(num) {
    ++num;
  }
};
class group {
  private:
    map<int, vector<int>> members;
    bool known;
  public:
    group(int i): known(i) {}
    void displayGroup();
    bool addMember(person &p);
    bool deleteMember(person &p);
    bool makeFriend(person &p1, person &p2);
    bool breakRelation(person &p1, person &p2);
};
bool group::addMember(person &p) {
  if (members.find(p.id) == members.end() && p.id < 9900) {
    vector<int> temp;
    members.insert(pair<int, vector<int>>(p.id, temp));
    if (known) {
      for (auto &a: members) {
        if (a.first != p.id) {
          a.second.push_back(p.id);
          members[p.id].push_back(a.first);
        }
      }
    }
    return true;
  }
  return false;
}
bool group::deleteMember(person &p) {
  if (members.find(p.id) != members.end()) {
    members.erase(p.id);
    return true;
  }
  return false;
}
bool group::makeFriend(person &p1, person &p2) {
  if (members.find(p1.id) != members.end() && members.find(p2.id) != members.end()) {
    members[p1.id].push_back(p2.id);
    members[p2.id].push_back(p1.id);
    return true;
  }
  return false;
}
bool group::breakRelation(person &p1, person &p2) {
  vector<int>::iterator a = find(members[p1.id].begin(), members[p1.id].end(), p2.id);
  vector<int>::iterator b = find(members[p2.id].begin(), members[p2.id].end(), p1.id);
  if (members.find(p1.id) != members.end() && members.find(p2.id) != members.end() &&
      a != members[p1.id].end() && b != members[p2.id].end()) {
    members[p1.id].erase(a);
    members[p2.id].erase(b);
    return true;
  }
  return false;
}
void group::displayGroup() {
  for (auto &m: members) {
    cout << "Person_" << m.first << ": ";
    if (!m.second.size())
      cout << "null";
    for (int i = 0; i < m.second.size(); ++i) {
      cout << m.second[i];
      cout << ((i + 1 < m.second.size()) ? ", " : "");
    }
    cout << endl;
  }
}
#endif