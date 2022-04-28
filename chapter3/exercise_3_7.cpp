#include <iostream>
using std::cout;
using std::cin;

void print_histogram(const int* hist, const int SIZE);
int find_mode(const int* hist, const int SIZE);

int main()
{
    const int NUM_ELEMENTS = 15;
    const int ELEMENT_RANGE = 10;
    const int values[NUM_ELEMENTS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 7, 7, 9, 7, 3};
    int histogram[ELEMENT_RANGE] = {0};

    for(int i = 1; i <= NUM_ELEMENTS; ++i)
    {
        for(int j = 1; j <= ELEMENT_RANGE; ++j)
        {
            if(values[i - 1] == j)
                histogram[j - 1]++;
        }
    }
    cout << "Mode: " << find_mode(histogram, ELEMENT_RANGE);

    return 0;
}
void print_histogram(const int* hist, const int SIZE)
{
    for(int k = 0; k < SIZE; ++k)
        cout << hist[k] << '\n';

}
int find_mode(const int* hist, const int SIZE)
{
    int maxFreq = hist[0];
    int freqIndex;

    for(int i = 1; i < SIZE; ++i)
    {
        if(hist[i] > maxFreq)
        {
            maxFreq = hist[i];
            freqIndex = i;
        }
    }
    return hist[freqIndex];
}
