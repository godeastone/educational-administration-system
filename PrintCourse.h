#pragma once
#ifndef _PrintCourse_H
#define _PrintCourse_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class PrintCourse : public ICommand
{
private:
public:
	std::string name1;
	PrintCourse();
	void execute();
};

#endif