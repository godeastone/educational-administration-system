#pragma once
#ifndef _CourseCreation_H
#define _CourseCreation_H
#include <string>
#include <vector>
#include "ICommand.h"


class Professor;
class Course;
class ICommand;


class CourseCreation : public ICommand
{
private:
public:
	CourseCreation();
	void execute();
	void undo();
	void redo();
};

#endif