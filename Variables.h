#pragma once

#ifndef _Variables_H
#define _Variables_H
#include <iostream>
#include <string>
#include <vector>
#include <stack>


class Student;
class Professor;
class Course;
class ICommand;


extern std::vector<Student *> studentList;
extern std::vector<Student *> studentList2;
extern std::vector<Student *>::iterator it_s;
extern std::vector<Student *>::iterator it_s2;
extern std::vector<Professor *> professorList;
extern std::vector<Professor *>::iterator it_p;
extern std::vector<Course *> courseList;
extern std::vector<Course *> courseList2;
extern std::vector<Course *>::iterator it_c;
extern std::vector<Course *>::iterator it_c2;
extern std::vector<Course *>::iterator it_c3;

extern std::stack<ICommand *> historyList;
extern std::stack<ICommand *> historyList_;
extern std::stack<ICommand *> historyList2;
extern std::stack<ICommand *> historyList2_;

extern std::vector<std::vector<Student *>> studentList_i;
extern std::vector<std::vector<Student *>>::iterator it_s_i;

extern std::vector<std::vector<Student *>> studentList_i2;
extern std::vector<std::vector<Student *>>::iterator it_s_i2;

extern std::vector<std::vector<Course *>> courseList_i;
extern std::vector<std::vector<Course *>>::iterator it_c_i;

extern std::vector<std::vector<Course *>> courseList_i2;
extern std::vector<std::vector<Course *>>::iterator it_c_i2;

extern std::vector<std::vector<Professor *>> professorList_i;
extern std::vector<std::vector<Professor *>>::iterator it_p_i;

extern std::vector<std::vector<Professor *>> professorList_i2;
extern std::vector<std::vector<Professor *>>::iterator it_p_i2;


extern std::vector<std::string> registclass_name;
extern std::vector<std::string> registclass_id;
extern std::vector<std::string> registclass_name_c;
extern std::vector<std::string> registclass_id_c;
extern std::vector<std::string> registclass_name2;
extern std::vector<std::string> registclass_id2;
extern std::vector<std::string> registclass_name_c2;
extern std::vector<std::string> registclass_id_c2;

extern std::vector<std::string> cancelclass_name;
extern std::vector<std::string> cancelclass_id;
extern std::vector<std::string> cancelclass_name_c;
extern std::vector<std::string> cancelclass_id_c;
extern std::vector<std::string> cancelclass_name2;
extern std::vector<std::string> cancelclass_id2;
extern std::vector<std::string> cancelclass_name_c2;
extern std::vector<std::string> cancelclass_id_c2;

extern std::vector<std::string> classamend_name;
extern std::vector<std::string> classamend_id;
extern std::vector<std::string> classamend_name_c;
extern std::vector<std::string> classamend_id_c;
extern std::vector<std::string> classamend_name_c2;
extern std::vector<std::string> classamend_id_c2;
extern std::vector<std::string> classamend_name3;
extern std::vector<std::string> classamend_id3;
extern std::vector<std::string> classamend_name_c3;
extern std::vector<std::string> classamend_id_c3;
extern std::vector<std::string> classamend_name_c4;
extern std::vector<std::string> classamend_id_c4;

extern std::vector<std::string> setgrade_name;
extern std::vector<std::string> setgrade_id;
extern std::vector<std::string> setgrade_name_c;
extern std::vector<std::string> setgrade_id_c;
extern std::vector<std::string> setgrade_name2;
extern std::vector<std::string> setgrade_id2;
extern std::vector<std::string> setgrade_name_c2;
extern std::vector<std::string> setgrade_id_c2;
extern std::vector<std::string> gradeList;
extern std::vector<std::string>::iterator it_g;

extern std::vector<std::string> coursecreation_name;
extern std::vector<std::string> coursecreation_id;
extern std::vector<std::string> coursecreation_name_c;
extern std::vector<std::string> coursecreation_id_c;
extern std::vector<std::string> coursecreation_name2;
extern std::vector<std::string> coursecreation_id2;
extern std::vector<std::string> coursecreation_name_c2;
extern std::vector<std::string> coursecreation_id_c2;

extern std::vector<std::string> coursecancel_name;
extern std::vector<std::string> coursecancel_id;
extern std::vector<std::string> coursecancel_name_c;
extern std::vector<std::string> coursecancel_id_c;
extern std::vector<std::string> coursecancel_name2;
extern std::vector<std::string> coursecancel_id2;
extern std::vector<std::string> coursecancel_name_c2;
extern std::vector<std::string> coursecancel_id_c2;

#endif