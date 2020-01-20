/*
Scripting and Programming - Applications C867
Manuel Fuentes
Student ID: 00099064
Software Development
*/
#include <iostream>
#include <string>
#include <iomanip>

#include "securityStudent.h"
#include "student.h"
#include "degree.h"

using namespace std;

/*EMPTY CONSTRUCTOR*/
SecurityStudent::SecurityStudent():Student() {

degree = Degree::SECURITY;
}

/*CONSTRUCTOR*/
SecurityStudent::SecurityStudent(
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

	degree = Degree::SECURITY;
}

/*USING PARENTCLASS'S VIRTUAL FUNCTION*/
Degree SecurityStudent::getDegree() {
	return degree = Degree::SECURITY;
}

void SecurityStudent::print() {
	this->Student::print(); //CALLS PARENT PRINT FUNCTION
	cout << "Security" << endl; //ADDS THE DEGREE
}

/* DESTRUCTOR */
SecurityStudent::~SecurityStudent() {

	Student::~Student();
}
