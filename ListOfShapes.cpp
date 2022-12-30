#include "ListOfShapes.h"

ListOfShapes::ListOfShapes(){
    
}

void ListOfShapes::addShape(Shape* shp){
    Shapes.push_back(shp);
    cout << "There are currently " << Shapes.size() <<" shape(s) in the list " << endl;
}

void ListOfShapes::displayShapes(){
    int duration = Shapes.size();
    if (duration == 0){
        cout << "No Shapes in vector" << endl;
    }
    else{
        for (int i = 0; i < Shapes.size(); i++){
            Shape* shp = Shapes[i];
            shp->print();
        }
    }
    cout << "There are currently " << Shapes.size() <<" shape(s) in the list " << endl;
}
void ListOfShapes::removeShape(){
    Shape* shp = Shapes[Shapes.size()-1];
    Shapes.pop_back();
    delete shp; shp = 0;
    cout << "There are currently " << Shapes.size() <<" shape(s) in the list " << endl;

}
ListOfShapes::~ListOfShapes(){
    
}
