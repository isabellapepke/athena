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

Faculty::Faculty(string nameInput, string jobInput, string departmentInput, int facultyIDInput, vector<int> listInput)
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

void Faculty::removeAdvisee(int studIDInput)
{
	/*list<int> temp = adviseesList;
	temp.remove(studIDInput);
	if(temp==adviseesList)
	{
		cout<<"Student not found in advisees list of this faculty member"<<endl;
	}
	else
	{
		adviseesList.remove(studIDInput);
		cout<<"Student "<<studIDInput<<" successfully removed"<<endl;
	} */
	//adviseesList.erase(remove(adviseesList.begin(), adviseesList.end(), studIDInput), adviseesList.end());
	
	adviseesList.erase(adviseesList.begin()+1);
}


void Faculty::addAdvisee(int studIDInput)
{
	adviseesList.push_back(studIDInput);
}

//void printFaculty();
//void printFacultyAdvisees();




//Need to finsih code to print advisee list 

void Faculty::printAdviseesList()
{
	/*for (list<int>::const_iterator iterator = adviseesList.begin(), end = adviseesList.end(); iterator != end; ++iterator) 
	{
    	cout << *iterator <<endl;
    }*/
    for(vector<int>::size_type i = 0; i != adviseesList.size(); i++) 
	{
   		cout <<adviseesList[i]<<endl;
	}
}



bool operator== ( Faculty &f1,  Faculty &f2)
{
 	return f1.getID()==f2.getID();
}

bool operator< ( Faculty &f1,  Faculty &f2)
{
 	return f1.getID()<f2.getID();
}

ostream& operator<< (ostream& out, Faculty &f)
{
	out<<"Faculty:\n\tName: "<<f.name<<"\n\tFaculty ID: "<<f.facultyID<<"\n\tDepartment: "<<f.department<<"\n\tJob: "<<f.job<<endl;
	return out;
}

vector<int> Faculty::getAdviseesList()
{
	return adviseesList;

}

void Faculty::printFaculty()
{
	cout<<"Faculty:\n\tName: "<<name<<"\n\tFaculty ID: "<<facultyID<<"\n\tDepartment: "<<department<<"\n\tJob: "<<job<<endl;
	cout<<"\tList of advisees"<< endl;
	printAdviseesList();  
}

int Faculty::getID()
{
	return facultyID;
}

