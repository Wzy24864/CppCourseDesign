#pragma once
#include <iostream>
using std::string;
using std::cout;
class Student
{
private:
    string name;
    string id;
public:
    Student(string &n, string &i);
    Student();
    void display();
    string getName();
    string getId();
};

