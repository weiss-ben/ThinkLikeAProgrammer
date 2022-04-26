#include <iostream>
using std::cout;

bool isSorted(int* arr, const int SIZE);

int main()
{
    const int SIZE = 10;
    int arr[SIZE] = {1, 3, 2, 4, 5, 7, 6, 8, 0, 9};

    if(isSorted(arr, SIZE))
    {
        cout << "Array is sorted.\n";
    }
    else
    {
        cout << "Array is not sorted.\n";
    }
    return 0;
}
bool isSorted(int* arr, const int SIZE)
{
    for(int i = 1; i < SIZE; ++i)
    {
        if(arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
