#include <memory>
#include "base.h"

template<typename T, typename Alloc = std::allocator<T>>
class myVector: public Base {
    public:
        // Constructor
        myVector() {
          Alloc a;
          _data = a.allocate(10);
          _size = 0;
          _capacity = 10;
        }
        myVector(const std::size_t &size, const T &val,
                 Alloc a = Alloc()) {
          _data = a.allocate(size);
          for (_size = 0; _size < size; ++_size)
            a.construct(_data + _size, val);
          _size = size;
          _capacity = size;
        }
        template<typename InputIterator>
            myVector(InputIterator begin, InputIterator end,
                     Alloc a = Alloc()) {
              _data = a.allocate(end - begin);
              for (int index = 0; index < end - begin; ++index) {
                a.construct(_data + index, *(begin + index));
              }
              _size = end - begin;
              _capacity = _size;
            }
        myVector(const myVector &other) {
          _size = other._size;
          _capacity = other._capacity;
          Alloc a;
          _data = a.allocate(_capacity);
          for (int index(0); index < _size; ++index) {
            a.construct(_data + index, *(other._data + index));
          }
        }
        ~myVector() {
          if (_data == NULL)
            return;
          Alloc a;
          for (int index = 0; index < _size; ++index)
            a.destroy(_data + index);
          a.deallocate(_data, _capacity);
          _capacity = 0;
          _size = 0;
        }
         // Copy Operator
        myVector& operator=(const myVector &other) {
          if (other._data == _data)
            return *this;
          Alloc a;
          for (int index = 0; index < _size; ++index)
            a.destroy(_data + index);
          a.deallocate(_data, _capacity);
          _data = a.allocate(other._capacity);
          for (int index(0); index < other._size; ++index) {
            a.construct(_data + index, (other._data)[index]);
          }
          _size = other._size;
          _capacity = other._capacity;
          return *this;
        }
         // Iterator
        typedef T *iterator;
        typedef const T *const_iterator;
        inline iterator begin() {
          return _data;
        }
        inline const_iterator begin() const {
          return static_cast<const_iterator>(_data);
        }
        inline iterator end() {
          return _data + _size;
        }
        inline const_iterator end() const {
          return static_cast<const_iterator>(_data + _size);       
        }
         // Capacity
        inline std::size_t size() {
          return _size;
        }
        void resize(const std::size_t &newSize) {
          resize(newSize, T());
        }
        void resize(const std::size_t &newSize, const T &val) {
          Alloc a;
          if (newSize <= _size) {
            for (int index(newSize); index < _size; ++index)
              a.destroy(_data + index);
          } else if (newSize <= _capacity) {
            for (int index(_size); index < newSize; ++index)
              a.construct(_data + index, val);
          } else {
            T *temp = a.allocate(newSize);
            for (int index(0); index < _size; ++index) {
              a.construct(temp + index, _data[index]);
              a.destroy(_data + index);
            }
            a.deallocate(_data, _capacity);
            for (int index(_size); index < newSize; ++index) {
              a.construct(temp + index, val); 
            }
            _data = temp;
            _capacity = newSize;
          }
          _size = newSize;
        }
        inline std::size_t capacity() const {
          return _capacity;
        }
        inline bool empty() const {
          return !_size;
        }
         // Element Access
        void reserve(const std::size_t &newCapacity) {
          if (newCapacity > _capacity) {
            Alloc a;
            T *temp = a.allocate(newCapacity);
            for (int index(0); index < _size; ++index) {
              a.construct(temp + index, _data[index]);
              a.destroy(_data + index);
            }
            a.deallocate(_data, _capacity);
            _data = temp;
            _capacity = newCapacity;
          }
        }
        inline T& operator[](const std::size_t & index) {
          if (index < _size)
            return _data[index];
        }
        inline const T& operator[](const std::size_t & index) const {
          if (index < _size)
            return static_cast<const T&>(_data[index]);
        }
        inline T& front() {
          if (_size)
            return _data[0];
        }
        inline const T& front() const {
          if (_size)
            return static_cast<const T&>(_data[0]);
        }
        inline T& back() {
          if (_size)
            return _data[_size - 1];
        }
        inline const T & back() const {
          if (_size)
            return static_cast<const T&>(_data[_size - 1]);
        }
        inline T* data() {
          return _data;
        }
         // Modifiers
        inline const T* data() const {
          return static_cast<const T*>(_data);
        }
        template<typename InputIterator>
        void assign(InputIterator begin, InputIterator end) {
          Alloc a;
          if (end - begin > _capacity) {
            clear();
            _data = a.allocate(end - begin);
            _capacity = end - begin;
          }
          auto temp = _data;
          for (auto i = begin; i != end; ++i) {
            a.construct(temp, *i);
            ++temp;
          }
          _size = end - begin;
        }
        void assign(const std::size_t &newSize, const T &val) {
          Alloc a;
          if (newSize > _capacity) {
            clear();
            _data = a.allocate(newSize);
            _capacity = newSize;
          }
          _size = newSize;
         for (int index(0); index < _size; ++index)
          a.construct(_data + index);
        }
        void push_back(const T & val) {
          Alloc a;
          if (_size == _capacity)
            resize(_size * 5);
          a.construct(_data + _size, val);
          ++_size;
        }
        void pop_back() {
          Alloc a;
          if (_size) {
            --_size;
            a.destroy(_data + _size);
          }
        }
        void clear() {
          if (_data == NULL)
            return;
          Alloc a;
          for (int index = 0; index < _size; ++index)
            a.destroy(_data + index);
          _size = 0;
        }
     private:
        T* _data;
        std::size_t _size, _capacity;
};