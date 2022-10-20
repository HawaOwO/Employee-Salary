#include "EmployeeSalary.h" //header file of class EmployeeSalary
#include "Update.h" //header file of class Update
#include "Bonus.h" //header file of class Bonus
#include <iostream>
#include <fstream> //to use file
#include <string> //to use string
#include <iomanip>
using namespace std;

bool operator==(Update lhs, Update rhs) //friend function of operator overloading == 
{
    return lhs.getCompare1() == rhs.getCompare2(); //return true if the statement is true and otherwise false
}

void Password()  //function to validate the password of the manager before going into the system 
{
    string PW = "144A"; //the set password
    string pw;
    cout << "\n~~WELCOME TO THE HAPPY WORKERS ENTERPRISE~~ " << endl;
    do
    {
        cout << "ENTER YOUR PASSWORD : "; //get the password from the user
        cin >> pw;
        if (PW == pw) //check if the password is correct or not
            cout << "~YOU CAN ENTER THE SYSTEM~ \n" << endl;
        else
            cout << "!!PLEASE TRY AGAIN!!\n" << endl;
    } while (pw != PW); //repeat the loop until the correct password is given

}

int main()
{
    Update Up; //object of class Update
   
    double totalSal[5]; //array of total salaries of the current staff from the text file
    int totalHour[5]; //array of total hour of the current staff from the text file
    double total = 0, totalh = 0; //variable to store total salary in a week and total hour of a week
    int hourU; //variable hour for updated staff
    double value; //hour get from the text file
    double s; //temporary variable to store salary
    double staff; //number of updated staff
    double bonusrate; //number of bonus rate given from the user
    double totalCompare1 = 0, totalCompare2 = 0; //variable to compare the total salaries for a week

    Up.Design(); //display the design
    Password(); //call function of password
    Up.Design();
    ifstream infile; //declaration of input file

    cout << showpoint << setprecision(2) << fixed << endl;
    infile.open("EmployeeHour.txt"); //open file name "EmployeeHour.txt"
    cout << "    STAFF WORKING HOURS AND TOTAL SALARIES IN A WEEK \n\n";
    Up.Design();
    if (infile) //if the file can be open, proceed
    {

        for (int i = 0; i < 5;i++) //for loop to get the data from file
        {
            cout << "EMPLOYEE " << (i + 1) << endl;

            for (int j = 0; j < 7; j++)
            {
                infile >> value; //read value from input file
                Up.setHour(value); //set the hour to the EmployeeSalary class by using derived class object
                s = Up.CalcSal(); //assign the salary to the variable s
                cout << "\nDAY " << j + 1 << " : RM ";
                Up.print(); //print the salary
                total += s;  //add the salary of each day to total
                totalh += value; //add the hour of each day to totalh
                totalCompare1 += s; //add the salary of each day to this variable

            }
            totalSal[i] = total; // assign the total to the array
            totalHour[i] = totalh; // assign the hour to the array
            //display for each employee
            cout << "\nTOTAL HOUR : " << totalHour[i]<<" hours" << endl; 
            cout << "TOTAL SALARY : RM " << totalSal[i];
            cout << endl << endl;

            total = 0; //set the total to 0 for next employee
        }
    }
    else
        cout << "!!FILE CANNOT OPEN !!" << endl; //display if file cannot be open

    infile.close(); //close the file
    Up.Design();

    cout << "\n    ADD AND UPDATING THE STAFF \n" << endl;
    Up.Design();
    do //repeat the loop if invalid number of staff given
    {
    cout << "HOW MANY STAFF YOU WANT TO ADD : ";
    cin >> staff;
    } while (staff <= 0);

    double* totalSalary2; //declaration of dynamic array for updated staff salaries
    totalSalary2 = new double[staff];
    double* totalHour2; //declaration of dynamic array for updated staff hours
    totalHour2 = new double[staff];

    for (int i = 0; i < staff;i++)
    {
        do //repeat the loop if the hours get from the user is invalid
        {
        cout << "\nHOUR IN A WEEK FOR EMPLOYEE " << i + 1 << " : ";
        cin >> hourU;
        } while (hourU <= 0);
        
        Up.setHour(hourU); //set the hour 
        s = Up.CalcSal(); //calculate the salaries 
        cout << "TOTAL SALARIES FOR EMPLOYEE " << i + 1 << " : RM ";
        Up.print(); //display the salaries for each day in a week
        //assign the value to the arrays
        totalSalary2[i] = s; 
        totalHour2[i] = hourU;
        totalCompare2 += s;
        cout<< endl;
    }
    cout << endl << endl;
    Up.Design();
    cout << "\n    BONUS FOR THE STAFF WITH MORE THAN 53 WORKING HOURS PER WEEK \n" << endl;
    Up.Design();
    do //repeat the loop if invalid input
    {
    cout << "HOW MANY BONUS YOU WANT TO GIVE : ";
    cin >> bonusrate;
    } while (bonusrate <= 0);

    cout << "\nTHIS IS FOR CURRENT EMPLOYEES" << endl;
    for (int i = 0; i < 5;i++)
    {
        if (totalHour[i] > 53) //the current employees will get bonus salaries if their working hours are more than 53 hours
        {

            cout << "EMPLOYEE " << i + 1 << ": TOTAL SALARY WITH BONUS : RM " << totalSal[i] + bonusrate << endl;

        }
        else //display if not
            cout << "EMPLOYEE " << i + 1 << ": SORRY, WORK HARDER !!" << endl;
    }

    cout << "\nTHIS IS FOR UPDATED EMPLOYEES \n";
    for (int i = 0; i < staff;i++)//the updated employees will get bonus salaries if their working hours are more than 53 hours
    {
        if (totalHour2[i] > 53)
        {
            cout << "EMPLOYEE " << i + 1 << ": TOTAL SALARY WITH BONUS: " << totalSalary2[i] + bonusrate << endl;
        }
        else //display if not
            cout << "EMPLOYEE " << i + 1 << ":  SORRY, WORK HARDER !!" << endl;
    }
    cout << endl;
    Up.Design();

    cout << "\n    COMPARISAN BETWEEN CURRENT STAFF AND NEW STAFF\n" << endl; 
    Up.Design();
    Up.setCompare1(totalCompare1); //set the value of total salaries for all curent staff
    Up.setCompare2(totalCompare2); //set the value of total salaries for all updated staff
    if ( Up== Up) //calling the operator overloading == function
    {
        cout << "THE TOTAL OF SALARIES FOR CURRENT AND UPDATED EMPLOYEES ARE THE SAME " << endl; //display if their salaries are same
    }
    else 
        cout << "THE TOTAL OF SALARIES FOR CURRENT AND UPDATED EMPLOYEES ARE NOT THE SAME \n" << endl; //display if not

    Up.Design();

    delete[] totalSalary2; //delete the dynamic array of totalSalary2
    delete[] totalHour2; //delete the dynamic array of totalHour2

    return 0;
}