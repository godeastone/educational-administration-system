#pragma once
#ifndef _PrintPerson_H
#define _PrintPerson_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class PrintPerson : public ICommand
{
private:
public:
	std::string name1;
	PrintPerson();
	void execute();
};

#endif