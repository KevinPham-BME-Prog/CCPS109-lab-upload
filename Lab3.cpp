#include <iostream>
#include <cstdlib>
#include "Lab3.h"
//implement the function accessSalaryArrayByPointerArithmetic
//implement the function sortIntegersByPointerArithmetic
int main(int argc, char* argv[]) {
	string p1("part1");
	string p2("part2");
	if (0 == p1.compare(argv[1])) { //PART I
		//WRITE THE CODE FOR Part I HERE.
		int salary[3];
		for (int i = 0; i < 3; i++) {
			cout << "Enter Salary: ";
			cin >> *(salary + i);
			cout << endl;
		}
		cout << "The entered salaries are: " << endl;
		for (int y = 0; y < 3; y++) {
			cout << *(salary + y) << " ";
		}
	}
	if (0 == p2.compare(argv[1])) { //PART II
		//WRITE THE CODE FOR Part I HERE.
		int nums[10];
		for (int i = 0; i < 10; i++) {
			*(nums + i) = atoi(argv[2 + i]);
		}
		int temp;
		int referencea = 1;
		int referenceb = 1;
		while (referenceb != 10) {
			if (referencea == 0) {
				referencea = referenceb++;
			}
			else if ((*(nums + referencea)) > *((nums + referencea - 1))) {
				temp = *(nums + referencea);

			}
		}
	}
} //end of main