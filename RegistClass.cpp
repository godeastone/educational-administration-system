#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "RegistClass.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"

using namespace std;



RegistClass::RegistClass() : ICommand()
{
	setCommandName("regist subject");

}
void RegistClass::execute()
{

	////////////////
	string p;

	while (1)
	{
		cout << "student name : ";
		cin >> name;
		cout << endl;
		cout << "student number : ";
		cin >> id;
		cout << endl;


		it_s = studentList.begin();
		while (it_s < studentList.end())
		{
			if (name == (*it_s)->GetName() && id == (*it_s)->GetId())
			{
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
			cout << "##Information not matched. try again." << endl << endl;
		}
		else
		{
			break;
		}
	}

	cout << "***** Available subjects *****" << endl;

	it_c = courseList.begin();
	while (it_c < courseList.end())
	{
	Label5:

		it_c2 = (*it_s)->courseList_s.begin();
		while (it_c2 < (*it_s)->courseList_s.end())
		{
			if ((*it_c2)->GetName() == (*it_c)->GetName() && (*it_c2)->GetId() == (*it_c)->GetId())
			{
				it_c++;
				num++;
				goto Label5;
			}
			else
			{
				it_c2++;
			}
		}
		cout << num << ". " << (*it_c)->GetId() << "   " << (*it_c)->GetName() << "   " << p << endl;
		num++;
		it_c++;
	}
	cout << "*********************************" << endl;

	it_c = courseList.begin();

Label:

	cout << "\n**Enter the number of subjects you want to register : ";
	cin >> sel;
	if (sel > num - 1)
	{
		cout << "Information not matched. try again" << endl << endl;
		goto Label;
	}
	it_c += sel - 1;
	Student *st = new Student(name, id);
	(*it_c)->studentList_c.push_back(st);




	name_c = (*it_c)->GetName();
	id_c = (*it_c)->GetId();

	it_s = studentList.begin();
	while (it_s < studentList.end())
	{
		if (name == (*it_s)->GetName() && id == (*it_s)->GetId())
		{
			Course *cr = new Course(name_c, id_c, "profid", "prof");
			(*it_s)->courseList_s.push_back(cr);

			break;
		}
		else
		{
			it_s++;
		}
	}
	cout << "$$register complete$$" << endl << endl;

	registclass_id.push_back(id);
	registclass_id_c.push_back(id_c);
	registclass_name.push_back(name);
	registclass_name_c.push_back(name_c);



	num = 1;
	control = 0;



	/////


	while (!historyList2.empty())
	{
		historyList2.pop();
	}
	////

}

void RegistClass::undo()
{

	int x = registclass_id.size();

	name = registclass_name.at(x - 1);
	name_c = registclass_name_c.at(x - 1);
	id = registclass_id.at(x - 1);
	id_c = registclass_id_c.at(x - 1);

	registclass_id2.push_back(id);
	registclass_id_c2.push_back(id_c);
	registclass_name2.push_back(name);
	registclass_name_c2.push_back(name_c);
	//redo

	it_s = studentList.begin();
	it_c = courseList.begin();

	while (it_s < studentList.end())
	{
		if (name == (*it_s)->GetName() && id == (*it_s)->GetId())
		{
			break;
		}
		else
		{
			it_s++;
		}
	}
	while (it_c < courseList.end())
	{
		if (name_c == (*it_c)->GetName() && id_c == (*it_c)->GetId())
		{
			break;
		}
		else
		{
			it_c++;
		}
	}

	it_s2 = (*it_c)->studentList_c.begin();
	it_c2 = (*it_s)->courseList_s.begin();

	while (it_s2 < (*it_c)->studentList_c.end())
	{
		if (name == (*it_s2)->GetName() && id == (*it_s2)->GetId())
		{
			break;
		}
		else
		{
			it_s2++;
		}
	}
	while (it_c2 < (*it_s)->courseList_s.end())
	{
		if (name_c == (*it_c2)->GetName() && id_c == (*it_c2)->GetId())
		{
			break;
		}
		else
		{
			it_s2++;
		}
	}


	(*it_s)->courseList_s.erase(it_c2);
	(*it_c)->studentList_c.erase(it_s2);



	registclass_id.pop_back();
	registclass_id_c.pop_back();
	registclass_name.pop_back();
	registclass_name_c.pop_back();
}

void RegistClass::redo()
{
	int x = registclass_id2.size();

	name = registclass_name2.at(x - 1);
	name_c = registclass_name_c2.at(x - 1);
	id = registclass_id2.at(x - 1);
	id_c = registclass_id_c2.at(x - 1);

	/////////

	it_s = studentList.begin();
	it_c = courseList.begin();

	Course *cr = new Course(name_c, id_c, "prof", "prof");
	Student *st = new Student(name, id);

	while (it_s < studentList.end())
	{
		if (name == (*it_s)->GetName() && id == (*it_s)->GetId())
		{
			break;
		}
		else
		{
			it_s++;
		}
	}
	while (it_c < courseList.end())
	{
		if (name_c == (*it_c)->GetName() && id_c == (*it_c)->GetId())
		{
			break;
		}
		else
		{
			it_c++;
		}
	}

	(*it_s)->courseList_s.push_back(cr);
	(*it_c)->studentList_c.push_back(st);

	registclass_id2.pop_back();
	registclass_id_c2.pop_back();
	registclass_name2.pop_back();
	registclass_name_c2.pop_back();

}
