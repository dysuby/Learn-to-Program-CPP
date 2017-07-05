# ArrayList

## Task
ArrayList与std::vector类似，是一个增强版的数组。   
根据给出的头文件，完成相应方法的实现。
## Hints
- storage指向一块大小为_maxsize（动态分配）的内存空间，用于存储ArrayList的元素
- _size表示当前ArrayList的大小（有效元素）
- 当内存空间已满时，调用extend()进行扩容
- 扩容策略为指数扩容，`_maxsize *= extend_factor`
- 为简化，不考虑缩容问题以及`E& get(int index)`与`E& operator[](int index)`中index越界问题
- `void remove(E e)`将移除ArrayList中**所有值与e相等的元素**
- `int indexOf(E element)`返回element在ArrayList中**第一次出现的索引位置**。若未找到，返回-1
## Other
改编自《Collection with Inheritance》（叶嘉琪）
