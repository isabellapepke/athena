#include <iostream>
#include <string>
#include <list>
using namespace std;

class Faculty
{
public:
	Faculty();
	~Faculty();
	Faculty(string nameInput, string jobInput, string departmentInput, int facultyIDInput, list<int> listInput);
	void printFaculty();
	void printFacultyAdvisees();
	void addAdvisee();
	void printAdviseesList();
	int getID();
private:
	string name, job, department;
	int facultyID;
	list<int> adviseesIDs;
};
