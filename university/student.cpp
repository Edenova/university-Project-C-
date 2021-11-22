#include "student.h"
#include <iostream>
#include "degree.h"


Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDays[3], DegreeProgram degree) {
	
	_studentID = studentID;
	_firstName = firstName;
	_lastName = lastName;
	_email = email;
	_age = age;
	_numDays = new int[3];
	_numDays[0] = numDays[0];
	_numDays[1] = numDays[1];
	_numDays[2] = numDays[2];
	_degree = degree;

}
//Setters 
void Student::setStudentID(string studentID)
{
	_studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	_firstName = firstName;
}

void Student::setLastName(string lastName)
{
	_lastName = lastName;
}

void Student::setEmail(string email)
{
	_email = email;
}

void Student::setAge(int age)
{
	_age = age;
}

void Student::setNumDays(int numDays[3])
{
	_numDays = numDays;
}

void Student::setDegree(DegreeProgram degree)
{
	_degree = degree;
}

void Student::print() //prints specific student data
{
	string degreeName;
	switch (_degree)                      //switch case is used to pring specific string degree names using the enumurated degreees.
	{
	case SECURITY:
		degreeName = "Security";
		break;
	case NETWORK:
		degreeName = "Network";
		break;
	case SOFTWARE:
		degreeName = "Software";
		break;
	default:
		break;
	}
	cout << _studentID << "\t";
	cout << "First Name: " << _firstName << "\t";
	cout << "Last Name: " << _lastName << "\t";
	cout << "Email: " << _email << "\t";
	cout << "Age: " << _age << "\t";
	cout << "daysInCourse: {" << _numDays[0] << ", " << _numDays[1] << ", " << _numDays[2] << " }\t";
	cout << "Degree Program: " << degreeName << ".\n";
}
//Destructor of student contructor and _numDays array
Student::~Student()
{
	delete _numDays;
}
