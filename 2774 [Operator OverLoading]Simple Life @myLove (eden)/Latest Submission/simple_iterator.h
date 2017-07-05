#ifndef SIMPLE_ITERATOR
#define SIMPLE_ITERATOR
class simple_iterator {
  public:
    simple_iterator(char *p): iterator(p) {}
    simple_iterator(): iterator(0) {}
    simple_iterator(const simple_iterator &oth) {
      iterator = oth.iterator;
    }
    simple_iterator prev() {
      return (iterator - 1);
    }
    simple_iterator next() {
      return (iterator + 1);    
    }
    simple_iterator begin() {
      auto temp = iterator;
      while (*temp != '\0')
        --temp;
      return ++temp;
    }
    simple_iterator end() {
      auto temp = iterator;
      while (*temp != '\0')
        ++temp;
      return --temp;
    }
    char operator*() {
      return *iterator;
    }
    simple_iterator operator++() {
      if (*iterator != '\0')
        return ++iterator;
    }
    simple_iterator operator--() {
      if (*iterator != '\0')
        return --iterator;
    }
    simple_iterator operator++(int) {
      if (*iterator != '\0')
        return iterator++;
    }
    simple_iterator operator--(int) {
      if (*iterator != '\0')
        return iterator--;
    }
    simple_iterator operator+(int index) {
      if (*iterator != '\0')
        return simple_iterator(iterator + index);
    }
    simple_iterator operator-(int index) {
      if (*iterator != '\0')
        return simple_iterator(iterator - index);
    }
    simple_iterator& operator=(const simple_iterator oth) {
      iterator = oth.iterator;
      return *this;
    }
    bool operator==(const simple_iterator &oth) const {
      return *iterator == *oth.iterator;
    }
    bool operator<(const simple_iterator &oth) const {
      return (*iterator < *oth.iterator);
    }
    bool operator>(const simple_iterator &oth) const {
      return (*iterator > *oth.iterator);
    }
    bool operator!=(const simple_iterator &oth) const {
      return *iterator != *oth.iterator;
    }
    bool operator>=(const simple_iterator &oth) const {
      return (*iterator == *oth.iterator) || (*iterator > *oth.iterator);
    }
    bool operator<=(const simple_iterator &oth) const {
      return (*iterator == *oth.iterator) || (*iterator < *oth.iterator);
    }
  private:
    char *iterator;
};
#endif