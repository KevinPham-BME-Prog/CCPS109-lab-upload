#ifndef LAB4_H
#define LAB4_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
enum bloodtype { A, AB, O, B };
enum organ { Heart, Kidney, Lung, Liver };
using namespace std;
struct PatientRecord;
int intro(int patient);
void processToken(int tokNum, string& tok, PatientRecord& patients);
void tokenizeAndFillup(stringstream& aStrStream, PatientRecord& patients);
void patiententry(PatientRecord& patients);
void inputpatientlist(PatientRecord& patiententry, PatientRecord patientlist[], int currentindex);
void printscreen(PatientRecord patientlist[], int patients);
//WRITE THE REMAINING CODE HERE.
#endif /* LAB4_H */



