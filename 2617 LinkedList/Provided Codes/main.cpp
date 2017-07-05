#include <iostream>
#include <cstdlib>
#include "LinkedList.hpp"

using std::cin;
using std::cout;
using std::endl;

class TEST {
private:
  int *testData;
  int data_size;

 public:
  TEST() {
#if defined(_GLIBCXX_LIST)
    cout << "FORBIDDEN!" << endl;
#endif
    cin >> data_size;
    cout << "test data size:" << data_size << endl;
    testData = new int[data_size];
    for (int i = 0; i < data_size; i++) {
      cin >> testData[i];
    }
  }

  ~TEST() { delete[] testData; }

  void testLinkedList(LinkedList *c) {
    cout << (c->isEmpty() ? "true" : "false") << endl;

    int n = data_size;

    for (int i = 0; i < n; i++) {
      c->add(testData[i]);
    }

    for (int i = 0; i < c->size(); i++) {
      cout << (*c)[i] << " ";
    }

    cout << endl;

    cout << (c->isEmpty() ? "true" : "false") << endl;

    for (int i = 0; i < n / 2; i++) {
      cout << "(" << i << ", "
           << (c->contain(i) ? "true" : "false");
      cout << ","
           << c->indexOf(i)
           << ") ";
      c->remove(i);
    }

    cout << endl;

    for (int i = 0; i < c->size(); i++) {
      cout << (*c)[i] << " ";
    }
    cout << endl;

    cout << "remaining size: " << c->size() << endl;

    c->clear();
    cout << (c->isEmpty() ? "true" : "false") << endl;
  }

  void runAllTests() {
    LinkedList *c = new LinkedList();
    testLinkedList(c);
    delete c;
  }
};

int main() {
  TEST t;
  t.runAllTests();
  return 0;
}
