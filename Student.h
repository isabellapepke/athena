#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student();
	~Student();
	Student(int studIDInput, int facultyIDInput, string majorInput, string yearInput, string nameInput, double gpaInput);
	void printStudent();
	void printStudentAndAdvisor(int studIDInput);
	void changeAdvisor(int facultyIDInput);//will need to do this on a student in the bst
	int getID();

private:
	int studID, facultyID;
	string major, year, name;
	double gpa;
};