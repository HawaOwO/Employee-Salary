#include "EmployeeSalary.h"
#include <iostream>
using namespace std;

void EmployeeSalary::setHour(double v) //function to set number of hour
{
	hour = v;
}

double EmployeeSalary::CalcSal() //function to calculate salary
{
	return hour * rate;
}

void EmployeeSalary::print()//function to print the salary
{
	cout  << CalcSal() ;
	
}
void EmployeeSalary::setCompare1(double totalC1) //function to set the number of total salaries of current staff
{
	tc1 = totalC1;
}

double EmployeeSalary::getCompare1() //function to get the number of total salaries of current staff
{
	return tc1;
}

