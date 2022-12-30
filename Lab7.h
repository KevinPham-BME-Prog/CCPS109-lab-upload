#ifndef LAB7_H
#define LAB7_H
#include <iostream>
using namespace std;
class Product {
private:
    int id;
public:
    Product(int i) { id = i; }
    int getID() { return id; }
};

class Factory {
public:
    static Factory* getInstance();
    Product* createProduct(int z);
    ~Factory();
private:
    static Factory* instance;
    Factory();
};

#endif
