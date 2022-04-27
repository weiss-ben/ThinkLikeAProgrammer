#include <iostream>
#include <string>
using std::cout;
using std::cin;

int char_to_index(const char c);

int main()
{
    const char cipher[26] = {'1', '3', '*', '[', '%', 'V', 'a', '$', '@', 'C', '#', '\'','h', 'w',
                             'X', '<', '>', '?', '.', ',', '^', '&', '!', ')', '0','-'};

    std::string code;
    std::string line;
    cout << "Enter a message to encrypt: ";
    getline(cin, line);

    //Position indices
    std::size_t begin = 0;
    std::size_t space = line.find(" ", begin);

    while(begin != std::string::npos)
    {
        //Extract word
        std::string word = line.substr(begin, space - begin);

        for(int i = 0; i < word.length(); ++i)
        {
            code += cipher[char_to_index(word.at(i))];
        }
        //Add a space after each word
        code += ' ';

        //Update indices
        begin = space == std::string::npos ? space : space + 1;
        space = line.find(' ', begin + 1);
    }

    cout << "Encrypted text: " << code << '\n';

    return 0;
}
int char_to_index(const char c)
{
    if(c > 96)
    {
        return c % 97;
    }
    else
    {
        return c % 65;
    }
}
