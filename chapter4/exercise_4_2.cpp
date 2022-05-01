#include <iostream>
#include <string>
using std::cout;
using std::cin;

typedef char * arrayString;

int length(const arrayString& s);
arrayString substring(const arrayString& s, const int posStart, const int len);
void print(const arrayString& s);

int main()
{
    //Original string
    arrayString s = new char[5];
    s[0] = 't'; s[1] = 'e'; s[2] = 's'; s[3] = 't'; s[4] = '\0';
    print(s);

    //Substring test
    arrayString s2 = substring(s, 0, 2);
    print(s2);

    delete[] s;
    delete[] s2;

    return 0;
}
int length(const arrayString& s)
{
    int l = 0;
    while(s[l] != '\0')
        ++l;
    return l;
}
void print(const arrayString& s)
{
    int l = length(s);
    for(int i = 0; i < l; ++i)
        cout << s[i];
    cout << '\n';
}
arrayString substring(const arrayString& s, const int posStart, const int len)
{
    arrayString newS = new char[len + 1];

    for(int i = 0; i < len; ++i)
        newS[i] = s[posStart + i];
    newS[len] = '\0';

    return newS;
}
