#pragma once
#ifndef _StudentCreation_H
#define _StudentCreation_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class StudentCreation : public ICommand
{
private:
public:
	StudentCreation();
	void execute();
	void undo();
	void redo();
};

#endif