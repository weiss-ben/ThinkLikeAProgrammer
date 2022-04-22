#include <iostream>
using std::cout;
using std::cin;

int main()
{
    short len = 12;
    short space = 0;

    while(len > 0)
    {
        //Left space
        for(int j = 0; j < space; ++j)
        {
            cout << ' ';
        }
        //Left pound
        for(int j = 0; j < space + 1; ++j)
        {
            cout << '#';
        }
        //Center spaces
        for(int i = len; i > space; --i)
        {
            cout << ' ';
        }
        //Right pound
        for(int j = 0; j < space + 1; ++j)
        {
            cout << '#';
        }
        cout << '\n';
        len -=3;
        ++space;
    }

    while(len <= 12)
    {
        for(int i = space - 1; i > 0; --i)
        {
            cout << ' ';
        }
        for(int j = 0; j < space; ++j)
        {
            cout << '#';
        }
        for(int i = space; i < len + 4; ++i)
        {
            cout << ' ';
        }
        for(int j = 0; j < space; ++j)
        {
            cout << '#';
        }
        cout << '\n';
        len +=3;
        --space;
    }
}
