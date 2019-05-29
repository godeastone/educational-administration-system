
#pragma once
#ifndef _About_course_H
#define _About_course_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class About_course : public ICommand
{
private:
	std::string select;
	std::vector<ICommand *> menuCommandList;
	std::vector<ICommand *>::iterator it;
public:
	About_course();
	void addMenu(ICommand *command);
	void execute();
};

#endif