#include "roster.h"
#include "student.h"
#include "degree.h"

/* Create a Roster class (roster.cpp) by doing the following:

1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”

2.  Create a student object for each student in the data table and populate classRosterArray.

a.Parse each set of data identified in the “studentData Table.”

b.Add each student object to classRosterArray.*/ 

Roster::Roster(int maxCapacity)
{
	_maxCapacity = maxCapacity;
	_classRosterArray = new Student*[maxCapacity];
	for (size_t i = 0; i < _maxCapacity; i++)
		_classRosterArray[i] = NULL;
}

// uses add and if roster is full then prompt pops up.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	for (size_t i = 0; i < _maxCapacity; i++)
	{
		if (_classRosterArray[i] == NULL) {
			int numDays[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
			_classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, numDays, degreeprogram);
			return;
		}
	}
	cout << "Roster is full, cannot add new student.\n";
}

//Uses remove and if student is not found then prompt pops up.
void Roster::remove(string studentID)
{
	for (size_t i = 0; i < _maxCapacity; i++)
	{
		if (_classRosterArray[i] != NULL && _classRosterArray[i]->getStudentID() == studentID) {
			delete _classRosterArray[i];
			_classRosterArray[i] = NULL;
			return;
		}
	}
	cout << "Student with ID: " << studentID << " is not found.\n";
}

//Uses printALL that prints class roster.
void Roster::printAll()
{
	for (size_t i = 0; i < _maxCapacity; i++)
	{
		if (_classRosterArray[i] != NULL) {
			 _classRosterArray[i]->print();
		}
	}
}

// Prints average days in course using studentID, if student is not found then prompt pops up.
void Roster::printAverageDaysInCourse(string studentID)
{
	for (size_t i = 0; i < _maxCapacity; i++)
	{
		if (_classRosterArray[i] != NULL && _classRosterArray[i]->getStudentID() == studentID) {
			double avgDays =( _classRosterArray[i]->getNumDays()[0] + _classRosterArray[i]->getNumDays()[1] + _classRosterArray[i]->getNumDays()[2]) / 3;
			cout << "For student with Id " << studentID << " average days in course is: " << avgDays << "\n";
			return;
		}
	}
	cout << "Student with ID: " << studentID << " is not found.\n";
}

//Uses printInvalidEmails and isEmailValid to check email adderesses and displays invalid adderesses.
void Roster::printInvalidEmails()
{
	for (size_t i = 0; i < _maxCapacity; i++)
	{
		if (_classRosterArray[i] != NULL && !_classRosterArray[i]->isEmailValid()) {
			cout << _classRosterArray[i]->getEmail()<< "\n";
		}
	}
}

// Prints student degrees by specified program.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (size_t i = 0; i < _maxCapacity; i++)
	{
		if (_classRosterArray[i] != NULL && _classRosterArray[i]->getDegree()== degreeProgram) {
			_classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() //5.  Implement the destructor to release the memory that was allocated dynamically in Roster.
{
	for (size_t i = 0; i < _maxCapacity; i++)
	{
		if (_classRosterArray[i] != NULL) {
			delete _classRosterArray[i];
		}
	}
	delete _classRosterArray;
}



