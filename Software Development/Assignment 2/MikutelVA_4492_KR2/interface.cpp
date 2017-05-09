#include <iostream>
#include "task.h"

using namespace std;

int choise;

int main(void)
{
	cout << "Please select one of the options: \n"
		 << "1 - Output a sequence of triangular numbers.\n"
		 << "2 - Output a sequence of triangular numbers in the specified range.\n"
		 << "3 - Input a sequence of triangular numbers with calculation." << endl;

	cin >> choise;


	return 0;
}
