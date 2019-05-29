#pragma once
#ifndef _CoursePrint_H
#define _CoursePrint_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class CoursePrint : public ICommand
{
private:
public:
	CoursePrint();
	void execute();
};

#endif