#include <iostream>
#include <string>
using std::cout;
using std::cin;

typedef char * arrayString;

const char characterAt(const arrayString& s, const int index);
void append(arrayString &s, const char c);
int length(const arrayString& s);
void concatenate(arrayString& s1, const arrayString& s2);

int main()
{
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = '\0';

    arrayString a2 = new char[5];
    a2[0] = 't'; a2[1] = 'e'; a2[2] = 's'; a2[3] = 't'; a2[4] = '\0';

    append(a, '!');
    cout << "Append Test: " << a << '\n';

    concatenate(a, a2);
    cout << "Concat Test: " << a << '\n';

    delete[] a;
    delete[] a2;
    return 0;
}
const char characterAt(const arrayString& s, const int index)
{
    return s[index];
}
void append(arrayString &s, const char c)
{
    //Get length
    int oldLength = length(s);

    //Transfer from old to new
    arrayString newS = new char[oldLength + 2];
    for(int i = 0; i < oldLength; ++i)
        newS[i] = s[i];

    //Append new char
    newS[oldLength] = c;
    newS[oldLength + 1] = '\0';

    delete[] s;
    s = newS;
}
int length(const arrayString& s)
{
    int l = 0;
    while(s[l] != '\0')
        ++l;
    return l;
}
void concatenate(arrayString& s1, const arrayString& s2)
{
    int s2Length = length(s2);

    for(int j = 0; j < s2Length; ++j)
        append(s1, characterAt(s2, j));
}
