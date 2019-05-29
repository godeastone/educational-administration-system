#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"
#include "PrintCourse.h"


using namespace std;

string name3;

PrintCourse::PrintCourse() : ICommand()
{
	setCommandName("��ü ���� ���� ���");
}
void PrintCourse::execute()
{
	it_c = courseList.begin();
	int num;

	while (it_c < courseList.end())
	{
		string name, id, prof, profid, stu_name, stu_id;
		name = (*it_c)->GetName();
		id = (*it_c)->GetId();
		prof = (*it_c)->GetProf_Name();
		profid = (*it_c)->GetProf_Id();
		it_p = professorList.begin();
		//course �� professor �� �޼ҵ带 �̿��Ͽ� ������ �Ҵ���
		it_s = (*it_c)->studentList_c.begin();
		num = (*it_c)->studentList_c.size();

		cout << "**" << name << " ����(" << id << ") �л�����** - ��米�� : " << prof << "(" << profid << ")" << "\n***�л� �� : " << num << endl;
		cout << "-----<�̸�>------------<�й�>----------" << endl;
		while (it_s < (*it_c)->studentList_c.end())
		{
			stu_name = (*it_s)->GetName();
			stu_id = (*it_s)->GetId();
			cout << setw(11) << stu_name << "           " << setw(10) << stu_id << endl;
			it_s++;
		}


		/////////////////////
		if (courseList.empty())
		{
			cout << "������ ������ �����ϴ�." << endl << endl;
			break;
		}
		it_c++;
		cout << endl << endl;
	}
	cout << endl;
}
