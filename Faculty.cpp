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
	job = jobInput;
	facultyID = facultyIDInput;
	department = departmentInput;
	adviseesList  = listInput;
	
}

Faculty::Faculty( int facultyIDInput)
{
	facultyID = facultyIDInput;
}

Faculty::~Faculty()
{

}

bool operator< ( Faculty &f1,  Faculty &f2)
{
 	return f1.getID()<f2.getID();
}
/*void printFaculty();
	void printFacultyAdvisees();
	void addAdvisee();*/




//Need to finsih code to print advisee list 
/*
void Faculty::printAdviseesList()
{
	
	for(auto i = adviseesList.begin(); i != adviseesList.end(); ++i) 
	{
    	cout<<i.print
   	}
		
}

*/
ostream& operator<< (ostream& out, Faculty &f)
{
	out<<"Faculty:\n\tName: "<<f.name<<"\n\tFaculty ID: "<<f.facultyID<<"\n\tDepartment: "<<f.department<<"\n\tJob: "<<f.job<<endl;
	return out;
}

list<int> Faculty::getAdviseesList()
{
	return adviseesList;

}

void Faculty::printFaculty()
{
	cout<<"Faculty:\n\tName: "<<name<<"\n\tFaculty ID: "<<facultyID<<"\n\tDepartment: "<<department<<"\n\tJob: "<<job<<endl;
	cout<<"\tList of advisees"<< endl; //need to iterate through the list/array to print out 
	//call printAdvisees list
}
int Faculty::getID()
{
	return facultyID;
}

