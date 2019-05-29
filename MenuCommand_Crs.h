#pragma once
#ifndef _MenuCommand_Crs_H
#define _MenuCommand_Crs_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class MenuCommand_Crs : public ICommand
{
private:
	std::string select;
	std::vector<ICommand *> menuCommandList;
	std::vector<ICommand *>::iterator it;
public:
	MenuCommand_Crs();
	void addMenu(ICommand *command);
	void execute();
};

#endif