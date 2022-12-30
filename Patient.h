#ifndef PATIENT_H
#define PATIENT_H
#include <iostream> 
using namespace std;
enum condition{UNKNOWN, LABOUR, ADMIT};
class Patient{
private:
    string name;
    int healthcard;
    condition status; //unknown, labour, admit
    int cervix;
public:
    Patient(string, int, condition, int); ~Patient();
    const string& getName(); const int getHealthcard(); const condition getCondition(); const int getcervix();
};

#endif /* PATIENT_H */
