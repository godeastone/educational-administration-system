#pragma once
#ifndef _About_haksa_H
#define _About_haksa_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class About_haksa : public ICommand
{
private:
	std::string select;
	std::vector<ICommand *> menuCommandList;
	std::vector<ICommand *>::iterator it;
public:
	About_haksa();
	void addMenu(ICommand *command);
	void execute();
};

#endif