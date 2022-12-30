#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <cmath>
using namespace std;
class Shape{
private:
    string color;
public:
    Shape(); Shape(string); const string& getColor(); virtual void print(); virtual ~Shape();
    
};


#endif /* SHAPE_H */
