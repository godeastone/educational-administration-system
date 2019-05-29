#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "SetGrade.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "ICommand.h"
#include "Variables.h"


using namespace std;

SetGrade::SetGrade() : ICommand()
{
	setCommandName("성적 입력");
}
void SetGrade::execute()
{


	////////////////

	string prof_name, prof_id, course_id, grade, name_t, id_t, name_c, id_c;
	int control1 = 0;
	int control2 = 0;
	int control3 = 0;
	int control4 = 0;
	int n = 0;

	while (1)
	{
		cout << "교수 이름 : ";
		cin >> prof_name;
		cout << "\n교수 번호 : ";
		cin >> prof_id;

		it_p = professorList.begin();
		while (it_p < professorList.end())
		{
			if (prof_name == (*it_p)->GetName() && prof_id == (*it_p)->GetId())
			{
				control1 = 1;
				break;
			}
			else
			{
				it_p++;
			}
		}

		if (control1 == 0)
		{
			it_p--;
		}

		cout << "**" << prof_name << " 교수님 개설과목" << endl;
		cout << " <과목 이름>        <과목 코드>" << endl;

		it_c = (*it_p)->courseList_p.begin();

		if (it_c == (*it_p)->courseList_p.end() && control1 == 1)
		{
			cout << "##개설 과목이 없습니다." << endl << endl;
			control3 = 1;
			break;
		}

		while (it_c < (*it_p)->courseList_p.end())
		{
			cout << "     " << (*it_c)->GetName() << "          " << (*it_c)->GetId() << endl;
			it_c++;
		}

		cout << endl << endl;
		if (control1 == 1)
		{
			break;
		}
		else
		{
			cout << "##잘못된 교수정보입니다. 다시 입력하세요." << endl << endl;
		}
	}


	while (control3 == 0)
	{
		cout << "과목 코드 : ";
		cin >> course_id;

		cout << "\n**** " << course_id << " 과목 수강학생 ****" << endl;
		cout << " <이름>        <학번>" << endl;
		it_c = courseList.begin();
		while (it_c < courseList.end())
		{
			if (course_id == (*it_c)->GetId())
			{
				name_c = (*it_c)->GetName();
				id_c = (*it_c)->GetId();

				it_s = (*it_c)->studentList_c.begin();
				while (it_s < (*it_c)->studentList_c.end())
				{
					++n;
					cout << n << ". " << (*it_s)->GetName() << "         " << (*it_s)->GetId() << endl;
					it_s++;
				}
				control2 = 1;
				break;
			}
			else
			{
				it_c++;
			}
		}
		if (control2 == 1)
		{
			cout << endl << endl;
			break;
		}
		cout << "##잘못된 과목 코드 입력입니다. 다시 입력하세요" << endl << endl;
	}


	cout << "**순서대로 성적을 입력하세요**" << endl << endl;
	int n2 = 1;



	it_c = courseList.begin();

	while (it_c < courseList.end())
	{
		if (course_id == (*it_c)->GetId())
		{
			it_s = (*it_c)->studentList_c.begin();
			while (it_s < (*it_c)->studentList_c.end())
			{
				name_t = (*it_s)->GetName();
				id_t = (*it_s)->GetId();

				it_s2 = studentList.begin();
				while (it_s2 < studentList.end())
				{
					if (name_t == (*it_s2)->GetName() && id_t == (*it_s2)->GetId())
					{
						it_c2 = (*it_s2)->courseList_s.begin();
						while (it_c2 < (*it_s2)->courseList_s.end())
						{
							if (course_id == (*it_c2)->GetId())
							{
								cout << n2 << "번 학생 점수 : ";
								cin >> grade;
								if ((grade != "A") && (grade != "B") && (grade != "C") && (grade != "D") && (grade != "F"))
								{
									cout << "입력 가능한 성적이 아닙니다." << endl << endl;
									continue;
								}
								n--;
								n2++;
								(*it_c2)->grade = grade;
								control1 = 2;
								it_s++;
								break;
							}
							else
							{
								it_c2++;
							}
						}
						if (control1 == 2)
						{
							break;
						}
					}
					else
					{
						it_s2++;
					}
				}

			}
			break;
		}
		else
		{
			it_c++;
		}
	}

	setgrade_id.push_back(prof_id);
	setgrade_id_c.push_back(id_c);
	setgrade_name.push_back(prof_name);
	setgrade_name_c.push_back(name_c);



	/////


	while (!historyList2.empty())
	{
		historyList2.pop();
	}
	////

}

