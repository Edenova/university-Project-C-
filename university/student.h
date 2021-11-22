#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;
/*D.  For the Student class, do the following:

1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:

•  student ID

•  first name

•   last name

•  email address

•  age

•  array of number of days to complete each course

•  degree program*/

class Student {

//Variables that are accessed internally.
private:
	string _studentID;
	string _firstName;
	string _lastName;
	string _email;
	int _age;
	int *_numDays;
	DegreeProgram _degree;
	

public:
	// contructor for student class using all variables provided.
	Student(string studentID, string firstName, string lastName, string email, int age, int numDays[3], DegreeProgram degree);

	//Accessors for each instance variable.
	string getStudentID() { return _studentID;}
	string getFirstName() { return _firstName; }
	string getLastName() { return _lastName; }
	string getEmail() { return _email; }
	int getAge() { return _age; }
	int* getNumDays() { return _numDays; }
	DegreeProgram getDegree() { return _degree; }

	//Mutators for each instance variable.
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumDays(int numDays[3]);
	void setDegree(DegreeProgram degree);

	void print();
	// isEmailValid checks for valid format that includes the ('@') sign, and period ('.') and does not include a space (' ').
	bool isEmailValid() { return _email.find('@') != string::npos && _email.find('.') != string::npos && _email.find(' ') == string::npos; } 
	
	~Student(); //deconstructor

};
