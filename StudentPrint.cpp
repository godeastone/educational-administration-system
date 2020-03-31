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
	setCommandName("Show student information");
}
void StudentPrint::execute()
{
	string id1;
	int control = 0;

	while (1)
	{
		cout << "student number you want to search :";
		cin >> id1;
		it_s = studentList.begin();
		while (it_s < studentList.end())
		{
			if (id1 == (*it_s)->GetId())
			{
				cout << "\n**student name :" << (*it_s)->GetName() << endl << endl;
				cout << "**" << (*it_s)->GetName() << "'s subject list**" << endl;
				cout << "<subject>     <grade>" << endl;

				it_c = (*it_s)->courseList_s.begin();
				string str;
				if ((*it_s)->courseList_s.end() == (*it_s)->courseList_s.begin())
				{
					cout << "No subjects." << endl << endl;
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
						str += "No grades.";
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
			cout << "Information not matched. try again" << endl << endl;
			continue;
		}
		else
		{
			break;
		}
	}
}
