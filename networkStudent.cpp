/*
Scripting and Programming - Applications C867
Manuel Fuentes
Student ID: 00099064
Software Development
*/
#include <iostream>
#include <string>
#include <iomanip>

#include "networkStudent.h"
#include "student.h"
#include "degree.h"

using namespace std;

/*EMPTY CONSTRUCTOR*/
NetworkStudent::NetworkStudent():Student() {
	degree = Degree::NETWORKING;
}
/* CONSTRUCTOR */
NetworkStudent::NetworkStudent(
	string sID, 
	string sName, 
	string sLast, 
	string sEmail, 
	int sAge, 
	int* sDays, 
	Degree sDeg) //ADDING ARGUMENT (DEGREE) DECLARED IN PARENT CLASS
	: Student::Student( //CALLING PARENT CONSTRUCTOR 
		sID, 
		sName, 
		sLast, 
		sEmail, 
		sAge, 
		sDays) {

	degree = Degree::NETWORKING;//GIVING A VALUE TO DEGREE
}

/*USING PARENTCLASS'S VIRTUAL FUNCTION*/
Degree NetworkStudent::getDegree() {
	return degree = Degree::NETWORKING;
}


void NetworkStudent::print() {
	this->Student::print();//CALLS PARENT PRINT FUNCTION
	cout << "Networking" << endl;//ADDS THE DEGREE
}

/* DESTRUCTOR */
NetworkStudent::~NetworkStudent() {

	Student::~Student();
}
