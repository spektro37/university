#include <iostream>
#include "checkarea.h"

using namespace std;

int checkArea(double x, double y, bool debugFlag)
{
	if(debugFlag)
	{
		cout << "***CheckArea started***" << endl;
	}
	int sectionNumber = 0;
	bool isInCircle = false, isInParabola = false,
	isOnTheLeftSide = false;

	/* This check is checking if coordinates are inside the
	 * parabola
	 */
	if(y + 0.5 * x * x - 4.0 * x <= 0)
	{
		isInParabola = true;
	}
	if(debugFlag)
	{
		cout << "***isInParabola = " << isInParabola << " ***"
			 << endl;
	}

	/* This check is checking if coordinates are inside the
	 * circle
	 */
	if((x - 4) * (x - 4) + (y - 8) * (y - 8) <= 16)
	{
		isInCircle = true;
	}
	if(debugFlag)
	{
		cout << "***isInCircle = " << isInCircle << " ***"
			 << endl;
	}

	/* This check is checking if coordinates are on the left
	 * side of the straight
	 */
	if(x <= 4)
	{
		isOnTheLeftSide = true;
	}
	if(debugFlag)
	{
		cout << "***isOnTheLeftSide = " << isOnTheLeftSide
			 << " ***" << endl;
	}

	/* This series of checks returns the number of the area
	 * coordinates fall into
	 */
	if(isInCircle && !isInParabola && isOnTheLeftSide)
		sectionNumber = 1;
	else if(isInCircle && !isInParabola && !isOnTheLeftSide)
		sectionNumber = 2;
	else if(isInCircle && isInParabola && isOnTheLeftSide)
		sectionNumber = 3;
	else if(isInCircle && isInParabola && !isOnTheLeftSide)
		sectionNumber = 4;
	else if(!isInCircle && isInParabola && isOnTheLeftSide)
		sectionNumber = 5;
	else if(!isInCircle && isInParabola && !isOnTheLeftSide)
		sectionNumber = 6;
	else if(!isInCircle && !isInParabola && isOnTheLeftSide)
		sectionNumber = 7;
	else
		sectionNumber = 8;
	if(debugFlag)
	{
		cout << "***sectionNumber: " << sectionNumber << " ***"
			 << endl;
		cout << "***CheckArea finished***" << endl;
	}
    return sectionNumber;
}
