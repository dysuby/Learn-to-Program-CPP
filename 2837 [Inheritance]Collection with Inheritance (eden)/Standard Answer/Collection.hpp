
#ifndef COLLECTION_H_
#define COLLECTION_H_
typedef int E;

class Collection {
 public:
  Collection() {}
  virtual ~Collection(){};
  virtual void add(E e) = 0;
  virtual void clear(void) = 0;
  virtual bool contain(E e) = 0;
  virtual bool isEmpty(void) = 0;
  virtual void remove(int e) = 0;
  virtual int size(void) = 0;
};

#endif

