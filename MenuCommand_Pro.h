#pragma once
#ifndef _MenuCommand_Pro_H
#define _MenuCommand_Pro_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class MenuCommand_Pro : public ICommand
{
private:
	std::string select;
	std::vector<ICommand *> menuCommandList;
	std::vector<ICommand *>::iterator it;
public:
	MenuCommand_Pro();
	void addMenu(ICommand *command);
	void execute();
};

#endif