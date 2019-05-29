#pragma once
#ifndef _MenuCommand_Stu_H
#define _MenuCommand_Stu_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class MenuCommand_Stu : public ICommand
{
private:
	std::string select;
	std::vector<ICommand *> menuCommandList;
	std::vector<ICommand *>::iterator it;
public:
	MenuCommand_Stu();
	void addMenu(ICommand *command);
	void execute();
};

#endif