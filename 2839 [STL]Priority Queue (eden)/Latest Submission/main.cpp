 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int cases(0);
  cin >> cases;
  for (int times(0); times < cases; ++times) {
    int min(0), pos(0), size(0);
    vector<int> que;
    decltype(que.begin()) i;
    cin >> size >> pos;
    for (int index(0); index < size; ++index) {
      int temp(0);
      cin >> temp;
      que.push_back(temp);
    }
    while (pos >= 0) {
      int val = que[0];
      auto i = que.begin() + 1;
      for ( ; i != que.end(); ++i) {
        if (*i > val)
          break;
      }
      if (i != que.end()) {
        que.push_back(val);
        que.erase(que.begin());
        if (pos == 0)
          pos = que.size() - 1;
        else
          --pos;
      } else {
        que.erase(que.begin());
        ++min;
        if (pos == 0)
          break;
        else
          --pos;
      }
    }
    cout << min << endl;
  }
  return 0;
}