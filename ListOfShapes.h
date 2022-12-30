#ifndef LISTOFSHAPES_H
#define LISTOFSHAPES_H
#include"Rectangle.h"
#include"Circle.h"
#include <vector>
class ListOfShapes: public Circle, public Rectangle{
private:
    vector <Shape*> Shapes;
public:
    ListOfShapes(); ~ListOfShapes(); void addShape(Shape*); void removeShape(); void displayShapes();
};


#endif /* LISTOFSHAPES_H */
