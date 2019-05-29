#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "ProfessorCreation.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"


using namespace std;

ProfessorCreation::ProfessorCreation() : ICommand()
{
	setCommandName("교수 등록");
}

void ProfessorCreation::execute()
{


	studentList_i.push_back(studentList);
	courseList_i.push_back(courseList);
	professorList_i.push_back(professorList);

	////////////////


	int num;
	int count = 0;

	cout << "등록하려는 교수의 수 : ";
	scanf("%d", &num);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	for (int i = 0; i < num; i++)
	{
		char name[100];
		char id[100];
		cout << "교수 이름 :";

		if (cin.peek() != '\n')
			cin >> std::setw(12) >> name;
		else if (cin.peek() == '\n')
		{
			cout << "##모든 입력이 취소되었습니다." << endl << endl;
			for (int i = 0; i < count; i++)
			{
				professorList.pop_back();
			}
			break;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << endl;
	Labels:

		cout << "교수 번호 :";
		if (cin.peek() != '\n')
			cin >> setw(12) >> id;
		else if (cin.peek() == '\n')
		{
			cout << "##모든 입력이 취소되었습니다1." << endl << endl;
			for (int i = 0; i < count; i++)
			{
				professorList.pop_back();
			}
			break;
		}
		cout << endl;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int x;
		sscanf(id, "%d", &x);
		if (x < 1000 || x>9999)
		{
			cout << "##교수번호는 4자리 양의정수여야합니다." << endl;
			goto Labels;
		}
		it_p = professorList.begin();
		while (it_p < professorList.end())
		{
			if ((*it_p)->GetId() == id)
			{
				cout << "##중복된 교수번호 입니다.\n" << endl;
				goto Labels;
			}
			else
			{
				it_p++;
			}
		}

		Professor *st = new Professor(name, id);
		professorList.push_back(st);
		cout << "교수 이름 : " << name << ",  교수 번호 : " << id << " *등록되었음*" << endl << endl;
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

void ProfessorCreation::undo()
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

void ProfessorCreation::redo()
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
