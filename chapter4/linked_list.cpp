#include <iostream>
#include <string>
using std::cout;
using std::cin;

struct listNode
{
    int studentNum;
    int grade;
    listNode* next;
};

typedef listNode* studentCollection;

void addRecord(studentCollection& sc, int stuNum, int stuGrade);
void printRecords(studentCollection sc);
double averageRecord(studentCollection sc);

int main()
{
    //Build collection
    studentCollection sc;

    listNode* node1   = new listNode;
    node1->studentNum = 1001;
    node1->grade      = 78;

    listNode* node2   = new listNode;
    node2->studentNum = 1012;
    node2->grade      = 93;

    listNode* node3   = new listNode;
    node3->studentNum = 1076;
    node3->grade      = 85;

    //Set nexts
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;

    //each node to null
    node1 = node2 = node3 = nullptr;

    //Add
    addRecord(sc, 1274, 910);
    printRecords(sc);

    //Average test
    cout << "Average Grade: " << averageRecord(sc) << '\n';

    delete sc;
    return 0;
}
void addRecord(studentCollection& sc,  int stuNum, int stuGrade)
{
    //Allocate
    listNode* newNode  = new listNode;

    //Assign
    newNode->studentNum = stuNum;
    newNode->grade      = stuGrade;
    newNode->next       = sc;

    sc = newNode;

}
void printRecords(studentCollection sc)
{
    while(sc != nullptr)
    {
        cout << "Student ID: " << sc->studentNum << '\n';
        cout << "Student Grade: " << sc->grade << '\n' << '\n';
        sc = sc->next;
    }
}
double averageRecord(studentCollection sc)
{
    //Special Case: sc == null
    if(sc == nullptr)
        return 0;

    double gradeSum = 0;
    double numStudents = 0;

    while (sc != nullptr)
    {
        gradeSum += sc->grade;
        ++numStudents;
        sc = sc->next;
    }
    return gradeSum / numStudents;
}
