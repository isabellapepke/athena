#include <iostream>
#include <string>
#include <algorithm> //for to_upper
#include "Methods.h"

using namespace std;

void Methods::copyToSStack(BST<Student> tree)
{
	studentStack.push(tree);
}
void Methods::copyToFStack(BST<Faculty> tree)
{
	facultyStack.push(tree);
}


void Methods::createStudents()
{	
	int studentIDInput, facultyIDInput;
	string majorInput, yearInput, nameInput, input;
	double gpaInput;

	cout << "Enter Student ID number:  " <<endl;
	cin >> input;
	studentIDInput = atoi(input.c_str());
	cout<< "Enter Faculty ID number: " <<endl;
	cin >> input;
	//search if faculty already created if not prompt for
	facultyIDInput = atoi(input.c_str());
	cout << "Enter Major of Student: " <<endl;
	cin >> majorInput;
	cout << "Enter year of student: " <<endl;
	cin >> yearInput;
	cout << "Enter name of student: " <<endl;
	cin >> nameInput;
	cout << "Enter gpa of student: " <<endl;
	cin >> input;
	gpaInput = atoi(input.c_str());
	Student a(studentIDInput, facultyIDInput, majorInput, yearInput, nameInput, gpaInput);
	cout<<a<<endl;
	studentBST.insert(a);

	//if faculty not found immeadiately prompt
	Faculty defaultFaculty = Faculty();
	Faculty temp = facultyBST.find(facultyIDInput);
	if(temp==defaultFaculty)
	{
		cout<<"We do not have records of that faculty memeber. Please enter the following information: "<<endl;
		createFaculty();
	}
	else
	{
		//add student to faculty list find faculy then add the student
		temp.addAdvisee(studentIDInput);

	}

}



void Methods::createFaculty()
{
	string fNameInput, jobInput, departmentInput, input;
	int facultyIDInput;
	vector<int> adviseesListInput;
	cout << "Enter faculty ID number: " <<endl;
	cin >> input;
	cout << "Enter Faculty name:  " <<endl;
	cin >> fNameInput;
	cout<< "Enter job of faculty: " <<endl;
	cin >> jobInput;
	cout << "Enter department of faculty: " <<endl;
	cin >> departmentInput;
	
	facultyIDInput = atoi(input.c_str());
	cout << "How many students is the Faculty an advisor for (how many students will you add this faculty as their advisor)?" << endl;
	int i;//how many ids they are entering
	int idInput;//student id input
	cin>> i;
	for( int j = 0; j < i; ++ j)
	{
		cout<< "Student ID number: " <<endl;

		cin>> idInput;


		//addAdvisee(idInput);
		adviseesListInput.push_back(idInput);
	}
	//cout<<"Done entering advisees to the Faculty person"<<endl;

	Faculty f(fNameInput, jobInput, departmentInput, facultyIDInput, adviseesListInput);
	facultyBST.insert(f); //adding the faculty to the BST
	Student defaultStudent = Student();
	//vector<int>  f.getAdviseesList();
	//iterate
	/*for(vector<int>::size_type i = 0; i != f.getAdviseesList().size(); i++) 
        {
        	cout<<"seg fault here??";

        	Student temp = studentBST.find(f.getAdviseesList()[i]);
			if(temp==defaultStudent)
			{
				cout<<"We do not have records of that student. Please enter the following information: "<<endl;
				createStudents();
			}
		}*/
}

void Methods::deleteStudent(int ID)
{
	studentBST.remove(ID);
	cout<<"Student was deleted"<<endl;
}


void Methods::deleteFaculty(int ID)
{
	facultyBST.remove(ID);
	cout << "Faculty was deleted " <<endl;
}



void Methods::printAdvisees(int facultyIDInput)
{
	Faculty tempF(facultyBST.find(facultyIDInput));
	vector<int> tempAL = tempF.getAdviseesList();
}


