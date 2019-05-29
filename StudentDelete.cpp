#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"
#include "StudentDelete.h"


using namespace std;


StudentDelete::StudentDelete() : ICommand()
{
	setCommandName("학생 삭제");
}
void StudentDelete::execute()
{


	studentList_i.push_back(studentList);
	courseList_i.push_back(courseList);
	professorList_i.push_back(professorList);

	////////////////


	while (1)
	{
		string name, id;
		int control = 0;
		cout << "학생 이름 :";
		cin >> name;
		cout << endl;
		cout << "학생 번호 :";
		cin >> id;
		cout << endl;

		it_s = studentList.begin();
		while (it_s < studentList.end())
		{
			if (name == (*it_s)->GetName() && id == (*it_s)->GetId())
			{
				studentList.erase(it_s);
				cout << "학생 이름 : " << name << ",  학생 번호 : " << id << " *삭제되었음*" << endl << endl;
				control = 1;
				break;
			}
			else
			{
				it_s++;
			}
		}
		if (control == 0)
		{
			cout << "입력한 정보의 학생이 없습니다." << endl << endl;
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

void StudentDelete::undo()
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

void StudentDelete::redo()
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