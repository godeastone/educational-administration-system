#pragma once
#ifndef _StudentDelete_H
#define _StudentDelete_H
#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Professor;
class Course;

class StudentDelete : public ICommand
{
private:
public:
	StudentDelete();
	void execute();
	void undo();
	void redo();
};

#endif