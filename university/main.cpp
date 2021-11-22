#include <iostream>
#include "student.h"
#include "degree.h"
#include "roster.h"

// local function that breaks sudentData string into individual data points, that can then be printed seperately.

string GetNextField(string* inStr);

string GetNextField(string* inStr)
{ 
	int pos = inStr->find(',');
	string outStr = inStr->substr(0, pos);
	*inStr = inStr->substr(pos + 1, inStr->length());
	return outStr;
}

int main()
{
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Eden,Piatnichko,epiatni@wgu.edu,25,30,30,30,SOFTWARE" 
	};
	const int studentsNum = 5;

	//1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << "Scripting and Programming Applications — C867, Programmind Language used: C++. Student ID: #000984598. Name: Eden Piatnichko\n";
	

	/*Create an instance of the Roster class called classRoster.
	3.  Add each student to classRoster.*/
	
	Roster* classRoster = new Roster (studentsNum);
	for (size_t i = 0; i < studentsNum; i++)
	{
		string studentDataString = studentData[i];
		string studentID = GetNextField(&studentDataString);
		string firstName = GetNextField(&studentDataString);
		string lastName = GetNextField(&studentDataString);
		string email = GetNextField(&studentDataString);
		int age = stoi(GetNextField(&studentDataString));     //stoi converts a string to an integer
		int numDays1 = stoi(GetNextField(&studentDataString));
		int numDays2 = stoi(GetNextField(&studentDataString));
		int numDays3 = stoi(GetNextField(&studentDataString));
		DegreeProgram degree = SECURITY;
		if (studentDataString == "NETWORK")
			degree = NETWORK;
		else if (studentDataString == "SOFTWARE")
			degree = SOFTWARE;

		classRoster->add(studentID, firstName, lastName, email, age, numDays1, numDays2, numDays3, degree);
	}
	/*4.  Convert the following pseudo code to complete the rest of the  main() function:
	classRoster.printAll();
	classRoster.printInvalidEmails();*/
	classRoster->printAll();
	cout << "\n Invalid Emails:\n";
	classRoster->printInvalidEmails();
	cout << "\n";
	
	//loop through classRosterArray and for each element:
	for (size_t i = 0; i < studentsNum; i++)
	{
		string studentDataString = studentData[i];
		string studentID = GetNextField(&studentDataString);
		classRoster->printAverageDaysInCourse(studentID);
	}

	//4.  continued
	cout << "\n";
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << "\n";
	classRoster->remove("A3");
	cout << "\n";
	classRoster->printAll();
	cout << "\n";
	classRoster->remove("A3");

	delete classRoster;
}


