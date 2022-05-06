#include <string>
#include <vector>

class Student
{
    std::string name;
    int IDNum;
    int gradeNum;
    char gradeChar;
public:
    //=== Constructors ===
    Student();
    Student(std::string _name, int _IDNum, int _gradeNum, char _gradeChar);
};
