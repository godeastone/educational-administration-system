#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "CancelClass.h"
#include "CourseCancel.h"
#include "CourseCreation.h"
#include "CoursePrint.h"
#include "Menu.h"
#include "MenuCommand_Crs.h"
#include "MenuCommand_Pro.h"
#include "MenuCommand_Stu.h"
#include "MenuCommand_Man.h"
#include "ProfessorCreation.h"
#include "RegistClass.h"
#include "SetGrade.h"
#include "StudentCreation.h"
#include "StudentPrint.h"
#include "ICommand.h"
#include "Student.h"
#include "Course.h"
#include "Professor.h"
#include "Variables.h"
#include "About_regist.h"
#include "Class_Amend.h"
#include "About_course.h"
#include "About_apply.h"
#include "About_haksa.h"
#include "About_delete.h"
#include "StudentDelete.h"
#include "ProfessorDelete.h"
#include "PrintPerson.h"
#include "PrintCourse.h"

using namespace std;

int main()
{
	Student *st1 = new Student("유수정", "201900001");
	Student *st2 = new Student("정애인", "201900002");
	Student *st3 = new Student("김종언", "201900003");
	Student *st4 = new Student("유수정", "201800001");
	studentList.push_back(st1);
	studentList.push_back(st2);
	studentList.push_back(st3);
	studentList.push_back(st4);

	Course *cr1 = new Course("OOP", "CS001-1", "1922", "박선주");
	Course *cr2 = new Course("OOP", "CS001-2", "1923", "이유민");
	Course *cr3 = new Course("AI", "CS002", "1923", "이유민");
	Course *cr4 = new Course("Compiler", "CS003", "1924", "조인우");
	courseList.push_back(cr1);
	courseList.push_back(cr2);
	courseList.push_back(cr3);
	courseList.push_back(cr4);


	Professor *pr1 = new Professor("박선주", "1922");
	Professor *pr2 = new Professor("이유민", "1923");
	Professor *pr3 = new Professor("조인우", "1924");
	Professor *pr4 = new Professor("박선주", "1925");
	professorList.push_back(pr1);
	professorList.push_back(pr2);
	professorList.push_back(pr3);
	professorList.push_back(pr4);

	it_p = professorList.begin();
	(*it_p)->courseList_p.push_back(cr1);
	it_p++;
	(*it_p)->courseList_p.push_back(cr2);
	(*it_p)->courseList_p.push_back(cr3);
	it_p++;
	(*it_p)->courseList_p.push_back(cr4);

	Menu *topMenu = new Menu("Educational-administration-system");
	ICommand *subMenu1 = new MenuCommand_Stu();
	ICommand *subMenu2 = new MenuCommand_Pro();
	ICommand *subMenu3 = new MenuCommand_Crs();
	ICommand *subMenu4 = new MenuCommand_Man();
	ICommand *subMenu5 = new About_regist();
	ICommand *subMenu6 = new About_course();
	ICommand *subMenu7 = new About_apply();
	ICommand *subMenu8 = new About_delete();
	ICommand *subMenu9 = new About_haksa();

	ICommand *command1 = new CourseCreation();
	ICommand *command2 = new StudentCreation();
	ICommand *command3 = new StudentPrint();
	ICommand *command4 = new CoursePrint();
	ICommand *command5 = new RegistClass();
	ICommand *command6 = new CancelClass();
	ICommand *command7 = new ProfessorCreation();
	ICommand *command8 = new SetGrade();

	ICommand *command10 = new CourseCancel();
	ICommand *command11 = new Class_Amend();
	ICommand *command12 = new StudentDelete();
	ICommand *command13 = new ProfessorDelete();
	ICommand *command14 = new PrintCourse();
	ICommand *command15 = new PrintPerson();

	topMenu->addMenu(subMenu1);
	topMenu->addMenu(subMenu2);
	topMenu->addMenu(subMenu4);


	subMenu1->addMenu(subMenu5);
	subMenu1->addMenu(command3);


	subMenu5->addMenu(command5);
	subMenu5->addMenu(command6);
	subMenu5->addMenu(command11);

	subMenu2->addMenu(subMenu6);
	subMenu2->addMenu(command8);

	subMenu6->addMenu(command1);
	subMenu6->addMenu(command10);
	subMenu6->addMenu(command4);

	subMenu4->addMenu(subMenu7);
	subMenu4->addMenu(subMenu8);
	subMenu4->addMenu(subMenu9);

	subMenu7->addMenu(command2);
	subMenu7->addMenu(command7);
	subMenu8->addMenu(command12);
	subMenu8->addMenu(command13);
	subMenu9->addMenu(command15);
	subMenu9->addMenu(command14);

	topMenu->execute();

	return 0;
}
