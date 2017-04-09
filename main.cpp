#include <iostream>
#include <string>
#include <list>
#include "Student.h"

using namespace std;

int main()
{
	Student a;
	a.printStudent();
	//studIDInput, int facultyIDInput, string majorInput, string yearInput, string nameInput, double gpaInput
	Student b(3434,2342,"music","freshman","Bela",.7);
	b.printStudent();
}