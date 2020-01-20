/*
Scripting and Programming - Applications C867
Manuel Fuentes
Student ID: 00099064
Software Development
*/
#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iomanip>
#include <string>

#include "degree.h"

using namespace std;

class Student
{
public:
	const static int daysArraySize = 3; //Allocated before program runs so destructor won't do anything with this array

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int daysArray[daysArraySize];
	Degree degree; //DECLARED BUT ONLY USED BY SUBCLASSES 


public:
	
	//EMPTY CONSTRUCTOR
	Student();

/*-----------GETTERS/ACCESOR FUNCTIONS-------*/
	Student(string iD, string fName, string lName, string email, int age, int* days);
	//accessors for each instance variable
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	string GetStudentID();
	int GetAge();
	int* GetNumDays();


	/*------SETTERS/MUTATOR FUNCTIONS-------*/
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setStudentID(string studentID);
	void setNumDays(int day0, int day1, int day2);

	/*------VIRTUAL FUNCTIONS-------*/
	virtual void print();
	virtual Degree getDegree() = 0;

	//Deconstructor
	~Student();

};



#endif
	 




