/*
@file test.cpp
@author Renat Norderhaug
@date 2/3/18
*/

#include "Employee.h"
#include "Employee.cpp"
#include <iostream>
#include <string>
#include <algorithm>

class EmployeeComparator
{ public:
	bool operator()(const Employee& a, const Employee& b)
	{
		return a.getEmployeeId() < b.getEmployeeId();
	}
};

int computeAverageAge(Employee *current, int count) {
	int totalAge = 0;

	for (size_t i = 0; i != 3; ++i) {
		totalAge = totalAge + current[i].getAge();
	}

	return totalAge / count;
};


void printSortedList(Employee *current, int count) {

	for (size_t i = 0; i != 3; ++i) {
		cout << current[i] << endl;
	}
};

int main()
{

	Employee listOfEmployees[3];
	string info;
	char rate;

	for (size_t i = 0; i <3; i++)
	{
		cout << "Enter employee Id: ";
		getline(cin, info);
		listOfEmployees[i].setEmployeeId(std::stoi(info));
		cout << "Employee Id " << listOfEmployees[i].getEmployeeId() << ".";
		cout << endl;

		cout << "Enter employee first name: ";
		getline(cin, info);
		listOfEmployees[i].setFirstName(info);
		cout << "Entered firstName " << listOfEmployees[i].getFirstName() << ".";
		cout << endl;

		cout << "Enter employee last name: ";
		getline(cin, info);
		listOfEmployees[i].setLastName(info);
		cout << "Entered lastName " << listOfEmployees[i].getLastName() << ".";
		cout << endl;

		cout << "Enter employee age: ";
		getline(cin, info);
		listOfEmployees[i].setAge(std::stoi(info));
		cout << "Entered age " << listOfEmployees[i].getAge() << ".";
		cout << endl;

		cout << "Enter employee department: ";
		getline(cin, info);
		listOfEmployees[i].setDepartment(info);
		cout << "Entered department " << listOfEmployees[i].getDepartment() << ".";
		cout << endl;

		cout << "Enter employee position: ";
		getline(cin, info);
		listOfEmployees[i].setPosition(info);
		cout << "Entered position " << listOfEmployees[i].getPosition() << ".";
		cout << endl;

		cout << "Employee ID: " << listOfEmployees[i].getEmployeeId() << " was added to the list of employees.";
		cout << endl;

	}

	std::sort(std::begin(listOfEmployees), std::end(listOfEmployees), EmployeeComparator());

	int totalAge = 0;

	cout << "Sorted Array: " << endl;
	printSortedList(listOfEmployees, 3);

	cout << " Average employee age is: " << computeAverageAge(listOfEmployees, 3) << " ";
}



