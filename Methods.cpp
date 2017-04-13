#include <iostream>
#include <string>

#include "Methods.h"
#include "Student.h"

using namespace std;

/*

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

*/

void Methods::createStudents()
{	
	int studentIDInput, facultyIDInput;
	string majorInput, yearInput, nameInput;
	double gpaInput;

	cout << "Enter Student ID number:  " <<endl;
	cin >> studentIDInput;
	cout<< "Enter Faculty ID number: " <<endl;
	cin >> facultyIDInput;
	cout << "Enter Major of Student: " <<endl;
	cin >> majorInput;
	cout << "Enter year of student: " <<endl;
	cin >> yearInput;
	cout << " Enter name of student: " <<endl;
	cin >> nameInput;
	cout << "Enter gpa of student: " <<endl;
	cin >> gpaInput;

	Student a(studentIDInput, facultyIDInput, majorInput, yearInput, nameInput, gpaInput);

	a.printStudent();
}



void Methods::createFaculty()
{
	string fNameInput, jobInput, departmentInput;
	int facultyIDInput;
	list<int> adviseesListInput;

	cout << "Enter Faculty name:  " <<endl;
	cin >> fNameInput;
	cout<< "Enter job of faculty: " <<endl;
	cin >> jobInput;
	cout << "Enter department of faculty: " <<endl;
	cin >> departmentInput;
	cout << "Enter faculty ID number: " <<endl;
	cin >> facultyIDInput;

	cout << "How many students is the Faculty an advisor for (how many students will you add this faculty as their advisor)?" << endl;
	int i;//how many ids they are entering
	int idInput;//student id input
	cin>> i;
	for( int j = 0; j < i; ++ j)
	{
		cout<< "Student ID number: " <<endl;

		cin>> idInput;
		adviseesListInput.push_back(idInput);
	}
	cout<<"Done entering advisees to the Faculty person"<<endl;

	Faculty f(fNameInput, jobInput, departmentInput, facultyIDInput, adviseesListInput);
	f.printFaculty();

}

void Methods::printAdvisees(int facultyIDInput)
{
	//Faculty tempF = new Faculty(facultyBST.find(facultyIDInput));
	//lint<int> tempAL = tempF.getAdviseesList();
}



//Faculty::Faculty(string nameInput, string jobInput, string departmentInput, int facultyIDInput, list<int> listInput)




void Methods::printMenu()
{
	cout << " Press 1 for add a Student \n\n Press 2 for add a new Faculty: " <<endl;
	string answer;
	cin >> answer;
	//int choice = std::stoi(answer);

	int choice = atoi(answer.c_str());

	if (choice == 1)
	{
		createStudents(); 

	}
	
	
	else if (choice == 2)
	{
		createFaculty();
	}
	
	else
	{
		cout << "You did not enter what we wanted" <<endl;
		//break;
	}
}


