#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "CancelClass.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "Variables.h"
#include "ICommand.h"


class Student;
class Professor;
class Course;

using namespace std;



CancelClass::CancelClass() :ICommand()
{
	setCommandName("Cancel class");
}

void CancelClass::execute()
{
	while (1)
	{
		cout << "Student name : ";
		cin >> name;
		cout << endl;
		cout << "Student number : ";
		cin >> id;
		cout << endl;

		it_s = studentList.begin();
		while (it_s < studentList.end())
		{
			if (name == (*it_s)->GetName() && id == (*it_s)->GetId())
			{
				control1 = 1;
				break;
			}
			else
			{
				it_s++;
			}
		}

		if (control1 == 0)
		{
			cout << "##Information do not match'.##" << endl << endl;
		}
		else
		{
			break;
		}
	}


	it_s = studentList.begin();
	while (it_s < studentList.end())
	{
		if (name == (*it_s)->GetName() && id == (*it_s)->GetId())
		{
			cout << "*** " + name + " 's List of classes ***" << endl;
			it_c = (*it_s)->courseList_s.begin();

			if ((*it_s)->courseList_s.empty())
			{
				cout << "##No class##." << endl;
				control = 1;
				break;
			}

			while (it_c < (*it_s)->courseList_s.end())
			{
				cout << num << ". " << (*it_c)->GetId() << "   " << (*it_c)->GetName() << endl;
				it_c++;
				num++;
			}
			cout << "**************************************" << endl;
			break;
		}
		else
		{
			it_s++;
		}
	}

	if (control == 0)
	{
	Label2:

		cout << "\n**Enter the number of class you want to cancel : ";
		cin >> sel;

		if (sel > num - 1)
		{
			cout << "Can't do that'." << endl << endl;
			goto Label2;
		}


		it_c = (*it_s)->courseList_s.begin();
		it_c += sel - 1;
		name_c = (*it_c)->GetName();
		id_c = (*it_c)->GetId();
		(*it_s)->courseList_s.erase(it_c);

		it_c = courseList.begin();
		while (it_c < courseList.end())
		{
			if (name_c == (*it_c)->GetName() && id_c == (*it_c)->GetId())
			{
				it_s = (*it_c)->studentList_c.begin();
				while (it_s < (*it_c)->studentList_c.end())
				{
					if (name == (*it_s)->GetName() && id == (*it_s)->GetId())
					{
						(*it_c)->studentList_c.erase(it_s);
						cout << "$$Cancel class complete$$." << endl;
						break;
					}
					else
					{
						it_s++;
					}
				}
				break;
			}
			else
			{
				it_c++;
			}
		}
	}
	cout << endl;





	cancelclass_id.push_back(id);
	cancelclass_id_c.push_back(id_c);
	cancelclass_name.push_back(name);
	cancelclass_name_c.push_back(name_c);


	while (!historyList2.empty())
	{
		historyList2.pop();
	}
	////

	num = 1;
	control = 0;
	control1 = 0;
}

void CancelClass::undo()
{
	int x = cancelclass_id.size();

	name = cancelclass_name.at(x - 1);
	name_c = cancelclass_name_c.at(x - 1);
	id = cancelclass_id.at(x - 1);
	id_c = cancelclass_id_c.at(x - 1);

	cancelclass_id2.push_back(id);
	cancelclass_id_c2.push_back(id_c);
	cancelclass_name2.push_back(name);
	cancelclass_name_c2.push_back(name_c);

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

	cancelclass_id.pop_back();
	cancelclass_id_c.pop_back();
	cancelclass_name.pop_back();
	cancelclass_name_c.pop_back();


}

void CancelClass::redo()
{
	int x = cancelclass_id2.size();

	name = cancelclass_name2.at(x - 1);
	name_c = cancelclass_name_c2.at(x - 1);
	id = cancelclass_id2.at(x - 1);
	id_c = cancelclass_id_c2.at(x - 1);

	////////

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

	cancelclass_id2.pop_back();
	cancelclass_id_c2.pop_back();
	cancelclass_name2.pop_back();
	cancelclass_name_c2.pop_back();
}
