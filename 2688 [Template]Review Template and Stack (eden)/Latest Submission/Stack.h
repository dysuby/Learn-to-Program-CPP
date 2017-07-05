 #ifndef STACK_H
#define STACK_H
#include <queue>
#include <iostream>
using std::queue;
using std::cout;
using std::endl;

template <typename T>
class Stack {
  public:
    Stack(): count(0) {} // constructor.
    void push(const T& data) {
      q1.push(data);
      ++count;
    } // push operation.
    T pop() {
      if (count == 0)
        return T();
      while (q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
      }
      T res = q1.front();
      q1.pop();
      while (q2.size()) {
        q1.push(q2.front());
        q2.pop();
      }
      --count;
      return res;
    } // return the value in the top and pop it out of the stack.
    T top() {
      if (q1.size()) 
        return q1.back();
      else
        return T();
    } // return the value in top.
    int size() const {return count;}  // return size of the stack.
    bool empty() {return !count;} // check whether is empty.
    friend void print(Stack sta) {
      while (sta.size()) {
        cout << sta.top() << " ";
        sta.pop();
      }
      cout << endl;
    }
  private:
    queue<T> q1; // two queues.
    queue<T> q2;
    int count; // the number of elements.
};
#endif