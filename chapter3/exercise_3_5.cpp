#include <iostream>
#include <string>
using std::cout;
using std::cin;

int char_to_index(const char c);
std::string encrypt_text(const std::string& text, const char* cipher);
std::string decrypt_text(std::string code, const char* cipher);
const char find_index(const char letter, const char* cipher);

int main()
{
    const char cipher[26] = {'1', '3', '*', '[', '%', 'V', 'a', '$', '@', 'C', '#', '\'','h', 'w',
                             'X', '<', '>', '?', '.', ',', '^', '&', '!', ')', '0','-'};

    std::string line;
    cout << "Enter a message to encrypt: ";
    getline(cin, line);

    std::string code = encrypt_text(line, cipher);
    cout << "Encrypted text: " << code;
    cout << "Decrypted text: " << decrypt_text(code, cipher) << '\n';

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
std::string encrypt_text(const std::string& text, const char* cipher)
{
    std::string code;

    //Position indices
    std::size_t begin = 0;
    std::size_t space = text.find(' ', begin);

    while(begin != std::string::npos)
    {
        //Extract word
        std::string word = text.substr(begin, space - begin);

        for(int i = 0; i < word.length(); ++i)
        {
            code += cipher[char_to_index(word.at(i))];
        }
        //Add a space after each word
        code += ' ';

        //Update indices
        begin = space == std::string::npos ? space : space + 1;
        space = text.find(' ', begin + 1);
    }
    return code;
}
std::string decrypt_text(std::string code, const char* cipher)
{
    std::string plain_text;

    for(int i = 0; i < code.length(); ++i)
    {
        if(code.at(i) != ' ')
        {
            plain_text += find_index(code.at(i), cipher);
        }
        else
        {
            plain_text += ' ';
        }
    }
    return plain_text;
}
const char find_index(const char letter, const char* cipher)
{
    //Linear search for index
    for(int i = 0; i < 26; ++i)
    {
        if(letter == cipher[i])
            return (i + 'a');
    }
    return -1;
}
