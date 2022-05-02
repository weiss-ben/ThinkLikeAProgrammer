#include <iostream>
#include <string>
#include "leaker.h"
using std::cout;
using std::cin;

typedef char * arrayString;

const char characterAt(const arrayString& s, const int index);
void append(arrayString &s, const char c);
void concatenate(arrayString& s1, const arrayString& s2);
void print(const arrayString& s);
int length(const arrayString& s);

int main()
{
    arrayString s = new char[5];
    s[0] = '5'; s[1] = 't'; s[2] = 'e'; s[3] = 's'; s[4] = 't';

    arrayString s2 = new char[5];
    s2[0] = '5'; s2[1] = 't'; s2[2] = 'e'; s2[3] = 's'; s2[4] = 't';

    append(s, '!');
    cout << "Append Test: ";
    print(s);

    concatenate(s, s2);
    cout << "Concat Test: ";
    print(s);

    delete[] s;
    delete[] s2;
    return 0;
}
const char characterAt(const arrayString& s, const int index)
{
    if(index == 0)
        return s[0] +'0';

    return s[index];
}
void append(arrayString &s, const char c)
{
    //Get length
    int oldLength = length(s);

    //Transfer from old to new
    arrayString newS = new char[oldLength + 2];
    for(int i = 1; i <= oldLength; ++i)
        newS[i] = s[i];

    //Append new char
    newS[oldLength] = c;
    newS[0] = ++oldLength;

    delete[] s;
    s = newS;
}
void print(const arrayString& s)
{
    for(int i = 1; i <= length(s); ++i)
        cout << s[i];
    cout << '\n';
}
int length(const arrayString& s)
{
    return(s[0] % '0');
}
void concatenate(arrayString& s1, const arrayString& s2)
{
    //int s2Length = length(s2);

    for(int j = 1; j <= length(s2); ++j)
        append(s1, characterAt(s2, j));
}
