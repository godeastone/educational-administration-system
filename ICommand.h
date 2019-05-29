#pragma once
#ifndef _ICommand_H
#define _ICommand_H
#include <string>
#include <vector>
#include "ICommand.h"

class Professor;
class Student;

class ICommand
{
private:
	std::string commandName;
public:


	void setCommandName(std::string s) { commandName = s; }
	std::string getCommandName() { return commandName; }
	virtual void addMenu(ICommand *command) { return; }
	virtual void execute() { return; };
	virtual void undo() { return; };
	virtual void redo() { return; };
};

#endif