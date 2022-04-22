#include <iostream>
using std::cout;
using std::cin;

int main()
{
    short len = 2;
    short space = 3;

    while(len <= 8)
    {
        for(int j = 0; j < space; ++j)
        {
            cout << ' ';
        }
        for(int i = len; i > 0; --i)
        {
            cout << '#';
        }
        cout << '\n';
        len +=2;
        --space;
    }
    len -= 2;
    ++space;
    while(len > 0)
    {
        for(int j = 0; j < space; ++j)
        {
            cout << ' ';
        }
        for(int i = 0; i < len; ++i)
        {
            cout << '#';
        }
        cout << '\n';
        len -=2;
        ++space;
    }
}
