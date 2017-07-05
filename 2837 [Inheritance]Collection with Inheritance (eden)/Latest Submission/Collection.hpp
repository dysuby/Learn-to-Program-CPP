 #ifndef COLLECTION_HPP
#define COLLECTION_HPP
class Collection {
public:
  typedef int E;
  virtual void add(int ele) = 0;
  virtual void clear() = 0;
  virtual bool contain(int ele) = 0;
  virtual bool isEmpty() = 0;
  virtual void remove(int ele) = 0;
  virtual int size() = 0;
  virtual ~Collection() {}
};
#endif