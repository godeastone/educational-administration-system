#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "CoursePrint.h"
#include "ICommand.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "Variables.h"

using namespace std;

CoursePrint::CoursePrint() : ICommand()
{
	setCommandName("과목 수강생 출력");
}
void CoursePrint::execute()
{
	string prof_name, prof_id, course_id;
	int control1 = 0;
	int control2 = 0;
	int control3 = 0;
	int control4 = 0;

	while (1)
	{
		cout << "교수 이름 : ";
		cin >> prof_name;
		cout << "\n교수 번호 : ";
		cin >> prof_id;

		it_p = professorList.begin();
		while (it_p < professorList.end())
		{
			if (prof_name == (*it_p)->GetName() && prof_id == (*it_p)->GetId())
			{
				control1 = 1;
				break;
			}
			else
			{
				it_p++;
			}
		}

		if (control1 == 0)
		{
			it_p--;
		}

		cout << "**" << prof_name << " 교수님 개설과목" << endl;
		cout << " <과목 이름>        <과목 코드>" << endl;

		it_c = (*it_p)->courseList_p.begin();

		if (it_c == (*it_p)->courseList_p.end() && control1 == 1)
		{
			cout << "##개설 과목이 없습니다." << endl << endl;
			control3 = 1;
			break;
		}

		while (it_c < (*it_p)->courseList_p.end())
		{
			cout << "     " << (*it_c)->GetName() << "          " << (*it_c)->GetId() << endl;
			it_c++;
		}

		cout << endl << endl;
		if (control1 == 1)
		{
			break;
		}
		else
		{
			cout << "##잘못된 교수정보입니다. 다시 입력하세요." << endl << endl;
		}
	}

	while (control3 == 0)
	{
		cout << "과목 코드 : ";
		cin >> course_id;

		cout << "** " << course_id << " 과목 수강학생" << endl;
		cout << " <이름>        <학번>" << endl;
		it_c = courseList.begin();
		while (it_c < courseList.end())
		{
			if (course_id == (*it_c)->GetId())
			{
				it_s = (*it_c)->studentList_c.begin();
				while (it_s < (*it_c)->studentList_c.end())
				{
					cout << " " << (*it_s)->GetName() << "         " << (*it_s)->GetId() << endl;
					it_s++;
				}
				control2 = 1;
				break;
			}
			else
			{
				it_c++;
			}
		}
		if (control2 == 1)
		{
			cout << endl << endl;
			break;
		}
		cout << "##잘못된 과목 코드 입력입니다. 다시 입력하세요" << endl << endl;
	}
}