void SetGrade::undo()
{
	string name_c, id_c, prof_name, prof_id, name_t, id_t;
	int control1 = 1;
	int x = setgrade_id.size();

	prof_name = setgrade_name.at(x - 1);
	name_c = setgrade_name_c.at(x - 1);
	prof_id = setgrade_id.at(x - 1);
	id_c = setgrade_id_c.at(x - 1);

	setgrade_id2.push_back(prof_id);
	setgrade_id_c2.push_back(id_c);
	setgrade_name2.push_back(prof_name);
	setgrade_name_c2.push_back(name_c);

	it_s = studentList.begin();
	it_c = courseList.begin();
	it_p = professorList.begin();

	while (it_c < courseList.end())
	{
		if (id_c == (*it_c)->GetId())
		{
			it_s = (*it_c)->studentList_c.begin();
			while (it_s < (*it_c)->studentList_c.end())
			{
				name_t = (*it_s)->GetName();
				id_t = (*it_s)->GetId();

				it_s2 = studentList.begin();
				while (it_s2 < studentList.end())
				{
					if (name_t == (*it_s2)->GetName() && id_t == (*it_s2)->GetId())
					{
						it_c2 = (*it_s2)->courseList_s.begin();
						while (it_c2 < (*it_s2)->courseList_s.end())
						{
							if (id_c == (*it_c2)->GetId())
							{
								gradeList.push_back((*it_c2)->grade);
								(*it_c2)->grade = '\0';
								control1 = 2;
								it_s++;
								break;
							}
							else
							{
								it_c2++;
							}
						}
						if (control1 == 2)
						{
							break;
						}
					}
					else
					{
						it_s2++;
					}
				}

			}
			break;
		}
		else
		{
			it_c++;
		}
	}

	setgrade_id.pop_back();
	setgrade_id_c.pop_back();
	setgrade_name.pop_back();
	setgrade_name_c.pop_back();

}

void SetGrade::redo()
{
	string name_c, id_c, prof_name, prof_id, name_t, id_t;
	int control1 = 1;
	int x = setgrade_id2.size();

	prof_name = setgrade_name2.at(x - 1);
	name_c = setgrade_name_c2.at(x - 1);
	prof_id = setgrade_id2.at(x - 1);
	id_c = setgrade_id_c2.at(x - 1);


	///////////////////////////////


	it_c = courseList.begin();

	while (it_c < courseList.end())
	{
		if (id_c == (*it_c)->GetId())
		{
			it_s = (*it_c)->studentList_c.begin();
			while (it_s < (*it_c)->studentList_c.end())
			{
				name_t = (*it_s)->GetName();
				id_t = (*it_s)->GetId();

				it_s2 = studentList.begin();
				while (it_s2 < studentList.end())
				{
					if (name_t == (*it_s2)->GetName() && id_t == (*it_s2)->GetId())
					{
						it_c2 = (*it_s2)->courseList_s.begin();
						while (it_c2 < (*it_s2)->courseList_s.end())
						{
							if (id_c == (*it_c2)->GetId())
							{
								(*it_c2)->grade = gradeList.at(0);
								it_g = gradeList.begin();
								gradeList.erase(it_g);
								control1 = 2;
								it_s++;
								break;
							}
							else
							{
								it_c2++;
							}
						}
						if (control1 == 2)
						{
							break;
						}
					}
					else
					{
						it_s2++;
					}
				}

			}
			break;
		}
		else
		{
			it_c++;
		}
	}


	setgrade_id2.pop_back();
	setgrade_id_c2.pop_back();
	setgrade_name2.pop_back();
	setgrade_name_c2.pop_back();

}