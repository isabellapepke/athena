#include <iostream>
#include <string>

#include "methods.h"

using namespace std;


void Methods::StudentInOrder(Student n)
{
	if(n != NULL)
	{
		StudentInOrder(n->left);
		cout<< n-> key <<endl;//access each object's method 
		StudentInOrder(n->right);
	}
}


void Methods::FacultyInOrder(Faculty n)
{
	if(n != NULL)
	{
		FacultyInOrder(n->left);
		cout<< n-> key <<endl;//access each object's method 
		FacultyInOrder(n->right);
	}
}