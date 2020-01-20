
#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <iomanip>

#include "roster.h"
#include "student.h"
#include "degree.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"

using namespace std;



Roster::Roster() {}

 /* --------------------------ADD FUNCTION  ---------------------------------------*/
void Roster::add(string studID, string fiName, string laName, string emAddr, int a, int day0, int day1, int day2, Degree degree) {
	int nmDaysIn[] = { day0, day1, day2 };
	//incrementIndex++ PREVENTS OVERWRITING NEW
	if (degree == Degree::NETWORKING) {
		classRosterArray[incrementIndex++] = new NetworkStudent(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
	if (degree == Degree::SECURITY) {
		classRosterArray[incrementIndex++] = new SecurityStudent(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
	if (degree == Degree::SOFTWARE) {
		classRosterArray[incrementIndex++] = new SoftwareStudent(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
}
/* -----------------------------FUNCTION END---------------------------------------- */

/* ------------------------------PRINTING ALL STUDENTS-------------------- */
void Roster::printAll() {
	cout << "  STUDENT ROSTER:" << endl;
	cout << endl;
	for (int i = 0; i < 5; i++) {
		(*classRosterArray[i]).print();
	}
	//cout << setfill('-') << setw(100) << "" << endl;
	cout << endl;

}
/* -----------------------------FUNCTION END---------------------------------------- */

/* -----------------------DISPLAYING INVALID EMAILS--------------------------------------- */
void Roster::printInvalidEmails() {
	cout << "  INVALID STUDENT EMAILS:" << endl;
	cout << endl;

	bool hasSpace = false;
	bool hasAt = false;
	bool hasDot = false;
	string studentEmail;

	for (int i = 0; i < 5; i++) {

		studentEmail = (*classRosterArray[i]).GetEmailAddress();

		//checking for spaces on email string
		if (studentEmail.find(' ') != string::npos) {
			hasSpace = true;
		}
		else {
			hasSpace = false;
		}
		//checking for at symbol on email string
		if (studentEmail.find('@') != string::npos) {
			hasAt = true;
		}
		else {
			hasAt = false;
		}
		//checking for dot on email string
		if (studentEmail.find('.') != string::npos) {
			hasDot = true;
		}
		else {
			hasDot = false;
		}
		//invalid emails have spaces and are missing a dot or at symbol
		if (hasSpace == true || hasAt == false || hasDot == false) {
			cout << "  -" << (*classRosterArray[i]).GetEmailAddress() << endl;
			
		}
	}
	cout << endl;
}
/* -----------------------------FUNCTION END---------------------------------------- */

/* -----------------------------PRINTING AVERAGE OF DAYS---------------------------------------- */
//gets days by index then sum and division
void Roster::printAverageDaysInCourse(string studentID) {
	cout << "  COURSE COMPLETION RATE AVERAGE: " << endl;
	cout << endl;
	for (int i = 0; i < 5; i++) {
		if ((*classRosterArray[i]).GetStudentID() == studentID) {
			int average = 0;
			average = ((*classRosterArray[i]).GetNumDays()[0] + (*classRosterArray[i]).GetNumDays()[1] + (*classRosterArray[i]).GetNumDays()[2] ) / 3;
			//cout << "  The average days it took the student with studentID: " << studentID << " to finish 3 courses: " << average << '\n';
			cout << "  StudentID: " << studentID << "\t" << " Average: " << average << endl;
		}
	}
	cout << endl;
}
/* -----------------------------FUNCTION END---------------------------------------- */

/* ------------------PRINTING STUDENTS OF THE DEGREE SPECIFIED IN THE PARAMETER-------------- */
void Roster::printByDegreeProgram(string degree) {
	Degree studentsByDegree;
	
	if (degree == "NETWORKING") {
		studentsByDegree = Degree::NETWORKING;
		cout << "  STUDENTS IN THE NETWORKING PROGRAM: " << endl;
	}
	if (degree == "SOFTWARE") {
		studentsByDegree = Degree::SOFTWARE;
		cout << "  STUDENTS IN THE SOFTWARE PROGRAM: " << endl;
	}

	if (degree == "SECURITY") {
		studentsByDegree = Degree::SECURITY;
		cout << "  STUDENTS IN THE SECURITY PROGRAM:  " << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		if (studentsByDegree == (*classRosterArray[i]).getDegree()) {
			(*classRosterArray[i]).print();
		}
	}
	cout << endl;
}
/* -----------------------------FUNCTION END---------------------------------------- */



/* --------------------REMOVING STUDENT USING STUDENT ID----------------------------------------- */
void Roster::remove(string studentID) {
	bool studentRemoved = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			if (studentID == classRosterArray[i]->GetStudentID()) {
				classRosterArray[i] = nullptr;
				studentRemoved = true;
			}
		}
	}
	if (!studentRemoved) {
		cout << " ***The student with the ID: " << studentID << " was not found." << '\n';
	}
}
/* -----------------------------FUNCTION END---------------------------------------- */

/* -----------------------------MAIN---------------------------------------- */
int main()
{

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Manuel,Fuentes,mfuenq9@wgu.edu,30,32,35,37,SOFTWARE"
	};

	//Creating Roster Instance
	Roster classRoster;

	// Creating Degree Instance
	Degree myDegree;

	
	/* --------------------------CODE FOR SEPARATING STUDENT DATA ITEMS ----------------------------- */
	for (int i = 0; i < 5; i++) {
		
		//read student id
		int commaFind = studentData[i].find(",");
		string sID = studentData[i].substr(0, commaFind);
		
		//read student first name
		int secSubs = commaFind + 1; //starting from first character after the last comma
		commaFind = studentData[i].find(",", secSubs);
		string sFN = studentData[i].substr(secSubs, commaFind - secSubs);
		
		//read student last name
		int thirdSubs = commaFind + 1;
		commaFind = studentData[i].find(",", thirdSubs);
		string sLN = studentData[i].substr(thirdSubs, commaFind - thirdSubs);
	
		//read student email
		int fourthSubs = commaFind + 1;
		commaFind = studentData[i].find(",", fourthSubs);
		string sEM = studentData[i].substr(fourthSubs, commaFind - fourthSubs);
		
		//read student age
		int fifthSubs = commaFind + 1;
		commaFind = studentData[i].find(",", fifthSubs);
		int sAG = stoi(studentData[i].substr(fifthSubs, commaFind - fifthSubs));
		
		//read student day 1 of array
		int sixthSubs = commaFind + 1;
		commaFind = studentData[i].find(",", sixthSubs);
		int sDay1 = stoi(studentData[i].substr(sixthSubs, commaFind - sixthSubs));
		
		//read student day 2 of array
		int sevenSubs = commaFind + 1;
		commaFind = studentData[i].find(",", sevenSubs);
		int sDay2 = stoi(studentData[i].substr(sevenSubs, commaFind - sevenSubs));
		
		//read student day 3 of array
		int eightSubs = commaFind + 1;
		commaFind = studentData[i].find(",", eightSubs);
		int sDay3 = stoi(studentData[i].substr(eightSubs, commaFind - eightSubs));
		
		//read student degree
		int ninthSubs = commaFind + 1;
		commaFind = studentData[i].find(",", ninthSubs);
		string mydegree = studentData[i].substr(ninthSubs, commaFind - ninthSubs);
		
		//assigning the appropiate degree to each string
		if (mydegree == "NETWORK") {
			myDegree = Degree::NETWORKING;
		}

		if (mydegree == "SOFTWARE") {
			myDegree = Degree::SOFTWARE;
		}

		if (mydegree == "SECURITY") {
			myDegree = Degree::SECURITY;
		}

		classRoster.add(sID, sFN, sLN, sEM, sAG, sDay1, sDay2, sDay3, myDegree);
	}
	/* -------------------END OF SEPARATING STUDENT DATA ITEMS ----------------------------- */

	/*------------------ PRINTING PERSONAL INFO --------------------------------------------*/
	cout << endl;
	cout << "  Scripting and Programming - Applications C867" << endl;
	cout << "  Manuel Fuentes" << endl;
	cout << "  Student ID #000990664" << endl;
	cout << endl;

	// printing all results
	classRoster.printAll();

	classRoster.printInvalidEmails();

	classRoster.printAverageDaysInCourse("A1");

	classRoster.printByDegreeProgram("SOFTWARE");

	classRoster.remove("A3");

	classRoster.remove("A3"); //CHECK IF STUDENT WAS REMOVED

}


//Deconstructor
Roster::~Roster() {}
