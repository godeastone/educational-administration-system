#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "CourseCancel.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "Variables.h"
#include "ICommand.h"


using namespace std;

CourseCancel::CourseCancel() : ICommand()
{
	setCommandName("���� ��");
}
void CourseCancel::execute()
{


	int control = 0;

	string name, id, professor_id, professor_name;

	////////////////


	while (1)
	{

		control = 0;
		cout << "���� ���� �̸� :";
		cin >> name;
		cout << endl;
		cout << "���� ���� �ڵ� :";
		cin >> id;
		cout << endl;
		cout << "��� ���� ��ȣ :";
		cin >> professor_id;
		cout << endl;
		it_p = professorList.begin();
		while (it_p < professorList.end())
		{
			if (professor_id == (*it_p)->GetId())
			{
				professor_name = (*it_p)->GetName();
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
			cout << "��ȿ���� ���� �����Դϴ�. �ٽ��Է��ϼ���." << endl << endl;
			continue;
		}

		it_p = professorList.begin();
		while (it_p < professorList.end())
		{
			if (professor_name == (*it_p)->GetName() && professor_id == (*it_p)->GetId())
			{
				it_c2 = (*it_p)->courseList_p.begin();
				while (it_c2 < (*it_p)->courseList_p.end())
				{
					if ((*it_c2)->GetName() == name && (*it_c2)->GetId() == id)
					{
						(*it_p)->courseList_p.erase(it_c2);
						goto Label9;
					}
					else
					{
						it_c2++;

					}
				}

				break;
			}
			else
			{
				it_p++;
			}
		}
	Label9:

		it_c = courseList.begin();
		while (it_c < courseList.end())
		{
			if ((*it_c)->GetName() == name && (*it_c)->GetProf_Name() == professor_name && (*it_c)->GetId() == id)
			{
				courseList.erase(it_c);
				//iterator�� �̿��Ͽ� courseList�� ������ ����
				cout << professor_name + "�������� " + name + "������ �����Ǿ����ϴ�." << endl << endl;
				control = 0;
				break;
			}
			else
			{
				it_c++;
			}
		}
		if (control == 0)
		{
			break;
		}
		else
		{
			cout << "��ȿ���� ���� �����Դϴ�. �ٽ� �Է��ϼ���." << endl << endl;
		}
	}

	coursecancel_id.push_back(id);
	coursecancel_id_c.push_back(professor_id);
	coursecancel_name.push_back(name);
	coursecancel_name_c.push_back(professor_name);



	/////


	while (!historyList2.empty())
	{
		historyList2.pop();
	}
	////


}

void CourseCancel::undo()
{
	string name, id, professor_name, professor_id;
	int x = coursecancel_id.size();

	name = coursecancel_name.at(x - 1);
	professor_name = coursecancel_name_c.at(x - 1);
	id = coursecancel_id.at(x - 1);
	professor_id = coursecancel_id_c.at(x - 1);

	coursecancel_id2.push_back(id);
	coursecancel_id_c2.push_back(professor_id);
	coursecancel_name2.push_back(name);
	coursecancel_name_c2.push_back(professor_name);

	it_s = studentList.begin();
	it_c = courseList.begin();
	it_p = professorList.begin();

	Course *cr = new Course(name, id, professor_id, professor_name);

	courseList.push_back(cr);

	while (it_p < professorList.end())
	{
		if ((*it_p)->GetId() == professor_id && (*it_p)->GetName() == professor_name)
		{
			(*it_p)->courseList_p.push_back(cr);
			break;
		}
		else
		{
			it_p++;
		}
	}

	coursecancel_id.pop_back();
	coursecancel_id_c.pop_back();
	coursecancel_name.pop_back();
	coursecancel_name_c.pop_back();


}

void CourseCancel::redo()
{
	string name, id, professor_name, professor_id;
	int x = coursecancel_id2.size();

	name = coursecancel_name2.at(x - 1);
	professor_name = coursecancel_name_c2.at(x - 1);
	id = coursecancel_id2.at(x - 1);
	professor_id = coursecancel_id_c2.at(x - 1);

	////////

	it_s = studentList.begin();
	it_c = courseList.begin();


	while (it_c < courseList.end())
	{
		if ((*it_c)->GetName() == name && (*it_c)->GetId() == id)
		{
			courseList.erase(it_c);
			break;
		}
		else
		{
			it_c++;
		}
	}

	it_p = professorList.begin();
	while (it_p < professorList.end())
	{
		if ((*it_p)->GetName() == professor_name && (*it_p)->GetId() == professor_id)
		{
			it_c2 = (*it_p)->courseList_p.begin();
			while (it_c2 < (*it_p)->courseList_p.end())
			{
				if ((*it_c2)->GetName() == name && (*it_c2)->GetId() == id)
				{
					(*it_p)->courseList_p.erase(it_c2);
					goto Label10;
				}
				else
				{
					it_c2++;
				}
			}
		}
		else
		{
			it_p++;
		}
	}
Label10:


	coursecancel_id2.pop_back();
	coursecancel_id_c2.pop_back();
	coursecancel_name2.pop_back();
	coursecancel_name_c2.pop_back();
}