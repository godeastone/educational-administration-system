#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "CourseCreation.h"
#include "ICommand.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "Variables.h"

using namespace std;

CourseCreation::CourseCreation() :ICommand()
{
	setCommandName("Create class");
}
void CourseCreation::execute()
{
	int control = 0;
	int count = 1;
	const char *str, *str2;
	it_p = professorList.begin();
	string name, id, professor_id, professor_name, id_t;
	////////////////


	while (1)
	{
		control = 0;
		count = 1;

		cout << "class name you want to create :";
		cin >> name;
		cout << endl;
	Labelt:

		cout << "number of class you want to create :";
		cin >> id;
		cout << endl;

		str = id.c_str();
		int x = 0;
		int y = 0;
		int z = 0;
		int p = 0;
		x = str[2] - 48;
		y = str[3] - 48;
		z = str[4] - 48;
		p = str[5] - 48;
		if (str[0] != 'C' || str[1] != 'S' || x > 9 || x < 0 || y>9 || y < 0 || z>9 || z < 0 || p != -48)
		{//과목코드 입력조건 확인
			cout << "##class number should starts with CS, and three number." << endl;
			goto Labelt;
		}
		cout << "Professor number of class :";
		cin >> professor_id;
		cout << endl;

		it_c = courseList.begin();
		while (it_c < courseList.end())
		{
			string id_1 = (*it_c)->GetId();
			str2 = id_1.c_str();
			string id_2 = id.c_str();
			if (id_2[2] == str2[2] && id_2[3] == str2[3] && id_2[4] == str2[4] && name == (*it_c)->GetName())
			{
				count++;
				it_c++;
			}
			else
			{
				it_c++;
			}
		}
		if (count != 1)
		{//이름과 코드가 같은과목이 있을 경우 '- n'의 tag를 붙여줌.
			id_t = id;
			string tag = to_string(count);
			id = id + "-" + tag;
			/*
			if (count == 2)
			{
				it_c = courseList.begin();
				while (it_c < courseList.end())
				{
					if ((*it_c)->GetName() == name && (*it_c)->GetId() == id_t)
					{
						(*it_c)->SetId((*it_c)->GetId() + "-1");
						break;
					}
					else
					{
						it_c++;
					}
				}
			}*/

		}


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
			cout << "Information not matched. try again." << endl << endl;
			continue;
		}
		Course *st = new Course(name, id, professor_id, professor_name);
		//새로운 Course 객체를 생성하고
		courseList.push_back(st);
		//courseList 벡터에 삽입

		it_p = professorList.begin();
		while (it_p < professorList.end())
		{
			if (professor_id == (*it_p)->GetId() && professor_name == (*it_p)->GetName())
			{
				(*it_p)->courseList_p.push_back(st);
				break;
			}
			else
			{
				it_p++;
			}
		}
		cout << "class name : " << name << "  class number : " << id << "  professor : " << professor_name << " register complete" << endl << endl;

		if (control == 1)
		{
			break;
		}
		else
		{
			cout << "Information not matched. try again." << endl << endl;
		}
	}

	coursecreation_id.push_back(id);
	coursecreation_id_c.push_back(professor_id);
	coursecreation_name.push_back(name);
	coursecreation_name_c.push_back(professor_name);



	/////


	while (!historyList2.empty())
	{
		historyList2.pop();
	}
	////
}

void CourseCreation::undo()
{
	string name, id, professor_name, professor_id;
	int x = coursecreation_id.size();

	name = coursecreation_name.at(x - 1);
	professor_name = coursecreation_name_c.at(x - 1);
	id = coursecreation_id.at(x - 1);
	professor_id = coursecreation_id_c.at(x - 1);

	coursecreation_id2.push_back(id);
	coursecreation_id_c2.push_back(professor_id);
	coursecreation_name2.push_back(name);
	coursecreation_name_c2.push_back(professor_name);

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


	coursecreation_id.pop_back();
	coursecreation_id_c.pop_back();
	coursecreation_name.pop_back();
	coursecreation_name_c.pop_back();
}



void CourseCreation::redo()
{
	string name, id, professor_name, professor_id;
	int x = coursecreation_id2.size();

	name = coursecreation_name2.at(x - 1);
	professor_name = coursecreation_name_c2.at(x - 1);
	id = coursecreation_id2.at(x - 1);
	professor_id = coursecreation_id_c2.at(x - 1);

	///////

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

	coursecreation_id2.pop_back();
	coursecreation_id_c2.pop_back();
	coursecreation_name2.pop_back();
	coursecreation_name_c2.pop_back();

}
