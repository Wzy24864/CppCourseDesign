#include "Student.h"
Student::Student(string &n, string &s) :name(n), id(s){}
void Student::display() {
    cout << "\n学生信息:" <<
    " 学生姓名:" << name <<
    "\t学生id:" << id;
}
string Student::getId() { return id; }
string Student::getName() { return name; };