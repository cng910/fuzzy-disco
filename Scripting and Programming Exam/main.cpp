#include <iostream>

#include <string>
#include "roster.h"
using namespace std;

int main()
{
	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Courtney,Griffin,cgri421@school.edu,27,60,15,20,SOFTWARE"
	};

	const int numStudents = 5;
	Roster roster;

	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "C867: Scripting and Programming Applications - C++." << endl << "cgri421" << endl << "Courtney Grffin" << std::endl;
	roster.printAll();
	cout << std::endl;

	cout << "Displaying students with invalid emails" << std::endl;
	roster.printInvalidEmails();
	cout << std::endl;

	void printAverageDays(); {
	
		for (int i = 0; i < Student::dayArraySize; ++i) {
		roster.printAverageDays("A1");
		break;
	}
}
	for (int i = 0; i < 1; i++)
	{
		cout << "Displaying by degree type: " << degreeProgramStrings[2] << std::endl;
		roster.printByDegreeProgram((DegreeProgram)2);
	}

cout << "Removing student with ID A3" << std::endl;
roster.remove("A3");
cout << std::endl;

cout << "Removing student with ID A3" << std::endl;
roster.remove("A3");
cout << std::endl;

roster.printAll();

system("pause");

 /* code */
	return 0;
}