#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
//using std::endl;

class Student
{
public:
	const static int dayArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	string age;
	double days[dayArraySize];
	DegreeProgram degreeProgram;
public:
	Student(); //constructor
	Student(string studentID, string firstName, string lastName, string email, string age, double days[], DegreeProgram degreeProgram);
	~Student(); //destructor

	//accessors
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	string getAge();
	double* getDays();
	DegreeProgram getDegreeProgram();

	//mutators
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(string age);
	void setDays(double days[]);
	void setDegreeProgram(DegreeProgram dp);

	static void printHeader();
	void print();
};