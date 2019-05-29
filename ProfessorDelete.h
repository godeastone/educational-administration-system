#pragma once
#ifndef _ProfessorDelete_H
#define _ProfessorDelete_H

#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Course;
class Student;


class ProfessorDelete : public ICommand
{
private:
public:
	ProfessorDelete();
	void execute();
	void undo();
	void redo();
};

#endif