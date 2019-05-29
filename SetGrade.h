#pragma once
#ifndef _SetGrade_H
#define _SetGrade_H

#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Course;
class Student;


class SetGrade : public ICommand
{
private:
public:
	SetGrade();
	void execute();
	void undo();
	void redo();
};

#endif