#include <iostream>

#include <string>
#include <vector>
#include <sstream>

#include "roster.h"

using namespace std;

void Roster::parse(string studentdata)
{

	int rhs = studentdata.find(",");
	string studentID = studentdata.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentdata.find(",",lhs);
	string firstName = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string lastName = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string email = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string age = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	double day1 = stod(studentdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	double day2 = stod(studentdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	double day3 = stod(studentdata.substr(lhs, rhs - lhs));
	
	lhs = rhs + 1;
	rhs = studentdata.find("\0", lhs);
	string type = studentdata.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = SECURITY; //default value
	if (studentdata.back() == 'K') degreeProgram = NETWORK;
	else if (studentdata.back() == 'E') degreeProgram = SOFTWARE;
	

	add(studentID, firstName, lastName, email, age, day1, day2, day3, degreeProgram);
}

	void Roster::add(string studentID, string firstName, string lastName, string email, string age, double day1, double day2, double day3, DegreeProgram dp)
		 {
		double parr[3] = { day1, day2, day3 };
		studentRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, parr, dp);
	}

void Roster::printAll()
{
	cout << endl;
	int i = 0;
	for (int i = 0; i < 5; ++i) {
		if (studentRosterArray[i]->getID() != "invalid") {
			cout << "   ";
			studentRosterArray[i]->print();
		}
	}
	
	return;

}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::studentRosterArray[i]->getDegreeProgram() == dp) studentRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for(int i = 0; i <= Roster::lastIndex; i++)
	{
		string email = (studentRosterArray[i]->getEmail());
		if (email.find('@') == string::npos || email.find('.') == string::npos)
		{
			any = true;
			cout <<"Invalid email: " << studentRosterArray[i]->getEmail() << std::endl;
		}
		else if (email.find(' ') != -1) cout << "Invalid email: " << "\t" << email << endl;
	}
	if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDays(string studentID)
 {
	for(int i = 0; i <= Roster::lastIndex; i++) {
		cout << studentRosterArray[i]->getID();
		cout << ": ";
		cout << "Average Days in Course - ";
		cout << (studentRosterArray[i]->getDays()[0] + 
			studentRosterArray[i]->getDays()[1] + 
			studentRosterArray[i]->getDays()[2])/3.0 << std::endl;

	}
	cout << std::endl;
}


void Roster::remove(string studentID) {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		if (studentRosterArray[i]->getID() == studentID) {
			cout << "Deleting: " << studentRosterArray[i]->getID() << endl;
			studentRosterArray[i]->setID("invalid");
			return;
		}
	}
	cout << "Error: Student not found..." << endl;
	return;
}

Roster:: ~Roster()
{
	cout << "DESTRUCTOR CALLED!!!" << std::endl << std::endl;
	for(int i = 0; i < numStudents; i++)
	{
		cout << "Destroying student #" << i + 1 << std::endl;
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}