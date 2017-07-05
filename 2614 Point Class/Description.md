# Point Class

If a point’s dimension is high, it is harder to deal with. But I trust you.

Given the below class:
```
class Point
{
private:
    int *data;
    int dimension;
public:
    Point(int);
		 Point(int*,int);
    Point operator+(const Point&);
    Point operator-(const Point&);
    Point& operator=(const Point&);
    void print();
};
```

You should initialize in the construct function, the parameter is the dimension of the point. 
Overload +, - and =. When a point add with another, we simply add all of their dimensions. Minus is same with add. 

If dimensions of the two points are different, we could do like (1,2,3,5)+(1,2,3)=(2,4,6,5).

If point A is (1,2,3,5), point B is (1,4,3), then A is (1,4,3) after the operation A=B. 
The print function prints information of the point, like (1,2,5).