#pragma once
#include "student.h"
#include <list>
#include <string>

//Part E3: define the following functions: void add, void remove, void printAll(), void printAverageDaysInCourse, void pringInvalidEmails(), void printByDegreeProgram. 


class Roster {
private: 
	Student** _classRosterArray = NULL;
	int _maxCapacity = 0;  //max size of the roster

	



public:
	Roster(int maxCapacity);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster(); //deconstructor of Roster
};