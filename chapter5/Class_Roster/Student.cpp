#include "Student.h"
//=== Constructors ===
Student::Student()
:name(""),
IDNum(-1),
gradeChar('\0'),
gradeNum(-1)
{}
Student::Student(std::string _name, int _IDNum, int _gradeNum, char _gradeChar)
:name(_name),
IDNum(_IDNum),
gradeChar(_gradeChar),
gradeNum(_gradeNum)
{}
