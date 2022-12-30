#include "OTPRegister.h"

OTPRegister::OTPRegister(){
    cout << "There are currently 0 patient(s) in the list \n" << endl;
}
OTPRegister::~OTPRegister(){
    int size = q.size();
    for(int i = 0; i < size; ++i){
        delete q[i];
        q[i] = 0;
    }

}
void OTPRegister::enroll(string name, int healthcard){
    cout << ".. [Register]" << endl;
    cout << "\n==============" << endl;
    condition status = UNKNOWN;
    int cervix = 0;
    Patient * p = new Patient(name, healthcard, status, cervix);
    q.push_back(p);
    cout << "There are currently " << q.size() << " patient(s) in the list \n" << endl;

}
void OTPRegister::examine(){
    cout << "[Examine Patient]" << endl;
    if (q.empty()){
        cout << "There are 0 patient(s) in the list" << endl;
    }
    else{
        Patient * p = q[0];
        q.pop_front();
        string pname = p->getName();
        int hc = p->getHealthcard();
        cout << "Name: " << pname << endl;
        cout << "Health Card Number: " << hc << endl;
        cout << "Enter Cervix Dilation: ";
        int cervixd;
        cin >> cervixd;
        if (cervixd  >= 4 ){
            cout << ".. [Admitting]" << endl;
            cout << pname << "  " << hc << "  " << cervixd << " ADMIT" << endl;
Patient * p = new Patient(pname, hc, status, cervixd);
            q.push_back(p);

        }
        else{
            cout << ".. [Going back to queue]" << endl;
            condition status = LABOUR;
            Patient * p = new Patient(pname, hc, status, cervixd);
            q.push_back(p);
        }
    }
    cout << "\n==============" << endl;
    cout << "There are currently " << q.size() << " patient(s) in the list \n" << endl;

}

void OTPRegister::display(){
    cout << "[Display Patient]" << endl;
    if (q.empty()){
        cout << "\n==============" << endl;
    }
    else{
        for(int i = 0; i < q.size(); i++){
            Patient * p = q[i];
            string pname = p->getName();
            int hc = p->getHealthcard();
            int cervixid = p->getcervix();
            condition status = p->getCondition();
            if (status == 0){
                cout << pname << "  " << hc << "  " << cervixid << " UNKNOWN" << endl;
            }
            else{
                cout << pname << "  " << hc << "  " << cervixid << " LABOUR" << endl;
            }
        }
    }
    cout << "\n==============" << endl;
    cout << "There are currently " << q.size() << " patient(s) in the list \n" << endl;


}
