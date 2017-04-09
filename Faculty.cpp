#include <iostream>
#include <string>

using namespace std;
Faculty::Faculty()
{
	studID = 0;
	facultyID = 0;
	major = "default";
	year = 0;
	gpa = 0.1;
	name = "default";

}

Faculty::Faculty(string nameInput, string jobInput, string departmentInput, int facultyIDInput, list listInput)
{
	studID = studIDInput;
	facultyID = facultyIDInput;
	major = majorInput;
	year = yearInput;
	gpa = gpaInput;
	name = nameInput;
}
