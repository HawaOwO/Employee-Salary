#include "Update.h"
#include "EmployeeSalary.h"
#include <iostream>
using namespace std;


void Update::setStaff(int sta) //function to set number of updated staff
{
	staff = sta;
}

void Update::setCompare2(double totalC2) //function to set the number of total salaries of updated staff
{
	tc2 = totalC2;
}
double Update::getCompare2() //function to get the number of total salaries of updated staff
{
	return tc2;
}

void Update::Design() //Print interface
{
	cout << "*************************************************************************************" << endl;
}

