# LinkedList

## Task
LinkedList与std::list类似，是一个双向链表。  
根据给出的头文件，完成相应方法的实现。
## Hints
- head指向链表头部，tail指向链表尾部，_size表示当前LinkedList的大小
- `E& operator[](int index)`和`E& get(int index)`中，若index非法，直接返回`*reinterpret_cast<E*>(NULL)`即可
- `void remove(E e)`将移除LinkedList中**所有值与e相等的元素**
- `int indexOf(E element)`返回element在LinkedList中**第一次出现的索引位置**。若未找到，返回-1
- 注意边界情况的考虑：空链表、位于链表头部、位于链表尾部等
## Other
改编自《Collection with Inheritance》（叶嘉琪）
