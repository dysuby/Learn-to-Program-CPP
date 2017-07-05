#include "List.hpp"
using std::cout;
using std::cin;
using std::endl;
int main() {
    vector<string> foods;
    int size;
    cin >> size;
    string tmp;
    while (size--) {
        cin >> tmp;
        foods.push_back(tmp);
    }
    CycleList l1(foods), l2(foods);
    cout  << "Test 1" << endl;   // 检查重复调用eat
    cout << l1 << endl;
    while (l1.size() != 0) {
        l1.Eat();
        cout << "After eat" << endl;
        cout << l1 << endl;
    }
    cout  << "Test 2" << endl;   // 检查随机调用eat(pos)
    int eatTimes;
    cin >> eatTimes;
    cout << l2 << endl;
    while (eatTimes--) {
        int eat;
        cin >> eat;
        cout << "After eat at pos : " << eat << endl;
        l2.Eat(eat);
        cout << l2 << endl;
    }
    if (true) {    // 检查析构函数与clear
        cout  << "Test 3" << endl;
        CycleList l3(foods);
        cout << l3 << endl;
        l3.clear();
        cout << "After a Big guys clear all" << endl;
        cout << l3 << endl;
    }
}