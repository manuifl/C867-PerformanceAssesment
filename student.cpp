/*
Scripting and Programming - Applications C867
Manuel Fuentes
Student ID: 00099064
Software Development
*/
#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <iomanip>

#include "student.h"
#include "degree.h"

using namespace std;

/* EMPTY CONSTRUCTOR */
Student::Student()
{

studentID = " ";
	firstName = "";
	lastName = "";
	emailAddress = "";
	studentAge = 0;
	daysArray[0] = 0;
	daysArray[1] = 0;
	daysArray[2] = 0;

}

/*CONSTRUCTOR */
Student::Student(string iD, string fName, string lName, string email, int age, int* days) //DEGREE NOT INCLUDED
{
	studentID = iD;
	firstName = fName;
	lastName = lName;
	emailAddress = email;
	studentAge = age;
	daysArray[0] = days[0];
	daysArray[1] = days[1];
	daysArray[2] = days[2];
}

/*-----------GETTERS/ACCESOR FUNCTIONS-------*/
string Student::GetStudentID() {
	return studentID;
}
string Student::GetFirstName(){
	return firstName;
}
string Student::GetLastName(){
	return lastName;
}
string Student::GetEmailAddress(){
	return emailAddress;
}
int Student::GetAge(){
	return studentAge;
}
int* Student::GetNumDays() {
	return daysArray;
}

/*------SETTERS/MUTATOR FUNCTIONS-------*/
void Student::setStudentID(string iD) {
	
	Student::studentID = iD;
}
void Student::setFirstName(string fName){
	firstName = fName;
}
void Student::setLastName(string lName){
	lastName = lName;
}
void Student::setEmailAddress(string email){
	emailAddress = email;
}
void Student::setAge(int age){
	studentAge = age;
}

void Student::setNumDays(int day0, int day1, int day2){

	Student::daysArray[0] = day0;
	Student::daysArray[1] = day1;
	Student::daysArray[2] = day2;	
}

//Student::Student() {}


//GetDegree() WILL BE CONSTRUCTED AND CALLED IN THE SUBCLASSES
void Student::print() {

	cout << "  First Name: " << GetFirstName() << "\t"
		<< "Last Name: " << GetLastName() << "\t"
		<< "Age: " << GetAge() << "\t"
		<< "    Days per course: (" << GetNumDays()[0] 
		<< ", " << GetNumDays()[1] << ", " 
		<< GetNumDays()[2] << ")" 
		<< "    Degree: ";
}

/*  DECONSTRUCTOR  */
Student::~Student()
{
}
