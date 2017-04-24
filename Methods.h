#include <iostream>
#include <string>
#include <stack>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

class Methods
{
public:
	//void StudentInOrder(Student a); 
	//void FacultyInOrder(Faculty n)
	void menuOptions();
	void createStudents();
	void createFaculty();
	void printAdvisees(int facultyIDInput);
	void deleteStudent(int ID);
	void deleteFaculty(int ID);
	int returnRoot(BST<Student> tree);
	int returnRoot(BST<Faculty> tree);


private:

	BST<Student> studentBST; //creating the student BST
	BST<Faculty> facultyBST; //creating the faculty BST
	stack<Student> studentBSTStack; //our stack of student
	stack<Faculty> facultyBSTStack; 

};