void Methods::menuOptions()
{
	//can do if else statements for all options that will call other funcctions
	bool seeMenu = true;
	while(seeMenu)
	{	

		cout << "\n\t1. Print all STUDENTS and their information. " <<endl;
		cout << "\t2. Print all FACULTY and their information. " <<endl; 
		cout << "\t3. Find and display the student's information given the student's ID" <<endl; //will prompt for student ID in aother fucntion
		cout << "\t4. Find and display the faculty's information given the faculty's ID" << endl;
		cout << "\t5. Given a student's ID, print name and info of their advisor " <<endl;
		cout << "\t6. Given a faculty ID, print ALL names & info of their students" <<endl;
		cout << "\t7. Add a new Student" <<endl; //call create student in methods
		cout << "\t8. Delete a student, Give the ID " << endl;
		cout << "\t9. Add a new faculty member" << endl;
		cout << "\t10. Delete a faculty member given the ID " <<endl;
		cout << "\t11. Change a student's advisor given Student ID and new faculty ID" <<endl;
		cout << "\t12. Remove an advisee from a faculty member given ID" <<endl;
		cout << "\t13. Rollback" <<endl;
		cout << "\t14. Exit" << endl <<endl; 

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

		else if (choice == 3)//display student info 
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
			string idInput;
			cin >> idInput;
			int input = atoi(idInput.c_str());
			Student defaultStudent = Student();
			Student temp = studentBST.find(input);

			if(temp == defaultStudent)
			{
				//student doesnot exist
			}
			else
			{
				int facultyID;
				facultyID = (studentBST.find(input)).getFaculty();
				//cout << "The faculty ID for student is : " << facultyID <<endl;
				facultyBST.find(facultyID);
			//generate a seg fault because there is no faculty info..otherwise works 
			//add a if statement if no faculty in the 
			} 
			//push on stack

		}


		else if (choice == 6)
		{
			cout<<"You chose choice 6"<<endl;
			cout<<"Enter the Faculty ID: " <<endl;
			string idInput;
			cin >> idInput;
			int input = atoi(idInput.c_str()); 
			vector<int> advisees = (facultyBST.find(input)).getAdviseesList();
	
			int temp;
			for(vector<int>::size_type i = 0; i < advisees.size(); i++) 
			{
   				//i = value[i];
   				Student adviseeStud = (studentBST.find(advisees[i]));
				cout<<adviseeStud;
			}
			
			/*for (list<int>::const_iterator itt = value.begin(), end = value.end(); itt != end; ++itt) 
			{
				temp = *itt; //this is the students ID number 
				//need to access the Student BST and grab student info 
			//	(studentBST.find(temp)).printStudent(); 
				Student adviseeStud = (studentBST.find(temp));
				cout<<adviseeStud;
			}*/


		}



		else if (choice == 7)
		{
			cout<<"You chose choice 7"<<endl;
			createStudents(); 
			//push on stack
			copyToSStack(studentBST);

		}


		else if(choice == 8)
		{
			cout<<"You chose choice 8"<<endl;
			cout << "Enter student ID you would like to delete: " <<endl;
			string i;
			cin>>i;
			int input = atoi(i.c_str());
			Student defaultStudent = Student();
			Student temp = studentBST.find(input);

			if(temp == defaultStudent)
			{
				//student doesnot exist
			}
			else
				deleteStudent(input);
		}
		
		
		else if (choice == 9)
		{
			cout<<"You chose choice 9"<<endl;
			createFaculty();
			//push on stack
			copyToFStack(facultyBST);
		}


		else if (choice == 10)
		{
			cout << "Enter faculty ID you would like to delete: " <<endl;
			string i;
			cin>>i;
			int input = atoi(i.c_str());
			Faculty defaultFaculty = Faculty();
			Faculty temp = facultyBST.find(input);

			if(temp == defaultFaculty)
			{
				//student doesnot exist
			}
			else
				deleteFaculty(input);
			//push on stack
			copyToFStack(facultyBST);
		}

		else if(choice == 11)
		{
			cout << "You chose choice 11" <<endl;
			string input;
			cout << "What is the Student's ID #: " <<endl;
			cin>>input;
			int idInput = atoi(input.c_str());
			Student defaultStudent = Student();
			Student temp = studentBST.find(idInput);

			if(temp == defaultStudent)
			{
				//student doesnot exist
			}
			else
			{
				cout << "Enter the new Faculty ID: " <<endl;
				int newID;
				cin>>input;
				int oldFacultyID;
				newID = atoi(input.c_str());

				//create temporary students and faculty?
				//if the student BST containts the student
				if(temp.getFaculty() != newID)
				{
					oldFacultyID = temp.getFaculty();
					temp.changeAdvisor(newID);
				}
				
				else
				{
					//advisor is already assigned
				}

				//removing the student from the old advisor 
				Faculty tempF = facultyBST.find(oldFacultyID);
				tempF.removeAdvisee(idInput); 

				//need to add the new student ID to the list
				Faculty tempF2 = facultyBST.find(newID);
				tempF2.addAdvisee(idInput);
			}
			//push on stack
			copyToFStack(facultyBST);
			copyToSStack(studentBST);
		}

		else if(choice == 12)
		{
			//Remove an advisee from a faculty member given ID"

			cout << "You chose choice 12" <<endl;
			string i;
			cout << "Enter the ID of the advisee (student) you wish to remove: "<<endl;
			cin>>i;
			int input = atoi(i.c_str());
			Student studentInput = studentBST.find(input);
			Student defaultStudent = Student();
			if(studentInput == defaultStudent)
			{
				//student doesnt not exist
			}
			else
			{
				//cout<<"in remove advisee"<<endl;
				Faculty tempF = facultyBST.find(studentInput.getFaculty());
				Faculty defaultFaculty = Faculty();
				if(tempF ==defaultFaculty)
				{

				}
				else
				{
					tempF.removeAdvisee(input);
				}

			}
			//push on stack
			copyToFStack(facultyBST);
			copyToSStack(studentBST);

		}

		else if(choice == 13)
		{
			//13. Rollback
			cout << "You chose choice 13" <<endl;

			//studentBST = studentStack.pop();
			//facultyBST = facultyStack.pop();
		}

		else if(choice == 14)
		{
			cout << "You chose the exit the program. GOODBYE"<<endl;
			studentBST.printSToFile();
			facultyBST.printFToFile();
			exit(0);
		}
		

		else
		{
			cout << "You did not enter what we wanted" <<endl;
			//break;
		}
		

	}


}

