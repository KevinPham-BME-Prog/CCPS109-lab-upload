#include "Circle.h"


Circle::Circle(){
    
}
Circle::Circle(float radius, string color): Shape(color){
    this->radius;
}
const int Circle::getRadius(){
    return radius;
}
void Circle::print(){
     cout << "Circle R = " << radius << ", area = " << radius*radius*M_PI << ", " << getColor() << endl;
}

Circle::~Circle(){
    
}
