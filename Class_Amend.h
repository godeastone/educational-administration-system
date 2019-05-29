#pragma once
#ifndef _Class_Amend_H
#define _Class_Amend_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class Class_Amend : public ICommand
{
private:
	int select;
	std::vector<ICommand *> menuCommandList;
	std::vector<ICommand *>::iterator it;
public:
	Class_Amend();
	void addMenu(ICommand *command);
	void execute();
	void undo();
	void redo();

};

#endif