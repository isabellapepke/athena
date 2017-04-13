#include <iostream>
#include <string>
#include "Faculty.h"

using namespace std;
Faculty::Faculty()
{
	
	name = "default";
	job = "default";
	department = "default";
	facultyID = 0;

}

Faculty::Faculty(string nameInput, string jobInput, string departmentInput, int facultyIDInput, list<int> listInput)
{
	name = nameInput;
	facultyID = facultyIDInput;
	department = departmentInput;
	adviseesIDs  = listInput;
	job = jobInput;
	
}
Faculty::~Faculty()
{

}
/*void printFaculty();
	void printFacultyAdvisees();
	void addAdvisee();*/




//Need to finsih code to print advisee list 
/*
void Faculty::printAdviseesList()
{
	
	for(auto i = adviseesIDs.begin(); i != adviseesIDs.end(); ++i) 
	{
    	cout<<i.print
   	}
		
}

*/


void Faculty::printFaculty()
{
	cout<<"Faculty:\n\tName: "<<name<<"\n\tFaculty ID: "<<facultyID<<"\n\tDepartment: "<<department<<"\n\tJob: "<<job<<endl;
	cout<<"\tList of advisees"<<endl;
	//call printAdvisees list
}
int Faculty::getID()
{
	return facultyID;
}