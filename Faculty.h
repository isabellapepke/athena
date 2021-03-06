#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

class Faculty
{
public:
	Faculty();
	~Faculty();
	Faculty(string nameInput, string jobInput, string departmentInput, int facultyIDInput, vector<int> listInput);
	Faculty(int facultyIDInput);
	void printFaculty();
	void printFacultyAdvisees();
	void addAdvisee(int studIDInput);
	void printAdviseesList();
	//string printAdviseesListString();
	void removeAdvisee(int studIDInput);
	int getID();
	string getName();
	string getJob();
	string getDpmt();
	vector<int> getAdviseesList();
	friend bool operator<(Faculty &s1,  Faculty &s2);
	friend ostream& operator<< (ostream& out, Faculty &s);
	friend bool operator==(Faculty &s1,  Faculty &s2);


private:
	string name, job, department;
	int facultyID;
	vector<int> adviseesList;
};
#endif