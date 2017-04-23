#include <iostream>
#include <string>
#include <algorithm> //for to_upper
#include "Methods.h"

using namespace std;


/*void Methods::StudentInOrder(Student a) 
{
	//studentBST.inOrder(a);
}*/


/*void Methods::FacultyInOrder(Faculty n)
{
	//has to go through using key/ID
	if(n != NULL)
	{
		FacultyInOrder(n->left);
		cout<< n-> key <<endl;//access each object's method 
		FacultyInOrder(n->right);
	}
}*/


int Methods::returnRoot(BST<Student> tree)
{
	return tree.getRoot();
}
int Methods::returnRoot(BST<Faculty> tree)
{
	return tree.getRoot();
}

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

	studentBST.insert(a); //adding the student to the BST

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
	facultyBST.insert(f); //adding the faculty to the BST


}

void Methods::deleteStudent(int ID)
{
	studentBST.remove(ID);
	cout<<"Successfully removed Student"<<endl;
}


void Methods::deleteFaculty(int ID)
{
	facultyBST.remove(ID);
}



void Methods::printAdvisees(int facultyIDInput)
{
	Faculty tempF(facultyBST.find(facultyIDInput));
	list<int> tempAL = tempF.getAdviseesList();
}


void Methods::menuOptions()
{
	//can do if else statements for all options that will call other funcctions
	bool seeMenu = true;
	while(seeMenu)
	{	
		cout << "1. Print all STUDENTS and their information. " <<endl;
		cout << "2. Print all FACULTY and their information. " <<endl; 
		cout << "3. Find and display the student's information given the student's ID" <<endl; //will prompt for student ID in aother fucntion
		cout << "4. Find and display the faculty's information given the faculty's ID" << endl;
		cout << "5. Given a student's ID, print name and info of their advisor " <<endl;
		cout << "6. Given a faculty ID, print ALL names & info of their students" <<endl;
		cout << "7. Add a new Student" <<endl; //call create student in methods
		cout << "8. Delete a student, Give the ID " << endl;
		cout << "9. Add a new faculty member" << endl;
		cout << "10. Delete a faculty member given the ID " <<endl;
		cout << "11. Change a student's advisor given Student ID and new faculty ID" <<endl;
		cout << "12. Remove an advisee from a faculty member given ID" <<endl;
		cout << "13. Rollback" <<endl;
		cout << "14. Exit" << endl <<endl; 

		cout << "Please enter which option you would like (a number): " <<endl;
		string answer;
		cin >> answer;

		int choice = atoi(answer.c_str());

		if(choice==1)
		{
			//will call inorder
			cout<<"You chose choice 1"<<endl;
			studentBST.inOrder();
		}
		
		else if (choice == 2)
		{
			//will call inorder
			cout<<"You chose choice 2"<<endl;
			facultyBST.inOrder();

		}

		else if (choice == 3)
		{

			cout<<"You chose choice 3"<<endl;
			cout<<"Enter the student's ID: "<<endl;
			string idInput;
			cin>>idInput;
			int input = atoi(idInput.c_str());
			Student defaultStudent = Student();
			Student temp = (studentBST.find(input));
			if(temp == defaultStudent)
			{
				//dont print
			}
			else
				cout<<temp;

		}

		else if (choice == 4)
		{
			cout<<"You chose choice 4"<<endl;
			cout << "Enter faculty ID you would like to find: " <<endl;
			string i;
			cin>>i;
			int input = atoi(i.c_str());
			Faculty temp = facultyBST.find(input);
			Faculty defaultFaculty = Faculty();
			if(temp == defaultFaculty)
			{
				//dont print
			}
			else
				cout<<temp;	
		}

		else if (choice == 5)
		{
			cout<<"You chose choice 5"<<endl;
			cout << "Enter the Student's ID: " <<endl;
			int idInput;
			cin >> idInput;

			//print all the info for their faculty advisor 
			//access Student BST and return the Faculty advisor

			//using Faculty ID acces faculty BST and print all info 

			int facultyID;
			facultyID = (studentBST.find(idInput)).getFaculty();
			//cout << "The faculty ID for student is : " << facultyID <<endl;

			(facultyBST.find(facultyID)).printFaculty(); //generate a seg fault because there is no faculty info..otherwise works 
			//add a if statement if no faculty in the 


		}

		else if (choice == 6)
		{
			cout<<"You chose choice 6"<<endl;
			cout<<"Enter the Faculty ID: " <<endl;
			int idInput;
			cin>>idInput;

			list<int> value; 
			value = (facultyBST.find(idInput)).getAdviseesList();

		
/*
			for (int i = 0; i < value.size(); ++ i )
			{
				cout << "student in list: " << value.front() <<endl; 
				value.pop_front();
			}
*/

			list<int>::iterator itt = value.begin();
			itt++;
			itt++;

			for(itt = value.begin(); itt != value.end(); itt++)
			{
				cout<<*itt<<endl; //this is the students ID number 
				//need to access the Student BST and grab student info 
				//(studentBST.find(*itt)).printStudent(); //creates a segmentation fault
			}


			//access the Faculty BST, and get the student ID numbers 
			//access the student BST, in a loop print out all the student info 


		
	

		}

		else if (choice == 7)
		{
			cout<<"You chose choice 7"<<endl;
			createStudents(); 

		}


		else if(choice == 8)
		{
			cout<<"You chose choice 8"<<endl;
			cout << "Enter student ID you would like to delete: " <<endl;
			string i;
			cin>>i;
			int input = atoi(i.c_str());
			deleteStudent(input);
		}
		
		
		else if (choice == 9)
		{
			cout<<"You chose choice 9"<<endl;
			createFaculty();
		}


		else if (choice == 10)
		{
			cout << "Enter faculty ID you would like to delete: " <<endl;
			string i;
			int input = atoi(i.c_str());
			deleteFaculty(input);
		}

		else if(choice == 11)
		{
			cout << "You chose choice 11" <<endl;

			cout << " What is the Student's ID #: " <<endl;
			int idInput;
			cin>>idInput;
			cout << "Enter the new Faculty ID: " <<endl;
			int newID;
			cin>>newID;

			//create temporary students and faculty?
			//if the student BST containts the student
			//BST.find(studentID)

		}

		else if(choice == 12)
		{
			cout << "You chose choice 12" <<endl;

		}

		else if(choice == 13)
		{
			cout << "You chose choice 13" <<endl;
		}

		else if(choice == 14)
		{
			//exit(0);
		}
		

		else
		{
			cout << "You did not enter what we wanted" <<endl;
			//break;
		}
		string menuInput;
		cout<<"Do you want to see the menu again? type Y or N"<<endl;
		cin>>menuInput;
		if(menuInput!="Y")
		{
			seeMenu = false;
		}

	}


}

