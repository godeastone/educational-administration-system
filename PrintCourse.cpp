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
	setCommandName("전체 과목 정보 출력");
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
		//course 와 professor 의 메소드를 이용하여 정보를 할당함
		it_s = (*it_c)->studentList_c.begin();
		num = (*it_c)->studentList_c.size();

		cout << "**" << name << " 과목(" << id << ") 학생정보** - 담당교수 : " << prof << "(" << profid << ")" << "\n***학생 수 : " << num << endl;
		cout << "-----<이름>------------<학번>----------" << endl;
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
			cout << "개설된 과목이 없습니다." << endl << endl;
			break;
		}
		it_c++;
		cout << endl << endl;
	}
	cout << endl;
}
