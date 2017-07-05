# Queue

## Task
Queue是一个用数组存储的循环队列。  
根据给出的头文件，完成相应方法的实现。
## Hints
- storage指向一块大小为max_size + 1（动态分配）的内存空间，用于存储Queue的元素
- max_size为Queue的容量
- head为队头索引，rear为队尾索引
- 当队列满时，push不作任何操作
- 当队列空时，pop不作任何操作，front()和back()都返回0
## Other
改编自《Stack And Queue》（叶嘉琪）
