#pragma once
#ifndef _About_delete_H
#define _About_delete_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class About_delete : public ICommand
{
private:
	std::string select;
	std::vector<ICommand *> menuCommandList;
	std::vector<ICommand *>::iterator it;
public:
	About_delete();
	void addMenu(ICommand *command);
	void execute();
};

#endif