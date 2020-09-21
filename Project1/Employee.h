/**
 @file Employee.cpp
 @author Renat Norderhaug
 @date 2/3/18
 */

// Employee.h
#ifndef Employee_H
#define Employee_H
#include <string>
#include <iostream>

using namespace std;

//!  Employee class.
/*!
Class to hold employees properties including id and age.
*/
class Employee
{
private:
	int employeeId; /*!< an integer value */
	string firstName; /*!< a string value */
	string lastName; /*!<  a string value */
	int empAge; /*!< an integer value */
	string department; /*!<  a string value */
	string position; /*!<  a string value */

public:
	//! A constructor.
	/*!
	Default constructor for Employee class.
	*/
	Employee();
	//! A constructor.
	/*!
	Parametrized constructor for Employee class with 3 parameters.
	*/
	Employee(int id, string firstN, string lastN);
	//! A constructor.
	/*!
	Parametrized constructor for Employee class with 4 parameters.
	*/
    Employee(int id, string firstN, string lastN, int age);
	//! A constructor.
	/*!
	Parametrized constructor for Employee class with 6 parameters.
	*/
    Employee(int id, string firstN, string lastN, int age, string dept, string pos);
	//! A destructor.
	/*!
	Destructor for Employee class.
	*/
	virtual ~Employee();
	//! A setter for Employee Id
	/*!
	\param id an integer argument.
	*/
	void setEmployeeId(int id);
	//! A setter for first name
	/*!
	\param fn a string argument.
	*/
	void setFirstName(string fn);
	//! A setter for last name
	/*!
	\param ln a string argument..
	*/
	void setLastName(string ln);
	//! A setter for Employee Age
	/*!
	\param eAge an integer argument.
	*/
	void setAge(int eAge);
	//! A setter for department
	/*!
	\param dept a string argument
	*/
	void setDepartment(string dept);
	//! A setter for position
	/*!
	\param pos a string argument
	*/
	void setPosition(string pos);
	//! A getter for employee id.
	/*!
	\return employeeId
	*/
	int getEmployeeId() const;
	//! A getter for first name.
	/*!
	\return firstName
	*/
	string getFirstName() const;
	//! A getter for last name.
	/*!
	\return lastName
	*/
	string getLastName() const;
	//! A getter for age.
	/*!
	\return eAge
	*/
	int getAge() const;
	//! A getter for department.
	/*!
	\return department
	*/
	string getDepartment() const;
	//! A getter position.
	/*!
	\return position
	*/
	string getPosition() const;
	//! A friend function that outputs the employee properties
	/*!
	\return ostream
	*/
	friend std::ostream &operator << (std::ostream &os, Employee const &m) {
		return std::cout << m.employeeId << " " << m.firstName << " " << m.lastName << " " << m.empAge << " " << m.department << " " << m.position << " " <<  "\n";
	}
};

#endif

