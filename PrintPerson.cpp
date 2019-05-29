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
	setCommandName("��ü �ο� ���� ���");
}
void PrintPerson::execute()
{
	string name, id, course, grade, course_id;
	cout << "****�л� ����****" << endl;
	it_s = studentList.begin();
	while (it_s < studentList.end())
	{
		name = (*it_s)->GetName();
		id = (*it_s)->GetId();

		cout << name << " �л�(" << id << ")�� ��������---<����>------<����>-------\n";
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

	cout << "\n\n\n****���� ����****" << endl;
	it_p = professorList.begin();
	while (it_p < professorList.end())
	{
		name = (*it_p)->GetName();
		id = (*it_p)->GetId();

		cout << name << " ����(" << id << ")�� ����---<����>------<�����ڵ�>-------\n";
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
