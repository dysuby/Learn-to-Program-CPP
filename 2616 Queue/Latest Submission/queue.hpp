#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#define MAX_SIZE 10
typedef int E;

class queue {
private:
  E* storage;
  int max_size;
  int head;
  int rear;
public:
  queue();
  ~queue();
  void push(E);
  void pop();
  E front();
  E back();
  bool isFull();
  bool isEmpty();
  void clear();
};
#endif
