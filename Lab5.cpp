#include <cstdlib>
#include "OTPRegister.h"

using namespace std;

/*
 * 
 */
int main() {
    int option = 0;
    OTPRegister enPatient;
    cout << "There are currently 0 patient(s) in the list \n" << endl;

    
    while (option != 4){
        cout << "Please choose an option:" << endl;
        cout << "1.\tRegister Patient" << endl;
        cout << "2.\tExamine Patient" << endl;
        cout << "3.\tDisplay Patient" << endl;
        cout << "4.\tQuit"<< endl;
        cin >> option;
        if (option == 1){
            cout << "[Register Patient]" << endl;
            string PNAME;
            int HC;
            cout <<"Enter Name: ";
            cin >> PNAME;
            cout << "Enter Health Card Number: ";
            cin >> HC;
            cout << "\n==============" << endl;
            enPatient.enroll(PNAME, HC);
        }
        else if (option == 2){
            enPatient.examine();
        }
        else if (option == 3){
            enPatient.display();
        }
    }
    return 0;
}
