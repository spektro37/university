/* This programm was written by Mikutel Vladislav Aleksandrovich
 * group No.4492
 * It is designed to determine the number of the area,
 * coordinates provided by the user belong to
 */

#include <iostream>
#include <checkarea.h>
#include <limits.h>

using namespace std;
int areaNumber;
double x, y;
bool debugFlag = false;
char startAgain;

int main(void)
{
	//Start of execution
	do
	{
		if(debugFlag) {
			cout << "***Program is running in debug mode***"
				 << endl;
		}
		//Getting X
		cout << "Please enter the X and Y coordinates in order."
			 << endl;
		cout << "Please enter X:" << endl;
		cin >> x;
		/* If entered something other than a numeric value, an
		 * error message will be displayed
		 */
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "Inavlid X, please input a numeric value."
				 << endl;
		}
		//Getting Y
		else
		{
			cout << "Please enter Y:" << endl;
			cin >> y;
			/* If entered something other than a numeric value,
			 * an error message will be displayed
			 */
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				cout << "Inavlid Y, please input a numeric value."
					 << endl;
			}
			/* If both X and Y are valid, the areaCheck() function
			 * will be called and it will return the number of the
			 * area, coordinates belong to
			 */
			else
			{
				areaNumber = checkArea(x, y, debugFlag);
				cout << "Entered coordinates are:" << endl;
				cout << "x = " << x << endl;
				cout << "y = " << y << endl;
				cout << "And they belong to the area number "
					 << areaNumber << "." << endl;
			}
		}
		//Request to continue program execution
		cout << "Do you want to start again?" << endl;
		cin >> startAgain;
		cin.clear();
		cin.ignore(INT_MAX,'\n');
	} while(startAgain == 'Y' || startAgain == 'y');
	return 0;
}
