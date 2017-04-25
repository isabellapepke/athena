#include <iostream>
#include <string>
#include <stack>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "TreeNode.h"

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
	//BST<Student> copyStudentBST(TreeNode<Faculty> curr);
	//BST<Faculty> copyFacultyBST(TreeNode<Student> curr);
	void copyToSStack(BST<Student> tree);
	void copyToFStack(BST<Faculty> tree);


private:

	BST<Student> studentBST; //creating the student BST
	BST<Faculty> facultyBST; //creating the faculty BST
	stack<BST<Student> > studentStack; //our stack of studentBSTs
	stack<BST<Faculty> > facultyStack; //out stack of facultyBSTs

};