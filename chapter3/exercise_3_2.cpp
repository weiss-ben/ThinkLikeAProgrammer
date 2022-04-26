#include <iostream>
using std::cout;

int compareSales(const void* voidA, const void* voidB);

int main()
{
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
            {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
            {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
            {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    int maxMedian = 0;
    int currentMedian;
    for(int i = 0; i < NUM_AGENTS; ++i)
    {
        //Sort sales
        qsort(sales[i], NUM_MONTHS, sizeof(int), compareSales);

        //Get median
        if(NUM_MONTHS % 2 == 0)
        {
            currentMedian = sales[i][NUM_MONTHS / 2];
        }
        else
        {
            currentMedian = (sales[i][NUM_MONTHS / 2] + sales[i][(NUM_MONTHS / 2) + 1]) / 2;
        }

        //Compare to max
        if(currentMedian > maxMedian)
            maxMedian = currentMedian;
    }
    cout << "Maximum median sales: " << maxMedian << '\n';
    return 0;
}
int compareSales(const void* voidA, const void* voidB)
{
    int* saleA = (int*)(voidA);
    int* saleB = (int*)(voidB);
    return *saleA - *saleB;
}
