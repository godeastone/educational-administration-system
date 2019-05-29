#pragma once
#ifndef _RegistClass_H
#define _RegistClass_H

#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Course;
class Student;
class Professor;

class RegistClass : public ICommand
{
private:

protected:
	std::string name, id, name_c, id_c;
	int num = 1;
	int control = 0;
	int sel;

public:

	RegistClass();
	void execute();
	void undo();
	void redo();


};

#endif