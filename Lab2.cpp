#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "Lab2.h"

void initialize(double& k, int& n0) {
    cout << "Initializing Bacteria:" << endl;
    cout << "\t" << "Enter the Growth factor (k) [0.0-1.0] : ";
    cin >> k;
    while (k > 1.0 || k < 0) {
        cout << "Invalid entry try again: \n" << endl;
        cout << "\t" << "Enter the Growth factor (k) [0.0-1.0] : ";
        cin >> k;
    }
    cout << "\t" << "Enter the Initial population (N0) [1-1000] : ";
    cin >> n0;
    while ((n0 < 1.0) || (n0 > 1000)) {
        cout << "Invalid entry try again:" << endl;
        cout << "\t" << "Enter the Initial population (N0) [1-1000] : ";
        cin >> n0;
    }

}
void calculate(const double k, const int n0, double array[]) {
    int i = 0;
    do {
        *(array + i) = n0 * (exp(k * i));
        i++;
    } while (i <= 10);
}
void display(const double array[]) {
    cout << "\n";
    cout << "\t Growth Summary:" << endl;
    cout << "\t Hour \t Population" << endl;
    cout << "\t ==== \t ==========" << endl;
    for (int i = 0; i < 11; i++) {
        cout << setw(12) << i << setw(15) << setprecision(3) << fixed << array[i] << endl;
    }

}
void twoDdisplay(int num, const double arr[][11]) {
    cout << "\n";
    cout << "\t Agar Summary \n";
    cout << "\t Hour \t";
    for (int y = 0; y < num; y++) {
        cout << "Population (" << (y) << ") \t";
    }
    cout << endl;
    cout << "\t ====";
    for (int e = 0; e < num; e++) {
        cout << "=================";
        if (e >= 10) {
            cout << "=";
        }
    }
    cout << endl;
    for (int t = 0; t < 11; t++) {
        cout << setw(12) << t << "\t ";
        for (int x = 0; x < num; x++) {
            cout << setw(12) << setprecision(3 << fixed) << arr[x][t] << "\t ";
        }
        cout << endl;
    }

}

int main(int argc, char* argv[]) {
    double k;
    int n0;
    double poparray[11];
    if (1 == argc) { //Part I
        //WRITE THE CODE FOR Part I HERE.
        initialize(k, n0);
        calculate(k, n0, poparray);
        //work on output functions
        display(poparray);
    }
    else if (2 == argc) { //Part III
        //WRITE THE CODE FOR Part III HERE.

        int pops;
        pops = atoi(argv[1]);
        double multiarray[15][11];
        for (int r = 0; r < pops; r++) {
            initialize(k, n0);
            calculate(k, n0, poparray);
            for (int x = 0; x < 11; x++) {
                multiarray[r][x] = poparray[x];
            }
        }
        twoDdisplay(pops, multiarray);
        //get the integer value from the main function input (done) and from there generate a 2d array
        //then in a for loop generate x amount of 1d arrays with the calculate() function
        // combine them into the singular 2d-array
        // develop the multiple population output
        //double multipop[population][11];
    }
    else if (3 == argc) {
        k = atof(argv[1]);
        n0 = atoi(argv[2]);
        if (k < 0 || k > 1) {
            cout << "Invalid Growth Factor " << endl;
        }
        else if (n0 < 1 || n0 > 1000) {
            cout << "Invalid Population Value" << endl;
        }
        else {
            cout << "\t" << "Enter the Growth factor (k) [0.0-1.0] : " << k << endl;
            cout << "\t" << "Enter the Initial population (N0) [1-1000] : “ << n0 << endl;
                calculate(k, n0, poparray);
            display(poparray);
        }

        //Part II
        //WRITE THE CODE FOR Part II HERE.
        //find a way to convert string to integer from there find the values using calculate()
        // display output
    }
    else {
        cout << "Number of command-line arguments "
            << "(including the name of the program) "
            << "should be three or less." << endl;
    }
} //end of main


