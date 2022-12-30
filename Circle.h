#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle: public Shape{
private:
    float radius;
public:
    Circle(); Circle(float, string); const float getRadius(); void print(); virtual ~Circle();
};


#endif /* CIRCLE_H */
