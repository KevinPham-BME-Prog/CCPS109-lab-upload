#include "Rectangle.h"
Rectangle::Rectangle(){
    
}
Rectangle::Rectangle(float breadth, float length, string color): Shape(color){
    this->breadth = breadth;
    this->length = length;
}

void Rectangle::print(){
    cout << "Rectangle L = " << length  << ", B = " << breadth << ", area = " << length*breadth << ", " << getColor() << endl;
}
Rectangle::~Rectangle(){
    
}
