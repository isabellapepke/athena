#include <iostream>
#include <string>
#include <list>
using namespace std;

class Faculty
{
public:
	Faculty();
	~Faculty();
	Faculty(string nameInput, string jobInput, string departmentInput, int facultyIDInput, list listInput);
private:
	string name, job, department;
	int facultyID;
	list<int> adviseeID;
};
