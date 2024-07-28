#include <iostream>

#include <string>

#include "student.h"
using namespace std;

Student::Student()//constructor
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = "";
	for (int i = 0; i < dayArraySize; i++) this->days[i] = 0;
	this-> degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, string age, double days[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < dayArraySize; i++) this->days[i] = days[i];
	this-> degreeProgram = degreeProgram;
}

Student::~Student() {}//destructor

//accessors
string Student::getID() { return this->studentID;}
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getEmail() {return this->email;}
string Student::getAge() {return this->age;}
double* Student::getDays() {return this->days;}
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}

//mutators
void Student::setID(string ID) {this->studentID = ID;}
void Student::setFirstName(string firstName) {this->firstName = firstName;}
void Student::setLastName(string lastName) {this->lastName = lastName;}
void Student::setEmail(string email) {this->email = email;}
void Student::setAge(string age) {this->age = age;}
void Student::setDays(double days[])
{
	for (int i = 0; i < dayArraySize; i++) this->days[i] - days[i];
}
void Student::setDegreeProgram(DegreeProgram dp) {this->degreeProgram = dp;}

void Student::printHeader()
{
	cout << "ID|First Name|Email|Age|Days in Course| Degree Program\n";
}

void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}