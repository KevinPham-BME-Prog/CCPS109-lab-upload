#include <iostream>
#include <cstdlib>
#include "Lab3.h"
//implement the function accessSalaryArrayByPointerArithmetic
//implement the function sortIntegersByPointerArithmetic
void accessSalaryArrayByPointerArithmetic(){
    int salary[3];
    for (int i = 0; i < 3; i++) {
        cout << "Enter Salary: ";
        cin >> *(salary + i);
        cout << endl;
   }
    cout << "The entered salaries are: " << endl;
    for (int y = 0; y < 3; y++) {
        cout << *(salary + y) << " " << endl;
    }
    cout << "Updated salaries are: " << endl;
    for (int i = 0; i < 3; i++){
        *(salary + i) = *(salary + i) + *(salary + i)/(i + 1);
        cout << *(salary + i) << " ";
    }
}
int* sortIntegersByPointerArithmetic(int* arr, int size){
    int temp;
    int referencea = 1;
    int referenceb = 1;
    while (referenceb != size + 1) {
    if (referencea == 0) {
   	referencea = referenceb++;
    }
    else if ((*(arr + referencea)) < *((arr + referencea - 1))) {
   	temp = *(arr + referencea);
        *(arr + referencea) =  *(arr + referencea -1);
        *(arr + referencea -1) = temp;
        referencea--;
   	}
                 else{
                    referencea--;
                 }
   	 }
    return arr;
}
int main(int argc, char* argv[]) {
    string p1("part1");
    string p2("part2");
    if (0 == p1.compare(argv[1])) { //PART I
   	 //WRITE THE CODE FOR Part I HERE.
   	 accessSalaryArrayByPointerArithmetic();
    }
    if (0 == p2.compare(argv[1])) { //PART II
   	 //WRITE THE CODE FOR Part I HERE.
         int size = (argc - 2); 
   	 int nums[size];
         for (int i = 0; i < (size); i++) {
   		 *(nums + i) = atoi(argv[2 + i]);
   	 }
         sortIntegersByPointerArithmetic(nums, size);
         cout << "The numbers in ascending order are: " << endl;
         for (int x = 0; x < 10; x++){
            cout << *(nums + x) << " ";
         }
    }
} //end of main

