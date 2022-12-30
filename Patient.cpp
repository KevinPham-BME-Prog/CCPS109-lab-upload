#include "Patient.h"

Patient::Patient(string name, int healthcard, condition status, int cervix){
    this->name = name;
    this->healthcard = healthcard;
    this->status = status;
    this->cervix = cervix;
}

Patient::~Patient(){
    
}
const string& Patient::getName(){
    return name;
}

const int Patient::getHealthcard(){
    return healthcard;
}

const condition Patient::getCondition(){
    return status;
}

const int Patient::getcervix(){
    return cervix;
}
