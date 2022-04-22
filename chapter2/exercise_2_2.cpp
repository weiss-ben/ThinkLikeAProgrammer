#include <iostream>
using std::cout;
using std::cin;

int main()
{
    short space = 3;
    short pound = 2;
    short length = 8;
    bool ascending = true;

    while(length > 0)
    {
        for(int i = 0; i < space; ++i)
        {
            cout << ' ';
        }
        for(int j = 0; j < pound; ++ j)
        {
            cout << '#';
        }

        //Check for print order
        if(ascending)
        {
            --space;
            pound +=2;
        }
        else
        {
            ++space;
            pound -=2;
        }

        if(space == -1)
        {
            ascending = false;
            pound = 8;
            space = 0;
        }

        --length;
        cout << '\n';
    }
}
