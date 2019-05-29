#pragma once
#ifndef _ProfessorCreation_H
#define _ProfessorCreation_H

#include <string>
#include <vector>
#include "ICommand.h"

class ICommand;

class Course;
class Student;


class ProfessorCreation : public ICommand
{
private:
public:
	ProfessorCreation();
	void execute();
	void undo();
	void redo();
};

#endif