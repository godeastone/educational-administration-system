#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"
#include "PrintPerson.h"


using namespace std;

string name2;

PrintPerson::PrintPerson() : ICommand()
{
	setCommandName("Show all people's information");
}
void PrintPerson::execute()
{
	string name, id, course, grade, course_id;
	cout << "****student information****" << endl;
	it_s = studentList.begin();
	while (it_s < studentList.end())
	{
		name = (*it_s)->GetName();
		id = (*it_s)->GetId();

		cout << name << " student(" << id << ")'s classes---<class>------<grade>-------\n";
		it_c = (*it_s)->courseList_s.begin();
		while (it_c < (*it_s)->courseList_s.end())
		{
			course = (*it_c)->GetName();
			grade = (*it_c)->GetGrade();
			cout << "                                      " << course << "        " << grade << endl;
			it_c++;
		}
		it_s++;
		cout << endl << endl;

	}

	cout << "\n\n\n****professor information****" << endl;
	it_p = professorList.begin();
	while (it_p < professorList.end())
	{
		name = (*it_p)->GetName();
		id = (*it_p)->GetId();

		cout << name << " professor(" << id << ")'s information---<class>------<number of classes>-------\n";
		it_c = (*it_p)->courseList_p.begin();
		while (it_c < (*it_p)->courseList_p.end())
		{
			course = (*it_c)->GetName();
			course_id = (*it_c)->GetId();

			cout << "                            " << course << "        " << course_id << endl;
			it_c++;
		}
		it_p++;
		cout << endl;
	}

}
