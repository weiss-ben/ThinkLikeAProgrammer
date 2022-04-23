#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;

std::string dec_to_bin(int dec);
int bin_to_dec(std::string bin);
std::string bin_to_hex(std::string hex);
std::string dec_to_hex(int dec);
std::string hex_to_bin(std::string hex);
int hex_to_dec(std::string hex);
std::string toHexChar(int dec);
int hexCharToNum(char hexChar);

int main()
{
    char menuChoice;
    std::string response;

    cout << "1. Binary -> Decimal\n2. Decimal -> Binary\n3. Binary -> Hexadecimal\n";
    cout << "4. Decimal -> Hexadecimal\n5. Hexadecimal -> Binary\n6. Hexadecimal -> Decimal\n";
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
    else if(menuChoice == '3')
    {
        cout << "Enter number: ";
        cin >> response;

        cout << bin_to_hex(response);

    }
    else if(menuChoice == '4')
    {
        cout << "Enter number: ";
        cin >> response;

        cout << dec_to_hex(std::stoi(response));
    }
    else if(menuChoice == '5')
    {
        cout << "Enter number: ";
        cin >> response;

        cout << hex_to_bin(response);
    }
    else if(menuChoice == '6')
    {
        cout << "Enter number: ";
        cin >> response;

        cout << hex_to_dec(response);
    }
    return 0;
}
std::string dec_to_bin(int dec)
{
    std::string binNum;
    std::string reverseBin;

    //Get binary representation
    while(dec > 0)
    {
        reverseBin.push_back((dec % 2) + '0');
        dec /= 2;
    }

    //Reverse to proper order
    for(int j = 0; j < reverseBin.length(); ++j)
    {
        binNum.push_back(reverseBin.at((reverseBin.length() - 1) - j));
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
std::string bin_to_hex(std::string hex)
{
    int dec = bin_to_dec(hex);
    return dec_to_hex(dec);
}
std::string dec_to_hex(int dec)
{
    std::string hexNum;

    while(dec > 0)
    {
        hexNum.insert(0, toHexChar(dec % 16));
        dec /= 16;
    }
    return hexNum;
}
std::string toHexChar(int dec)
{
    switch(dec)
    {
        case 10:
            return "A";
        case 11:
            return "B";
        case 12:
            return "C";
        case 13:
            return "D";
        case 14:
            return "E";
        case 15:
            return "F";
        default:
            return std::to_string(dec);
    }
}
int hex_to_dec(std::string hex)
{
    int dec = 0;

    for(int i = 0; i < hex.length(); ++i)
    {
        dec += hexCharToNum((hex.at(i) )) * int(pow(16, i));
    }
    return dec;
}
std::string hex_to_bin(std::string hex)
{
    int dec = hex_to_dec(hex);
    return dec_to_bin(dec);
}
int hexCharToNum(char hexChar)
{
    switch(hexChar)
    {
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
        default:
            return int(hexChar + '0');
    }
}
