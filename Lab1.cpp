#include "Lab1.h"

string enterDNAString() {
    string DNA;
    cout << "Please enter the DNA string:";
    cout << ">> ";
    cin >> DNA;
    return DNA;
}

bool checkValidity(string s) {
    string nucleotide = "agctAGCT";
    int total = s.size();
    for (int count = 0; count < total; count++) {
        size_t found = nucleotide.find(s[count]);
        if (found == -1) {
            return false;
        }
    }
    return true;
}
void compliment(string s) {
    bool comp = true;
    string result = "";
    int total = s.size();
    for (int count = 0; count < total; count++) {
        if (s[count] == 'a') {
            result = result + 't';
        }
        else if (s[count] == 'A') {
            result = result + 'T';
        }
        else if (s[count] == 'c') {
            result = result + 'g';
        }
        else if (s[count] == 'C') {
            result = result + 'G';
        }
        else if (s[count] == 'g') {
            result = result + 'c';
        }
        else if (s[count] == 'G') {
            result = result + 'C';
        }
        else if (s[count] == 't') {
            result = result + 'a';
        }
        else if (s[count] == 'T') {
            result = result + 'A';
        }
        else {
            comp = false;
        }
    }
    if (comp == true) {
        cout << " : compliment (" << s << ") = " << result;
    }
    else {
        cout << endl;
    }
}
int main() {
    while (true) {
        cout << "Please choose an option:" << endl;
        cout << "1. Enter DNA string, echo it" << endl;
        cout << "2. Enter DNA string, echo it, validate it" << endl;
        cout << "3. Enter DNA string, echo it, validate it, compliment it if valid" << endl;
        cout << "4. Exit" << endl;
        int option;
        cout << ">> ";
        cin >> option;
        if (!cin) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Non-numeric option! Try again." << endl;
            continue;
        }
        if (1 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            cout << endl;
        }
        else if (2 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            bool b = checkValidity(str1);
            if (b == true)
                cout << " : VALID DNA";
            else
                cout << " : INVALID DNA";
            cout << endl;
        }
        else if (3 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            bool b = checkValidity(str1);
            if (b == true)
                cout << " : VALID DNA";
            else
                cout << " : INVALID DNA";
            compliment(str1);
            cout << endl;
        }
        else if (4 == option) {
            return 0;
        }
        else {
            cout << "Integer option, but incorrect! Try again." << endl;
        }
    }
    return 0;
}

