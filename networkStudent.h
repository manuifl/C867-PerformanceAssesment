#pragma once
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"
#include "degree.h"

class NetworkStudent : public Student {
public:
	
	NetworkStudent();

	NetworkStudent(
		string sID,
		string sName,
		string sLast,
		string sEmail,
		int sAge,
		int* sDays,
		Degree sDeg
	);


	Degree getDegree() override;

	void print() override;

	~NetworkStudent();

private:
	
};



#endif