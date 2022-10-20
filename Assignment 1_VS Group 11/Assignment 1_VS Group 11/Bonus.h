#pragma once
#ifndef BONUS_H
#define BONUS_H
#include "EmployeeSalary.h"
#include "Update.h"
#include <string>
#include <iostream>
using namespace std;

class Bonus
{
private:
	EmployeeSalary S; //Composition of class EmployeeSalary object S
	Update U; //Composition of class Update object U
	
public:
	Bonus() { } //constructor
	~Bonus() { } //destructor
	friend void Password(); //friend function for password validation
	friend bool operator==(Update, Update); //operator overloading == as a non member function
};

#endif 

