#pragma once
#ifndef _CancelClass_H
#define _CancelClass_H

#include <string>
#include <vector>
#include "ICommand.h"


class ICommand;
class Student;
class Course;
class Professor;

class CancelClass : public ICommand
{
private:
	std::vector<Student *> studentList_cancelclass;
	std::vector<Course *> courseList_cancelclass;
	std::vector<Professor *> professorList_cancelclass;

protected:
	std::string name, course, id, name_c, id_c, prof_id, prof_name;
	int sel;
	int num = 1;
	int control = 0;
	int control1 = 0;

public:


	CancelClass();
	void execute();
	void undo();
	void redo();
};

#endif