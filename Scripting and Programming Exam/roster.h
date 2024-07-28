#pragma once
#include "student.h"
class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* studentRosterArray[numStudents];

public:
	void parse(string row);
	void add(string sID,
		string sFirstName,
		string sLastName,
		string sEmail,
		string sAge,
		double sDay1,
		double sDay2,
		double sDay3,
		DegreeProgram type);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageDays(string studentID);
	void remove(string studentID);
	~Roster();

};