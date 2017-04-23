#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Faculty
{
public:
	Faculty();
	~Faculty();
	Faculty(string nameInput, string jobInput, string departmentInput, int facultyIDInput, list<int> listInput);
	Faculty(int facultyIDInput);
	void printFaculty();
	void printFacultyAdvisees();
	void addAdvisee();
	void printAdviseesList();
	int getID();
	list<int> getAdviseesList();
	friend bool operator<(Faculty &s1,  Faculty &s2);
	friend ostream& operator<< (ostream& out, Faculty &s);


private:
	string name, job, department;
	int facultyID;
	list<int> adviseesList;
};
#endif