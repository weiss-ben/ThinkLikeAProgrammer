#include <iostream>
#include <string>
//#include "leaker.h"
using std::cout;
using std::cin;

struct student
{
    int grade;
    int studentID;
    std::string name;
};

int gradeCompare(const void* voidA, const void* voidB);

int main()
{
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
            {87, 10001, "Fred"},
            {28, 10002, "Tom"},
            {100, 10003, "Alistair"},
            {78, 10004, "Sasha"},
            {84, 10005, "Erin"},
            {98, 10006, "Belinda"},
            {75, 10007, "Leslie"},
            {70, 10008, "Candy"},
            {81, 10009, "Aretha"},
            {68, 10010, "Veronica"}
    };

    //Sort by grade
    qsort(studentArray, ARRAY_SIZE, sizeof(student), gradeCompare);

    int quartiles[3];
    quartiles[0] = studentArray[((ARRAY_SIZE + 1) / 4)].grade;             //q1
    quartiles[1] = studentArray[(3 * (ARRAY_SIZE + 1) / 4)].grade;         //q3
    quartiles[2] = studentArray[(ARRAY_SIZE + 1) / 2].grade;               //q2

    for(int i = 0; i < 3; ++i)
        cout << "Q" << (i + 1) << ": " << quartiles[i] << '\n';

    return 0;
}
int gradeCompare(const void* voidA, const void* voidB)
{
    auto intA = (student*)(voidA);
    auto intB = (student*)(voidB);
    return intA->grade - intB->grade;
}
