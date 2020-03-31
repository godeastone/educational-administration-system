#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "StudentCreation.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"

using namespace std;

StudentCreation::StudentCreation() : ICommand()
{
	setCommandName("Student register");
}

void StudentCreation::execute()
{


	studentList_i.push_back(studentList);
	courseList_i.push_back(courseList);
	professorList_i.push_back(professorList);



	//////////////////////



	int num;
	int count = 0;

	cout << "number of students you want to register : ";
	scanf("%d", &num);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	for (int i = 0; i < num; i++)
	{
	Labels2:
		char name[100];
		char id[100];
		cout << "student name :";

		if (cin.peek() != '\n')
			cin >> std::setw(12) >> name;
		else if (cin.peek() == '\n')
		{
			cout << "##All inputs were canceled." << endl << endl;
			for (int i = 0; i < count; i++)
			{
				studentList.pop_back();
			}
			break;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << endl;

		cout << "student number :";
		if (cin.peek() != '\n')
			cin >> setw(12) >> id;
		else if (cin.peek() == '\n')
		{
			cout << "##all inputs were canceled." << endl << endl;
			for (int i = 0; i < count; i++)
			{
				studentList.pop_back();
			}
			break;
		}
		cout << endl;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int x;
		sscanf(id, "%d", &x);
		if (x < 99999999 || x>999999999)
		{
			cout << "##students number should be 9-number." << endl;
			goto Labels2;
		}

		it_s = studentList.begin();
		while (it_s < studentList.end())
		{
			if ((*it_s)->GetId() == id)
			{
				cout << "##duplicated student number.\n" << endl;
				goto Labels2;
			}
			else
			{
				it_s++;
			}
		}

		Student *st = new Student(name, id);
		studentList.push_back(st);
		cout << "student name : " << name << ",  student number : " << id << " *regist complete*" << endl << endl;
		count++;
	}

	studentList_i2.push_back(studentList);
	courseList_i2.push_back(courseList);
	professorList_i2.push_back(professorList);

	/////


	while (!historyList2.empty())
	{
		historyList2.pop();
	}
	////
}

void StudentCreation::undo()
{
	studentList.clear();
	courseList.clear();
	professorList.clear();


	int x = studentList_i.size();
	studentList = studentList_i.at(x - 1);
	courseList = courseList_i.at(x - 1);
	professorList = professorList_i.at(x - 1);

	studentList_i.pop_back();
	courseList_i.pop_back();
	professorList_i.pop_back();
}

void StudentCreation::redo()
{
	studentList.clear();
	courseList.clear();
	professorList.clear();

	it_s_i = studentList_i2.begin();
	it_c_i = courseList_i2.begin();
	it_p_i = professorList_i2.begin();

	int x = studentList_i2.size();
	studentList = studentList_i2.at(0);
	courseList = courseList_i2.at(0);
	professorList = professorList_i2.at(0);

	studentList_i2.erase(it_s_i);
	courseList_i2.erase(it_c_i);
	professorList_i2.erase(it_p_i);
}
