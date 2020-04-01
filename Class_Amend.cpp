#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Class_Amend.h"
#include "ICommand.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "Variables.h"

using namespace std;


Class_Amend::Class_Amend() :ICommand()
{
	setCommandName("Amend class");
}
void Class_Amend::addMenu(ICommand *command)
{
	menuCommandList.push_back(command);
}
void Class_Amend::execute()
{
	string name, course, id, name_c, id_c, name_c2, id_c2;
	string name_o;
	int sel;
	int num = 1;
	int control = 0;
	int control1 = 0;
	int control2 = 0;

	////////////////



	while (1)
	{
		cout << "Student name : ";
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
			cout << "##Information do not match.##" << endl << endl;
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
			cout << "*** " + name + " List of the classes ***" << endl;
			it_c = (*it_s)->courseList_s.begin();

			if ((*it_s)->courseList_s.empty())
			{
				cout << "##No class##." << endl;
				control = 999;
				goto LA;
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
		cout << "\n**Enter the number of class you want to amend : ";
		cin >> sel;
		it_c = (*it_s)->courseList_s.begin();
		it_c += (sel - 1);
		name_c = (*it_c)->GetName();
		id_c = (*it_c)->GetId();

		(*it_s)->courseList_s.erase(it_c);

		it_c = courseList.begin();
		while (it_c < courseList.end())
		{
			if (name_c == (*it_c)->GetName() && id_c == (*it_c)->GetId())
			{
				it_s2 = (*it_c)->studentList_c.begin();
				while (it_s2 < (*it_c)->studentList_c.end())
				{
					if (name == (*it_s2)->GetName() && id == (*it_s2)->GetId())
					{
						(*it_c)->studentList_c.erase(it_s2);
						break;
					}
					else
					{
						it_s2++;
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
	name_o = (*it_c)->GetName();
	cout << endl;

	num = 1;

	cout << "***** classes you can register *****" << endl;

	it_c = courseList.begin();
	while (it_c < courseList.end())
	{
	Label4:

		if (name_c == (*it_c)->GetName() && id_c == (*it_c)->GetId())
		{
			it_c++;
			num++;
			continue;
		}
		else
		{
			///////////////////////////

			it_c2 = (*it_s)->courseList_s.begin();
			while (it_c2 < (*it_s)->courseList_s.end())
			{
				if ((*it_c2)->GetName() == (*it_c)->GetName() && (*it_c2)->GetId() == (*it_c)->GetId())
				{
					if (it_c != courseList.end() - 1)
					{
						it_c++;
						num++;
						goto Label4;
					}
					else if (it_c == courseList.end() - 1)
					{
						goto Label5;
					}

				}
				else
				{
					it_c2++;
				}
			}

			///////////////////////////
			cout << num << ". " << (*it_c)->GetId() << "   " << (*it_c)->GetName() << endl;
			num++;
			it_c++;
		}
	}
Label5:

	cout << "*********************************" << endl;

	it_c = courseList.begin();

	cout << "\n**Enter the class number you want to register : ";
	cin >> sel;

	it_c += sel - 1;

LA:
	if (control != 999)
	{
		Student *st = new Student(name, id);
		(*it_c)->studentList_c.push_back(st);


		name_c2 = (*it_c)->GetName();
		id_c2 = (*it_c)->GetId();

		it_s = studentList.begin();
		while (it_s < studentList.end())
		{
			if (name == (*it_s)->GetName() && id == (*it_s)->GetId())
			{
				Course *cr = new Course(name_c2, id_c2, "prof", "prof");
				(*it_s)->courseList_s.push_back(cr);

				cout << "$$" << name_o << "class " << name_c2 << " amends complete$$";
				break;
			}
			else
			{
				it_s++;
			}
		}
	}
	cout << endl << endl;

	classamend_id.push_back(id);
	classamend_id_c.push_back(id_c);
	classamend_name.push_back(name);
	classamend_name_c.push_back(name_c);
	classamend_id_c2.push_back(id_c2);
	classamend_name_c2.push_back(name_c2);


	/////


	while (!historyList2.empty())
	{
		historyList2.pop();
	}
	////
}


void Class_Amend::undo()
{
	int x = classamend_id.size();
	string name, name_c, name_c2, id, id_c, id_c2;

	name = classamend_name.at(x - 1);
	name_c = classamend_name_c.at(x - 1);
	id = classamend_id.at(x - 1);
	id_c = classamend_id_c.at(x - 1);
	id_c2 = classamend_id_c2.at(x - 1);
	name_c2 = classamend_name_c2.at(x - 1);


	classamend_id3.push_back(id);
	classamend_id_c3.push_back(id_c);
	classamend_name3.push_back(name);
	classamend_name_c3.push_back(name_c);
	classamend_id_c4.push_back(id_c2);
	classamend_name_c4.push_back(name_c2);



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
	cout << "clag1" << endl;
	while (it_c < courseList.end())
	{
		if (name_c2 == (*it_c)->GetName() && id_c2 == (*it_c)->GetId())
		{
			break;
		}
		else
		{
			it_c++;
		}
	}
	it_c2 = (*it_s)->courseList_s.begin();
	it_s2 = (*it_c)->studentList_c.begin();
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
	////여기밑에가 문제
	while (it_c2 < (*it_s)->courseList_s.end())
	{
		if (name_c2 == (*it_c2)->GetName() && id_c2 == (*it_c2)->GetId())
		{
			break;
		}
		else
		{
			it_c2++;
		}
	}


	(*it_s)->courseList_s.erase(it_c2);
	(*it_c)->studentList_c.erase(it_s2);

	//////////////////////////////
	it_s = studentList.begin();
	it_c = courseList.begin();

	Student *st = new Student(name, id);
	Course *cr = new Course(name_c, id_c, "pr", "pr");

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

	classamend_id.pop_back();
	classamend_id_c.pop_back();
	classamend_name.pop_back();
	classamend_name_c.pop_back();
	classamend_name_c2.pop_back();
	classamend_id_c2.pop_back();
}



void Class_Amend::redo()
{
	int x = classamend_id3.size();
	string name, name_c, name_c2, id, id_c, id_c2;

	name = classamend_name3.at(x - 1);
	name_c2 = classamend_name_c4.at(x - 1);
	id = classamend_id3.at(x - 1);
	id_c2 = classamend_id_c4.at(x - 1);
	id_c = classamend_id_c3.at(x - 1);
	name_c = classamend_name_c3.at(x - 1);




	//////////////////////////////
	it_s = studentList.begin();
	it_c = courseList.begin();

	Course *cr = new Course(name_c2, id_c2, "prof", "prof");
	Student *st = new Student(name, id);

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

	it_c2 = (*it_s)->courseList_s.begin();
	it_s2 = (*it_c)->studentList_c.begin();

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

	///////////////////////

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
		if (name_c2 == (*it_c)->GetName() && id_c2 == (*it_c)->GetId())
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


	classamend_id3.pop_back();
	classamend_id_c3.pop_back();
	classamend_name3.pop_back();
	classamend_name_c3.pop_back();
	classamend_name_c4.pop_back();
	classamend_id_c4.pop_back();
}
