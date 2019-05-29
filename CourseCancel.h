#pragma once
#ifndef _CourseCancel_H
#define _CourseCancel_H
#include <string>
#include <vector>
#include "ICommand.h"


class ICommand;
class Professor;
class Course;

class CourseCancel : public ICommand
{
private:
public:
	CourseCancel();
	void execute();
	void undo();
	void redo();
};

#endif