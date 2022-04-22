#include <iostream>
#include <string>
using std::cout;
using std::cin;

int checkSum();
bool verifyNum(int sum);
short genCheckDigit();

int main()
{
    short menuChoice;
    std::string num;

    cout << "Verify(1) or generate check-digit(2)?";
    cin >> menuChoice;

    if(menuChoice == 1)
    {
        cout << "Enter number: ";

        //Check input
        if(verifyNum(checkSum()))
        {
            cout << "Verified.\n";
        }
        else
        {
            cout << "Error: Number not valid.\n";
        }

    }
    else if(menuChoice == 2)
    {
        cout << "Enter number: ";
        cout << "Check digit is: " << genCheckDigit() ;
    }

    return 0;
}
int checkSum()
{
    char digit;
    int runningTotal = 0;
    short numDigit = 1;

    cin >> digit;

    while(digit != '\n')
    {
        //Multiply every other digit by 3
        if(numDigit % 2 == 0)
        {
            runningTotal += (digit - '0') * 3;
        }
        else
        {
            runningTotal += (digit - '0');
        }
        cin.get(digit);
        ++numDigit;
    }
    return runningTotal;
}
bool verifyNum(int sum)
{
    if(sum % 10 == 0)
        return true;
    return false;
}
short genCheckDigit()
{
    int num = checkSum();
    cout << checkSum << '\n';
    short checkDig = 10 - (num % 10);

    return checkDig;
}
