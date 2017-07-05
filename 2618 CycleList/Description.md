# CycleList

某一天，小剑同学来到了一家饭店。
这家店有一个回转设置，然而它不同于正常的装置，吃法也与众不同，用小剑的话来说就是  
1.这个装置可以看作是一个循环的双向链表  
2.上面的每一份食物都作为一个节点而存在  
3.每次你可以选择从你面前拿走三碟菜，又或者走到一个pos处拿走三碟  
4.假设链表的长度为n，则 pos的范围为[0, n-1]  
5.当数目不足三个时，则全部拿走  
机智的小剑已经为你写好了头文件，假设你面前的菜便是head所在位置。也就是说，**当不指定位置时，你需要拿走的是head， head->front, head->next**
#### **注意，当输出链表时，包括最后一个菜名，每个菜名后面都跟着一个空格，无需换行**
#### 输入格式：第一行为数字n，接下来输入n个foodname，每个foodname间以空格隔开。然后输入数字m，接下来输入m个数字代表每次eat的pos，每个数字间以空格隔开
### Sample Input
```
5
beef potato chicken humburger chips
10
0 0 0 0 0 0 0 0 0 10
```
### Sample Output
```
Test 1
beef potato chicken humburger chips 
After eat
chicken humburger 
After eat

Test 2
beef potato chicken humburger chips 
After eat at pos : 0
chicken humburger 
After eat at pos : 0

After eat at pos : 0

After eat at pos : 0

After eat at pos : 0

After eat at pos : 0

After eat at pos : 0

After eat at pos : 0

After eat at pos : 0

After eat at pos : 10

Test 3
beef potato chicken humburger chips 
After a Big guys clear all

```

### Hint
vector容器可以像数组一样按照下标访问对应内容。其成员函数size返回其有效长度。  
```
// vector 遍历
for (int i = 0; i < vector.size(); i++) {
  // Todo
}
```