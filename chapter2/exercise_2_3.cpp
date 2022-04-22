#include <iostream>
using std::cout;
using std::cin;

int main()
{
    short space = 0;
    short pound = 2;
    short length = 8;
    bool ascending = true;

    while(length > 0)
    {
        for(int i = 0; i < space; ++i)
        {
            cout << ' ';
        }
        for(int j = 0; j < pound / 2; ++ j)
        {
            cout << '#';
        }

        //Check for order
        if(ascending)
        {
            ++space;
            pound += 2;
        }
        else
        {
            --space;
            pound -= 2;
        }

        //Switch order
        if(pound == 10)
        {
            ascending = false;

            pound = 8;
            space = 3;
        }

        --length;
        cout << '\n';
    }
}
