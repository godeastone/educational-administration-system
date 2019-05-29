#pragma once
#ifndef _Professor_H
#define _Professor_H
#include <string>
#include <iostream>	
#include <vector>

#include "Course.h"
#include "Student.h"

class Course;
class Professor
{
private:
	std::string name, id;
public:
	Professor(std::string name, std::string id)
	{
		this->name = name;
		this->id = id;
	}
	std::string GetName() { return name; }
	std::string GetId() { return id; }
	std::vector<Course *> courseList_p;
};
#endif;