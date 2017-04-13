#include <iostream>
#include <string>
#include <fstream>

#include "Student.h"
using namespace std;

Student::Student()
{
	studID = 0;
	facultyID = 0;
	major = "default";
	year = "default";
	gpa = 0.1;
	name = "default";
}

Student::~Student()
{

}

Student::Student(int studIDInput, int facultyIDInput, string majorInput, string yearInput, string nameInput, double gpaInput)//overloaded
{

	//keep input in here 

	studID = studIDInput;
	facultyID = facultyIDInput;
	major = majorInput;
	year = yearInput;
	name = nameInput;
	gpa = gpaInput;

}


void Student::printStudent()//will print out all of student info
{
	cout<<"Student:\n\tName: "<<name<<"\n\tStudent ID: "<<studID<<"\n\tFaculty ID: "<<facultyID<<"\n\tMajor: "<<major<<"\n\tYear: "<<year<<"\n\tGPA: "<<gpa<<endl;
}

void Student::changeAdvisor(int facultyIDInput)
{
	facultyID = facultyIDInput;
}


int Student::getID()
{
	return studID;
}

 bool operator< ( Student &s1,  Student &s2)
 {
 	return s1.getID()<s2.getID();
 }
 /*bool operator> ( Student &s1, Student &s2)
 {
 	return s1.getID()>s2.getID();

 }*/

