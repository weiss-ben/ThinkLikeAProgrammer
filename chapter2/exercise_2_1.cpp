#include <iostream>
using std::cout;
using std::cin;

int main()
{
    short len = 8;
    short space = 0;

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
