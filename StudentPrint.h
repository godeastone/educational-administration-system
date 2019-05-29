#pragma once
#ifndef _StudentPrint_H
#define _StudentPrint_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class StudentPrint : public ICommand
{
private:
public:
	StudentPrint();
	void execute();
};

#endif