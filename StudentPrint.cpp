#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "StudentPrint.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"


using namespace std;

StudentPrint::StudentPrint() : ICommand()
{
	setCommandName("학생 정보 조회");
}
void StudentPrint::execute()
{
	string id1;
	int control = 0;

	while (1)
	{
		cout << "조회할 학생의 학번 :";
		cin >> id1;
		it_s = studentList.begin();
		while (it_s < studentList.end())
		{
			if (id1 == (*it_s)->GetId())
			{
				cout << "\n**학생 이름 :" << (*it_s)->GetName() << endl << endl;
				cout << "**" << (*it_s)->GetName() << "학생 수강현황**" << endl;
				cout << "<과목명>     <성적>" << endl;

				it_c = (*it_s)->courseList_s.begin();
				string str;
				if ((*it_s)->courseList_s.end() == (*it_s)->courseList_s.begin())
				{
					cout << "수강중인 과목이 없습니다." << endl << endl;
					control = 1;
					break;
				}

				while (it_c < (*it_s)->courseList_s.end())
				{
					str += "   ";
					str += (*it_c)->GetName();
					str += "          ";
					str += (*it_c)->GetGrade();
					if ((*it_c)->GetGrade() == "\0")
					{
						str += "등록된 점수가 없습니다.";
					}
					str += "\n";
					it_c++;
				}
				cout << str << endl << endl;

				control = 1;
				break;
			}
			else
			{
				it_s++;
			}
		}
		cout << endl;
		if (control == 0)
		{
			cout << "잘못된 학번입니다. 다시 입력하세요." << endl << endl;
			continue;
		}
		else
		{
			break;
		}
	}
}
