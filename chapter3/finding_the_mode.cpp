#include <iostream>
using std::cout;

int main()
{
    //Build array
    const int ARRAY_SIZE = 12;
    int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};

    //Set initial mode
    const int RESPONSES = 10;
    int mode;
    int modeCount = 0;
    int maxCount = 0;

    for(int i = 1; i <= RESPONSES; ++i)
    {
        //Check occurences
       for(int j = 0; j < ARRAY_SIZE; ++j)
       {
           if(surveyData[j] == i)
           {
               ++modeCount;
           }
       }

       //Process count
        if(modeCount > maxCount)
        {
            maxCount = modeCount;
            mode = i;
        }

        //Reset modecount
        modeCount = 0;
    }
    cout << "Mode is: " << mode << '\n';
    cout << "Count: " << maxCount;
    return 0;
}
