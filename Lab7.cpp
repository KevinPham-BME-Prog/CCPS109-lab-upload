#include "Lab7.h"
Factory* Factory::instance = 0;
Factory::Factory() {}
Factory* Factory::getInstance() {
    if (instance == 0) {
   	 instance = new Factory();
    }
    return instance;
}
Product* Factory::createProduct(int z) {
    Product* prod = new Product(z);
    return prod;
}

int main(int argc, char* argv[]) {
    Factory* f = Factory::getInstance();
    Product* p1 = f->createProduct(5);
    Product* p2 = f->createProduct(6);
    cout << p1->getID() << endl;
    cout << p2->getID() << endl;
    return 0;
}
