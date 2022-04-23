#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;

std::string dec_to_bin(int dec);
int bin_to_dec(std::string bin);

int main()
{
    char menuChoice;
    std::string response;

    cout << "1. Binary-to-decimal\n2. Decimal-to-binary\n";
    cin >> menuChoice;

    if(menuChoice == '1')
    {
        cout << "Enter number: ";
        cin >> response;

        //dec_to_bin
        cout << bin_to_dec(response);
    }
    else if(menuChoice == '2')
    {
        cout << "Enter number: ";
        cin >> response;

        //bintodec
        cout << dec_to_bin(std::stoi(response));
    }
    return 0;
}
std::string dec_to_bin(int dec)
{
    std::string binNum;

    while(dec > 0)
    {
        binNum.push_back((dec % 2) + '0');
        dec /= 2;
    }
    return binNum;
}
int bin_to_dec(std::string bin)
{
    short pow_of_2 = 0;
    int dec = 0;

    for(int i = bin.length() - 1; i >= 0; --i)
    {
        if(bin.at(i) == '1')
        {
            dec += pow(2, pow_of_2);
        }
        ++pow_of_2;
    }
    return dec;
}
