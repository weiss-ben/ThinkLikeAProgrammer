#include <iostream>
using std::cout;
using std::cin;

enum decodeMode {UPPER, LOWER, PUNCT};

enum decodeMode switchMode(short modeController);
void decode(int charCode, enum decodeMode* mode);

int main()
{
    char num;
    int charCode = 0;

    enum decodeMode mode = UPPER;

    //Read values in
    do
    {
        num = cin.get();

        //Skip commas
        while(num != ',' && num != '\n')
        {
            //convert to number
            charCode *= 10;
            charCode += (num - '0');

            cin.get(num);
        }

        //Decode
        decode(charCode, &mode);

        //Re-set charCode
        charCode = 0;
    }
    while(num != '\n');

    return 0;
}
enum decodeMode switchMode(short modeController)
{
    switch(modeController)
    {
        case 0:
            return UPPER;
        case 1:
            return LOWER;
        case 2:
            return PUNCT;
        default:
            break;
    }
}
void decode(int charCode, enum decodeMode* mode)
{
    if(*mode == UPPER)
    {
        if(charCode % 27 == 0)
        {
            *mode = switchMode(1);
        }
        else
        {
            cout << char((charCode % 27) + 'A' - 1);

        }
    }
    else if(*mode == LOWER)
    {
        if(charCode % 27 == 0)
        {
            *mode = switchMode(2);
        }
        else
        {
            cout << char((charCode % 27) + 'a' - 1);
        }
    }
    else
    {
        if(charCode % 9 == 0)
        {
            *mode = switchMode( 0);
        }
        else
        {
            switch(charCode % 9)
            {
                case 1:
                    cout << '!';
                    break;
                case 2:
                    cout << '?';
                    break;
                case 3:
                    cout << ',';
                    break;
                case 4:
                    cout << '.';
                    break;
                case 5:
                    cout << ' ';
                    break;
                case 6:
                    cout << ';';
                    break;
                case 7:
                    cout << '"';
                    break;
                case 8:
                    cout << '\'';
                    break;
            }
        }
    }
}
