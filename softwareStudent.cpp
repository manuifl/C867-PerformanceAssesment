/*
Scripting and Programming - Applications C867
Manuel Fuentes
Student ID: 00099064
Software Development
*/
#include <iostream>
#include <string>
#include <iomanip>

#include "softwareStudent.h"
#include "student.h"
#include "degree.h"

using namespace std;

/*EMPTY CONSTRUCTOR*/
SoftwareStudent::SoftwareStudent():Student() {
	degree = Degree::SOFTWARE;
}

/*CONSTRUCTOR*/
SoftwareStudent::SoftwareStudent(
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

	degree = Degree::SOFTWARE;
}

/*USING PARENTCLASS'S VIRTUAL FUNCTION*/
Degree SoftwareStudent::getDegree() {
	return degree = Degree::SOFTWARE;
}

void SoftwareStudent::print() {
	this->Student::print(); //CALLS PARENT PRINT FUNCTION
	cout << "Software" << endl; //ADDS THE DEGREE
}

/* DESTRUCTOR */
SoftwareStudent::~SoftwareStudent() {

	Student::~Student();
}

