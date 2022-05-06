#include <string>
#include <vector>

class Roster
{
    struct student
    {
        std::string name;
        int IDNum;
        int gradeNum;
        char gradeChar;
    };
    std::vector<student*> studentList;
public:
    //=== Constructors ===
    Roster();
    Roster(std::string _name, int _IDNum, int _gradeNum, char _gradeChar);
};
