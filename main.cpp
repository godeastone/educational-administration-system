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
