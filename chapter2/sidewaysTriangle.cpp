#include <iostream>
using std::cout;
using std::cin;

void printHashes(int hashLimit);

int main()
{
    printHashes(4);

    return 0;
}

void printHashes(int hashLimit)
{
    unsigned int i, j;

    //Print increasing
    for(i = 1; i <= hashLimit; ++i)
    {
        for(j = 0; j < i; ++j)
            cout << '#';

        cout << '\n';
    }

    //Print decreasing
    for(i = 1; i <= hashLimit; i++)
    {
        for(j = i; j < hashLimit; ++j)
            cout << '#';

        cout << '\n';
    }
}
