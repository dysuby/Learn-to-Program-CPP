#ifndef STACK_H
#define STACK_H
#include <exception>
const int MAX_LEN = 5;

template<typename T>
class Stack {
  public:
    explicit Stack(): stack_size(0), data{0} {}
    bool empty() const {
      return stack_size == 0;
    }
    int size() const {
      return stack_size;
    }
    T& top() {
      if (stack_size == 0)
        throw int(0);
      else 
        return data[stack_size - 1];
    }
    const T& top() const {
      if (stack_size == 0)
        throw int(0);
      else 
        return data[stack_size - 1];
    }
    void push(const T& x) {
      if (stack_size < MAX_LEN) {
        data[stack_size] = x;
        ++stack_size;
      } else if (x > data[stack_size - 1]) {
        pop();
        data[stack_size] = x;
        ++stack_size;
      }
    }
    void pop() {
      if (stack_size == 0)
        throw double(0.0);
      else
        data[--stack_size] = 0;
    }
  private:
    T data[MAX_LEN];
    int stack_size;
};
#endif