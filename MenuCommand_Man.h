#pragma once
#ifndef _MenuCommand_Man_H
#define _MenuCommand_Man_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class MenuCommand_Man : public ICommand
{
private:
	std::string select;
	std::vector<ICommand *> menuCommandList;
	std::vector<ICommand *>::iterator it;
public:
	MenuCommand_Man();
	void addMenu(ICommand *command);
	void execute();
};

#endif