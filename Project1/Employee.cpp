/*
@file Employee.cpp
@author Renat Norderhaug
@date 2/3/18
*/

#include "Employee.h"
#include <sstream>
#include <iostream>
#include <string>

/**
<Default constructor>  <The default constructor which sets the ID to 0, first and lastname blank, age to 0, and department/position are blank>
@param  inputs any value
@pre  any input
@post  makes a default employee object
@return nothing
*/

	Employee::Employee()
	{
		employeeId = 0;
		firstName = " ";
		lastName = " ";
		empAge = 0;
		department = " ";
		position = " ";
	}
/**
<parameterized constructor>  <It is the parameterized constructor for the Employee class which sets the member variables equal to the values you pass in the parameter >
@param  an integer value, and two strings
@pre  takes in an integer and two strings
@post  sets the integer and two strings to whichever values you typed in
@return returns nothing
*/
Employee::Employee(int id, string firstN, string lastN)
	{
		employeeId = id;
		firstName = firstN;
		lastName = lastN;
		empAge = 0;
		department = " ";
		position = " ";
	}
/**
 <parameterized constructor two>  <It is the parameterized constructor for the Employee class which sets the member variables equal to the values you pass in the parameter and also adds the age file >
 @param  an integer value, and two strings as well as an integer for age
 @pre  takes in two integers and two strings
 @post  sets the integers and two strings to whichever values you typed in
 @return returns nothing
 */
	Employee::Employee(int id, string firstN, string lastN, int age)
	{
		employeeId = id;
		firstName = firstN;
		lastName = lastN;
		empAge = age;
		department = " ";
		position = " ";
	}
/**
 <parameterized constructor>  <It is the parameterized constructor for the Employee class which sets the member variables equal to the values you pass in the parameter >
 @param  two integer values, and four strings
 @pre  takes in two integers and four strings
 @post  sets the integer and four strings to whichever values you typed in
 @return returns nothing
 */
	Employee::Employee(int id, string firstN, string lastN, int age, string dept, string pos)
	{
		employeeId = id;
		firstName = firstN;
		lastName = lastN;
		empAge = age;
		department = dept;
		position = pos;
	}

/**
 <default destructor>  <It is the destructor which is called when an employee object needs to be deleted, such as when an employee is fired >
 @param  any
 @pre  takes in whichever input
 @post  deletes the object made
 @return returns nothing
 */
	Employee::~Employee()
	{
	}
/**
 <setter function>  <It sets the employee ID to whichever integer value that you pass into the function>
 @param  an integer value
 @pre  takes in an integer
 @post  sets the integer to what you typed in
 @return returns nothing
 */

	void Employee::setEmployeeId(int id)
	{
		employeeId = id;
	}
/**
 <setter function>  <It sets the employee's first name to whichever string value that you pass into the function>
 @param  an string value
 @pre  takes in an string
 @post  sets the string variable to what you typed in
 @return returns nothing
 */

	void Employee::setFirstName(string n)
	{
		firstName = n;
	}
/**
 <setter function>  <It sets the employee's last name to whichever string value that you pass into the function>
 @param  an string value
 @pre  takes in an string
 @post  sets the string variable to what you typed in
 @return returns nothing
 */
	void Employee::setLastName(string n)
	{
		lastName = n;
	}
/**
 <setter function>
 <It sets the employee's age to whichever integer value that you pass into the function>
 @param  an int value
 @pre  takes in an integer value
 @post  sets the integer variable to what you typed in
 @return returns nothing
 */

	void Employee::setAge(int eAge)
	{
		empAge = eAge;
	}

/**
 <setter function>  <It sets the employee's department to whichever string value that you pass into the function>
 @param  an string value
 @pre  takes in an string
 @post  sets the string variable to what you typed in
 @return returns nothing
 */

	void Employee::setDepartment(string dept)
	{
		department = dept;
	}
/**
<setter function>  <It sets the employee's position to whichever string value that you pass into the function>
@param  an string value
@pre  takes in an string
@post  sets the string variable to what you typed in
@return returns nothing
*/
	void Employee::setPosition(string pos)
	{
		position = pos;
	}
/**
 <getter function>  <It gets the employee's id number which is private so has to be accessed through a getter function>
 @param none
 @pre  takes in nothing
 @post  gets the id for the Employee
 @return returns the employeeID
 */

	int Employee::getEmployeeId() const
	{
		return employeeId;
	}
/**
 <getter function>  <It gets the employee's first name which is private so has to be accessed through a getter function>
 @param none
 @pre  takes in string variable for the first name
 @post  gets the first name for the Employee
 @return returns the firstName variable
 */

	string Employee::getFirstName() const
	{
		return firstName;
	}
/**
 <getter function>  <It gets the employee's Last name which is private so has to be accessed through a getter function>
 @param none
 @pre  takes in a string variable of last name
 @post  gets the first name for the Employee
 @return returns the firstName variable
 */
	string Employee::getLastName() const
	{
		return lastName;
	}
/**
 <getter function>  <It gets the employee's age which is an integer value that can only be accessed with a getter function>
 @param none
 @pre  takes in nothing
 @post  gets the first name for the Employee
 @return returns the firstName variable
 */
	int Employee::getAge() const
	{
		return empAge;
	}
/**
 <getter function>  <It gets the employee's department which is private so has to be accessed through a getter function>
 @param none
 @pre  takes in a string department
 @post  gets the string for the Employee's department
 @return returns the department
 */
	string Employee::getDepartment() const
	{
		return department;
	}
/**
 <getter function>  <It gets the employee's position at his department which is private so has to be accessed through a getter function>
 @param none
 @pre  takes in a string position
 @post  gets the string for the Employee's position
 @return returns the position
 */

	string Employee::getPosition() const
	{
		return position;
	}




