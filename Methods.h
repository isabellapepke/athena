#include <iostream>
#include <string>

#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

class Methods
{
public:
	//void StudentInOrder(T value); 
	//void FacultyInOrder(Faculty n)
	void menuOptions();
	void createStudents();
	void createFaculty();
	void printAdvisees(int facultyIDInput);

private:

	BST<Student> studentBST; //creating the student BST
	BST<Faculty> facultyBST; //creating the faculty BST

};