#include <iostream>
#include <string>
#include <list>
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "Methods.h"

using namespace std;

int main()
{
	
	//studIDInput, int facultyIDInput, string majorInput, string yearInput, string nameInput, double gpaInput
	Student b(3434,2342,"music","freshman","Bela",.7);
	b.printStudent();
	Student c(4,5,"beeetle","sophomore", "beep", 2.5);
	Faculty d;
	d.printFaculty();
	BST<Student> studentBST;
	studentBST.insert(b);
	studentBST.insert(c);
	cout<< "Max value is: " << studentBST.getMax()<<endl;
	cout<< "Min value is: " << studentBST.getMin()<<endl;
	studentBST.remove(3434);
	

	Methods newMethod;
	newMethod.menuOptions();
	//studentBST.inOrder(); //need to order student ID 

	//studentBST.remove();

 	return 0;
}




