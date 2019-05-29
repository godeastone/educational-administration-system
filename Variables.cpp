#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Variables.h"
#include "stack"
#include "ICommand.h"

class Student;
class Course;
class Professor;

using namespace std;

std::vector<Student *> studentList;
std::vector<Student *> studentList2;
std::vector<Student *>::iterator it_s;
std::vector<Student *>::iterator it_s2;
std::vector<Student *>::iterator it_s_rc;
std::vector<Professor *> professorList;
std::vector<Professor *>::iterator it_p;
std::vector<Course *> courseList;
std::vector<Course *> courseList2;
std::vector<Course *>::iterator it_c;
std::vector<Course *>::iterator it_c3;
std::vector<Course *>::iterator it_c2;


std::stack<ICommand *> historyList;
std::stack<ICommand *> historyList_;
std::stack<ICommand *> historyList2;
std::stack<ICommand *> historyList2_;


std::vector<std::vector<Student *>> studentList_i;
std::vector<std::vector<Student *>>::iterator it_s_i;

std::vector<std::vector<Student *>> studentList_i2;
std::vector<std::vector<Student *>>::iterator it_s_i2;

std::vector<std::vector<Course *>> courseList_i;
std::vector<std::vector<Course *>>::iterator it_c_i;

std::vector<std::vector<Course *>> courseList_i2;
std::vector<std::vector<Course *>>::iterator it_c_i2;

std::vector<std::vector<Professor *>> professorList_i;
std::vector<std::vector<Professor *>>::iterator it_p_i;

std::vector<std::vector<Professor *>> professorList_i2;
std::vector<std::vector<Professor *>>::iterator it_p_i2;


std::vector<std::string> registclass_name;
std::vector<std::string> registclass_id;
std::vector<std::string> registclass_name_c;
std::vector<std::string> registclass_id_c;
std::vector<std::string> registclass_name2;
std::vector<std::string> registclass_id2;
std::vector<std::string> registclass_name_c2;
std::vector<std::string> registclass_id_c2;

std::vector<std::string> cancelclass_name;
std::vector<std::string> cancelclass_id;
std::vector<std::string> cancelclass_name_c;
std::vector<std::string> cancelclass_id_c;
std::vector<std::string> cancelclass_name2;
std::vector<std::string> cancelclass_id2;
std::vector<std::string> cancelclass_name_c2;
std::vector<std::string> cancelclass_id_c2;

std::vector<std::string> classamend_name;
std::vector<std::string> classamend_id;
std::vector<std::string> classamend_name_c;
std::vector<std::string> classamend_id_c;
std::vector<std::string> classamend_name_c2;
std::vector<std::string> classamend_id_c2;
std::vector<std::string> classamend_name3;
std::vector<std::string> classamend_id3;
std::vector<std::string> classamend_name_c3;
std::vector<std::string> classamend_id_c3;
std::vector<std::string> classamend_name_c4;
std::vector<std::string> classamend_id_c4;

std::vector<std::string> setgrade_name;
std::vector<std::string> setgrade_id;
std::vector<std::string> setgrade_name_c;
std::vector<std::string> setgrade_id_c;
std::vector<std::string> setgrade_name2;
std::vector<std::string> setgrade_id2;
std::vector<std::string> setgrade_name_c2;
std::vector<std::string> setgrade_id_c2;
std::vector<std::string> gradeList;
std::vector<std::string>::iterator it_g;

std::vector<std::string> coursecreation_name;
std::vector<std::string> coursecreation_id;
std::vector<std::string> coursecreation_name_c;
std::vector<std::string> coursecreation_id_c;
std::vector<std::string> coursecreation_name2;
std::vector<std::string> coursecreation_id2;
std::vector<std::string> coursecreation_name_c2;
std::vector<std::string> coursecreation_id_c2;

std::vector<std::string> coursecancel_name;
std::vector<std::string> coursecancel_id;
std::vector<std::string> coursecancel_name_c;
std::vector<std::string> coursecancel_id_c;
std::vector<std::string> coursecancel_name2;
std::vector<std::string> coursecancel_id2;
std::vector<std::string> coursecancel_name_c2;
std::vector<std::string> coursecancel_id_c2;

