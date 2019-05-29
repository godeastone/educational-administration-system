#pragma once

#ifndef _About_apply_H
#define _About_apply_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class About_apply : public ICommand
{
private:
	std::string select;
	std::vector<ICommand *> menuCommandList;
	std::vector<ICommand *>::iterator it;
public:
	About_apply();
	void addMenu(ICommand *command);
	void execute();
};

#endif