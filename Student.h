#pragma once
#ifndef _Student_H
#define _Student_H
#include <string>
#include <iostream>	
#include <vector>
#include "Course.h"
#include "Professor.h"

class Professor;
class Course;
class Student
{
private:
	std::string name, id;
public:
	Student(std::string name, std::string id)
	{
		this->name = name;
		this->id = id;
	};
	std::string GetName() { return name; }
	std::string GetId() { return id; }
	std::vector<Course *> courseList_s;
	//vector<Grade *> gradeList;
};

#endif;