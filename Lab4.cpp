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


#include <iostream>
#include <cstdlib>
#include "Lab4.h"
using namespace std;
struct PatientRecord {
	string firstName;
	string surName;
	bloodtype bloodType;
	organ organType;
	int age;
	int yearAdded;
};
int intro(int patient) {
	int response = 0;
	while ((response > 4) || (response <= 0)) {
    	cout << "There are currently " << patient << " patient (s) in the list" << endl;
    	cout << "Please choose an option" << endl;
    	cout << "1. Add Patient" << endl;
    	cout << "2. Show List of Patients" << endl;
    	cout << "3. Save List of Patients" << endl;
    	cout << "4. Quit" << endl;
    	cin >> response;
    	if ((response > 4) && (response < 0)) {
        	cout << "Invalid entry" << endl;
        	cin >> response;
    	}
	}
	return response;
}
void processToken(int tokNum, string& tok, PatientRecord& patients) {
	if (1 == tokNum) patients.firstName = tok;
	if (2 == tokNum) patients.surName = tok;
	if (3 == tokNum) {
    	if (tok == "A") patients.bloodType = A;
    	else if (tok == "B") patients.bloodType = B;
    	else if (tok == "AB") patients.bloodType = AB;
    	else if (tok == "O") patients.bloodType = O;
    	else cout << "Invalid entry" << endl;
	}
	if (4 == tokNum) {
            if ((0 == tok.compare("heart")) ||(0 == tok.compare("Heart"))) {
                patients.organType = Heart;
            }
            else if ((0 == tok.compare("kidney")) || (0 == tok.compare("Kidney"))) {
                patients.organType = Kidney;
            }
            else if ((0 == tok.compare("lung")) || (0 == tok.compare("Lung"))) {
                patients.organType = Lung;
        }
            else if ((0 == tok.compare("liver")) ||(0 == tok.compare("liver"))) {
                patients.organType = Liver;
        }
            else cout << "Invalid entry" << endl;
	}
	if (5 == tokNum) patients.age = atoi(tok.c_str());
	if (6 == tokNum) patients.yearAdded = atoi(tok.c_str());
}
void tokenizeAndFillup(stringstream& aStrStream, PatientRecord& patients) {
	string token;
	int tokenNumber = 1;
	while (aStrStream >> token) {
    	processToken(tokenNumber, token, patients);
    	tokenNumber = tokenNumber + 1;
	}
}
void patiententry(PatientRecord& patients) {
	string entry;
	cout << "[Add Patient]" << endl;
	cout << "Please enter the Patient Record: \n" << endl;
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, entry, '\n');
	stringstream ss;
	ss.str(entry);
	tokenizeAndFillup(ss, patients);

}
void inputpatientlist(PatientRecord& patiententry, PatientRecord patientlist[], int currentindex) {
	int i = currentindex;
	patientlist[i].firstName = patiententry.firstName;
	patientlist[i].surName = patiententry.surName;
        string blood;
                string organs;
                if (patiententry.bloodType == A) {
                    patientlist[i].bloodType = A;
                }
                else if (patiententry.bloodType == B) {
                    patientlist[i].bloodType = B;
                }
                else if (patiententry.bloodType == AB) {
                    patientlist[i].bloodType = AB;
                }
                else if (patiententry.bloodType == O) {
                    patientlist[i].bloodType = O;
                }
                if (patiententry.organType == 0){
                    patientlist[i].organType = Heart;
                }
                else if (patiententry.organType == 1){
                    patientlist[i].organType = Kidney;
                }
                else if (patiententry.organType == 2){
                    patientlist[i].organType = Lung;
                }
                else if (patiententry.organType == 3){
                    patientlist[i].organType = Liver;
                }
	patientlist[i].age = patiententry.age;
	patientlist[i].yearAdded = patiententry.yearAdded;
}
void printscreen(PatientRecord patientlist[], int patients) {
	cout << "[Show List of Patients]" << endl;
	cout << "ID\tName\t\tBlood\tOrgan\tAge\tYear added" << endl;
	cout << "----------------------------------------------------------" << endl;
        string blood;
    	string organs;
        string listpat;
	for (int i = 0; i < patients; i++) {
    	listpat = patientlist[i].surName;
    	char patlist = (patientlist[i].firstName)[0];
        int p_age = patientlist[i].age;
    	int p_year = patientlist[i].yearAdded;
        cout << i + 1<< "\t" << listpat << ", " << patlist;
    	if (patientlist[i].bloodType == A) {
        	blood = 'A';
    	}
    	else if (patientlist[i].bloodType == B) {
        	blood = 'B';
    	}
    	else if (patientlist[i].bloodType == AB) {
        	blood = "AB";
    	}
    	else if (patientlist[i].bloodType == O) {
        	blood = 'O';
    	}
        if (patientlist[i].organType == 0){
            organs = "Heart";
        }
        else if (patientlist[i].organType == 1){
            organs = "Kidney";
        }
        else if (patientlist[i].organType == 2){
            organs = "Lung";
        }
        else if (patientlist[i].organType == 3){
            organs = "Liver";
        }
    	cout << "\t\t  " << blood << "\t" << organs << "\t" << p_age << "\t" << p_year << endl;
	}
}
int main(int argc, char* argv[]) {
	PatientRecord newpatient;
	PatientRecord patientlist[20];
	int answer = 0;
	int patient = 0;
        int patientqueue = 0;
        if (argc == 2){
            string myText;
            stringstream ss;
            ifstream MyFile(argv[1]); //needs to be moved
            getline(MyFile, myText);
            while(getline(MyFile, myText)){
                ss.str(myText);
                tokenizeAndFillup(ss, newpatient);
                ss.str("");
                ss.clear();
                inputpatientlist(newpatient, patientlist, patient);
                patient += 1;
            }
            MyFile.close();
        }
	while (answer < 4) {
    	answer = intro(patient);
    	if (answer == 1) {
        	patiententry(newpatient);
        	inputpatientlist(newpatient, patientlist, patient);
        	patient += 1;
    	}
    	else if(answer == 2) {
        	printscreen(patientlist, patient);

    	}
        else if(answer == 3){
            ofstream MyFile("transplantPatients.txt");
            MyFile << "Patient " << patient << endl; 
            for (int i = 0 + patientqueue; i < patientqueue + patient; i++){
                MyFile << patientlist[i].firstName << " ";
                MyFile << patientlist[i].surName << " ";
                string blood;
                string organs;
                if (patientlist[i].bloodType == A) {
                    blood = 'A';
                }
                else if (patientlist[i].bloodType == B) {
                    blood = 'B';
                }
                else if (patientlist[i].bloodType == AB) {
                    blood = "AB";
                }
                else if (patientlist[i].bloodType == O) {
                    blood = 'O';
                }
                if (patientlist[i].organType == 0){
                    organs = "Heart";
                }
                else if (patientlist[i].organType == 1){
                    organs = "Kidney";
                }
                else if (patientlist[i].organType == 2){
                    organs = "Lung";
                }
                else if (patientlist[i].organType == 3){
                    organs = "Liver";
                }
                MyFile << blood << " " << organs << " " << patientlist[i].age << " " << patientlist[i].yearAdded << " " << endl;
                
            }
            MyFile.close();
        }

	}
}








