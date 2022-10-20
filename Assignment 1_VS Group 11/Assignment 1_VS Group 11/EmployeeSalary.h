#pragma once
#ifndef EMPLOYEESALARY_H
#define EMPLOYEESALARY_H

class EmployeeSalary
{ 
protected:
	const double rate = 5.50; //the rate payment of salaries is RM 5.50
	double hour; //variable for number of hours 
	//double totalSalary; //variable for total salaries of the staff from text file
	double tc1; //variable of total salaries in a week 
	
public:
	EmployeeSalary() { hour = 0.0;  tc1 = 0.0; } //constructor
	~EmployeeSalary() { hour = 0.0; tc1 = 0.0;} //destructor
	void setHour(double); //function to set number of hour
	double CalcSal(); //function to calculate salary
	void print(); //function to print the salary
	void setCompare1(double); //function to set the number of total salaries of current staff
	double getCompare1(); //function to get the number of total salaries of current staff
};
#endif 


