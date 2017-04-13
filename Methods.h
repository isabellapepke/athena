#include <iostream>
#include <string>

#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

class Methods
{
public:
	//void StudentInOrder(Student n); 
	//void FacultyInOrder(Faculty n)
	void printMenu();
	void createStudents();
	void createFaculty();
	void printAdvisees(int facultyIDInput);

};