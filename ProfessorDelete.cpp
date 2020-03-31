#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "ProfessorDelete.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"


using namespace std;

ProfessorDelete::ProfessorDelete() : ICommand()
{
	setCommandName("Professor deletion");
}
void ProfessorDelete::execute()
{


	studentList_i.push_back(studentList);
	courseList_i.push_back(courseList);
	professorList_i.push_back(professorList);

	////////////////


	while (1)
	{
		string name, id;
		int control = 0;
		cout << "professor name :";
		cin >> name;
		cout << endl;
		cout << "professor number :";
		cin >> id;
		cout << endl;

		it_p = professorList.begin();
		while (it_p < professorList.end())
		{
			if (name == (*it_p)->GetName() && id == (*it_p)->GetId())
			{
				professorList.erase(it_p);
				cout << "professor name : " << name << ",  professor number : " << id << " *deleted*" << endl << endl;
				control = 1;
				break;
			}
			else
			{
				it_p++;
			}
		}
		if (control == 0)
		{
			cout << "Information not matched. try again." << endl << endl;
			continue;
		}
		break;
	}

	studentList_i2.push_back(studentList);
	courseList_i2.push_back(courseList);
	professorList_i2.push_back(professorList);

	/////


	while (!historyList2.empty())
	{
		historyList2.pop();
	}
	////

}

void ProfessorDelete::undo()
{

	studentList.clear();
	courseList.clear();
	professorList.clear();


	int x = studentList_i.size();
	studentList = studentList_i.at(x - 1);
	courseList = courseList_i.at(x - 1);
	professorList = professorList_i.at(x - 1);

	studentList_i.pop_back();
	courseList_i.pop_back();
	professorList_i.pop_back();

}

void ProfessorDelete::redo()
{
	studentList.clear();
	courseList.clear();
	professorList.clear();

	it_s_i = studentList_i2.begin();
	it_c_i = courseList_i2.begin();
	it_p_i = professorList_i2.begin();

	int x = studentList_i2.size();
	studentList = studentList_i2.at(0);
	courseList = courseList_i2.at(0);
	professorList = professorList_i2.at(0);

	studentList_i2.erase(it_s_i);
	courseList_i2.erase(it_c_i);
	professorList_i2.erase(it_p_i);
}
