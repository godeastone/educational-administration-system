#pragma once
#ifndef _About_regist_H
#define _About_regist_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class About_regist : public ICommand
{
private:
	std::string select;
	std::vector<ICommand *> menuCommandList;
	std::vector<ICommand *>::iterator it;
public:
	About_regist();
	void addMenu(ICommand *command);
	void execute();
};

#endif