#pragma once
#ifndef UPDATE_H
#define UPDATE_H
#include "EmployeeSalary.h"

class Update : public EmployeeSalary //inheritance from EmployeeSalary class
{
private : 
	double upSal; //variable for update staff salary
	double staff; //variable for number of updated staff
	
protected:
	double tc2; //variable for total salary of updated staff to compare
public : 
	void setStaff(int); //function to set number of staff
	Update() { upSal = 0.0; tc2 = 0.0; staff = 0.0; } //constructor
	~Update() { upSal = 0.0; tc2 = 0.0; staff = 0.0; } //destructor
	void setCompare2(double); //function to set the number of total salaries of updated staff
	double getCompare2(); //function to get the number of total salaries of updated staff
	void Design(); //function to call design 
};

#endif 


