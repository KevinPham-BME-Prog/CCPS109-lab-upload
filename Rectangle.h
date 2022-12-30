#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
class Rectangle: public Shape{
private:
    float length;
    float breadth;
public:
    Rectangle(); Rectangle(float, float, string); void print(); virtual ~Rectangle();
};


#endif /* RECTANGLE_H */
