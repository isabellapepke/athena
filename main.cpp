#include <iostream>
#include <string>
#include <list>
#include "Student.h"
#include "Faculty.h"
#include "BST.h"

using namespace std;

int main()
{
	
	//studIDInput, int facultyIDInput, string majorInput, string yearInput, string nameInput, double gpaInput
	Student b(3434,2342,"music","freshman","Bela",.7);
	b.printStudent();
	Faculty d;
	d.printFaculty();
	BST<Student> studentBST;
	studentBST.insert(b);

	studentBST.remove();


}