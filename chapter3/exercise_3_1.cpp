#include <iostream>
#include <string>
using std::cout;

struct student
{
    int grade;
    int studentID;
    std::string name;
};

int gradeCompare(const void* voidA, const void* voidB);
int IDCompare(const void* voidA, const void* voidB);
void printStudents(student* list, const int size);

int main()
{
    //Construct student array
    const int ARRAY_SIZE = 10;
    struct student studentArray[ARRAY_SIZE] = {
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

    cout << "Student list sorted by grade: " << '\n';
    printStudents(studentArray, ARRAY_SIZE);

    //Sort by ID
    qsort(studentArray, ARRAY_SIZE, sizeof(student), IDCompare);
  
    cout << "Student list sorted by ID: " << '\n';
    printStudents(studentArray, ARRAY_SIZE);

    return 0;
}
int gradeCompare(const void* voidA, const void* voidB)
{
    student* intA = (student*)(voidA);
    student* intB = (student*)(voidB);
    return intA->grade - intB->grade;
}
int IDCompare(const void* voidA, const void* voidB)
{
    student* studentA = (student*)(voidA);
    student* studentB = (student*)(voidB);
    return studentA->studentID - studentB->studentID;
}
void printStudents(student* list, const int size)
{
    unsigned int i;

    for(i = 0; i < size; ++i)
    {
        cout << "Student" << '\n';
        cout << "Name: " << list[i].name << '\n';
        cout << "Student ID: " << list[i].studentID << '\n';
        cout << "Grade: " << list[i].grade << '\n' << '\n';
    }
}
