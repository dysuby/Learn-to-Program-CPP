#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <cmath>
#define MAX 100
#define MIN -100
#define max(a,b) ((a) > (b) ? (a) : (b))
#define square(a) ((a) * (a))
#define e(a,b) ((a) * pow(10,b))
#define str(a) #a
#define mstr(a) str(a)
#define WARN_IF(a) ((a) ? printf("Warning: "#a"\n") : 1)
#endif