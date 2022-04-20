#include <iostream>
using std::cout;
using std::cin;

short doubleDigit(short digit);
bool verifyNum(short num);
short readDigit(char input);

int main()
{
    char num;
    cout << "Enter a number: ";
    cin >> num;

    int sumEven = 0;
    int sumOdd  = 0;
    int position = 1;
    bool ver;

    //Get digits one at a time
    while(num != '\n')
    {
        if(position % 2 == 0)
        {
            sumEven += readDigit(num);
            sumOdd  += doubleDigit(readDigit(num));
        }
        else
        {
            sumEven += doubleDigit(readDigit(num));
            sumOdd  += readDigit(num);
        }
        num = cin.get();
        ++position;
    }

    //Verify sum
    if((position - 1) % 2 == 0)
    {
        ver = verifyNum(sumEven);
    }
    else
    {
        ver = verifyNum(sumOdd);
    }

    //Output correct message
    if(ver)
    {
        cout << "Number is divisible by 10. Verified.\n";
    }
    else
    {
        cout << "Number is not divisible by 10. Not verified.\n";
    }
    return 0;
}
short doubleDigit(short digit)
{
    short extraDigit = 0;
    digit *= 2;

    if(digit > 9)
    {
        //Separate digits
        extraDigit = digit % 10;
        digit      /= 10;

        //Add back together
        digit += extraDigit;
    }

    return digit;
}
bool verifyNum(short num)
{
    if((num % 10) == 0)
        return true;
    return false;
}
short readDigit(char input)
{
    switch(input)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case '0':
            return 0;
        default:
            break;
    }
}
