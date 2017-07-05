# Point & Vector about overloading

## Description
There are many points in the plane. We can use a vector to move a point from here to there.

The following requirements should be satisfied.

(Given Vector a, b; Point c;)

1.The Point and Vector can be output directly from the standard output stream. The form like this, `cout << a;` The format of output includes the coordinate of x-axis and y-axis with a space between them. The implementation of the overloading of output operator **don't need to print newline**.

2.Overload the addition of two Vector,like `a = a + b;`

3.Overload the addition between Point and Vector, represented the Point moving along with the Vector. like `c = c + a;`

You should submit the definition and implementation of the two classes. No `main()` function should be included.