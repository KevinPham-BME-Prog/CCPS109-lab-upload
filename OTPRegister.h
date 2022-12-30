#ifndef OTPREGISTER_H
#define OTPREGISTER_H
#include "Patient.h"
#include <iostream>
#include <deque>
using namespace std;
class OTPRegister{
private:
    deque<Patient * > q;
public:
    OTPRegister(); ~OTPRegister(); void enroll(string, int); void examine(); void display();
};
#endif /* OTPREGISTER_H */
