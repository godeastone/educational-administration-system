#pragma once
#ifndef _Course_H
#define _Course_H
#include <string>
#include <iostream>	
#include <vector>
#include "Student.h"
#include "Professor.h"

class Student;
class Professor;
class Course
{
private:
	std::string name, id, prof_id, prof_name;

public:
	Course(std::string name, std::string id, std::string prof_id, std::string prof_name)
	{
		this->name = name;
		this->id = id;
		this->prof_id = prof_id;
		this->prof_name = prof_name;

	}
	std::string GetName() { return name; }
	std::string GetId() { return id; }
	std::string GetProf_Id() { return prof_id; }
	std::string GetProf_Name() { return prof_name; }
	std::vector<Student *> studentList_c;
	std::string grade;
	std::string GetGrade() { return grade; }
	void SetId(std::string _id) { id = _id; }
};

#endif;