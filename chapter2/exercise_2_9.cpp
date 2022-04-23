#include <iostream>
#include <string>
using std::cout;
using std::cin;

bool isVowel(char letter);

int main()
{
    std::string line;

    cout << "Enter a line of text: ";
    getline(cin, line);

    char white_space = line.at(0);
    int space = line.find_first_of(' ');
    int space2 = 0;
    std::string currentWord = line.substr(0, space);
    std::string longestWord;
    std::string mostVowels;
    int maxWord = 0;
    int maxVowel = 0;
    int vowelCount = 0;

    while(white_space != '\n')
    {
        //Get word length
        if(currentWord.length() > maxWord)
        {
            maxWord = currentWord.length();
            longestWord = currentWord;
        }

        //Get num vowels
        for(int i = 0; i < currentWord.length(); ++i)
        {
            if(isVowel(currentWord.at(i)))
                ++vowelCount;
        }
        //Assign maximum vowels
        if(vowelCount > maxVowel)
        {
            maxVowel = vowelCount;
            mostVowels = currentWord;
        }

        //Increment positions
        if(space == line.length() - 1 || space == std::string::npos)
        {
            white_space = '\n';
        }
        else
        {
            vowelCount = 0;
            currentWord = line.substr(space, (line.length() - space));
            space = space + (currentWord.length() - 1);
            white_space = line.at(space);
        }
    }
    cout << "Longest Word: " << longestWord << "\nLength: " << maxWord << '\n';
    cout << "Word with most vowels: " << mostVowels << "\nAmount: " << maxVowel << '\n';

    return 0;
}
bool isVowel(char letter)
{
    if(letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'i' || letter == 'I' || letter == 'o'
    || letter == 'O' || letter == 'u' || letter == 'u')
    {
        return true;
    }
    return false;
}
