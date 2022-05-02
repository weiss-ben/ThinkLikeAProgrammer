#include <iostream>
#include <string>
using std::cout;
using std::cin;

typedef char * arrayString;

int length(const arrayString& s);
void print(const arrayString& s);
const char characterAt(const arrayString& s, const int index);
void append(arrayString &s, const char c);
void concatenate(arrayString& s1, const arrayString& s2);
arrayString substring(const arrayString& s, const int posStart, const int len);
void replaceString(arrayString& source, arrayString& target, arrayString replaceText);
int find(const arrayString& source, const arrayString& target);

int main()
{
    //Original string
    arrayString s = new char[5];
    s[0] = 'a'; s[1] = 'b'; s[2] = 'c'; s[3] = 'd'; s[4] = '\0';
    print(s);

    arrayString target = new char[3];
    target[0] = 'b'; target[1] = 'c'; target[2] = '\0';

    arrayString rT = new char[4];
    rT[0] = 'x'; rT[1] = 'y'; rT[2] = 'z'; rT[3] = '\0';

    //cout << "Find: " << find(s, target);

    replaceString(s, target, rT);
    print(s);

    delete[] s;
    delete[] target;
    delete[] rT;

    return 0;
}
int length(const arrayString& s)
{
    int l = 0;
    while(s[l] != '\0')
        ++l;
    return l;
}
void print(const arrayString& s)
{
    int l = length(s);
    for(int i = 0; i < l; ++i)
        cout << s[i];
    cout << '\n';
}
const char characterAt(const arrayString& s, const int index)
{
    return s[index];
}
void append(arrayString &s, const char c)
{
    //Get length
    int oldLength = length(s);

    //Transfer from old to new
    arrayString newS = new char[oldLength + 2];
    for(int i = 0; i < oldLength; ++i)
        newS[i] = s[i];

    //Append new char
    newS[oldLength] = c;
    newS[oldLength + 1] = '\0';

    delete[] s;
    s = newS;
}
void concatenate(arrayString& s1, const arrayString& s2)
{
    int s2Length = length(s2);

    for(int j = 0; j < s2Length; ++j)
        append(s1, characterAt(s2, j));
}
arrayString substring(const arrayString& s, const int posStart, const int len)
{
    arrayString newS = new char[len + 1];

    for(int i = 0; i < len; ++i)
        newS[i] = s[posStart + i];
    newS[len] = '\0';

    return newS;
}
void replaceString(arrayString& source, arrayString& target, arrayString replaceText)
{
    int sourceLen = length(source);
    int targetLen = length(target);
    int replaceLen = length(replaceText);

    //Declare temp array for use in while
    arrayString tempS;

    //Find first occurrence
    int tPos = find(source, target);

    while(tPos != -1)
    {
        //Beginning
        if(tPos == 0)
        {
            //Make a new array of target and concatenate source[starting at replace length]
            tempS = new char[replaceLen + 1];
            for(int i = 0; i < replaceLen; ++i)
                tempS[i] = replaceText[i];
            tempS[replaceLen] = '\0';

            concatenate(tempS, substring(source, targetLen, (sourceLen - targetLen)));
        }
        else if(tPos == (sourceLen - targetLen))    //End
        {
            //Make a new array of source[until sourceLen - targetLen] and concatenate replace
            tempS = new char[(sourceLen - targetLen) + 1];
            for(int i = 0; i < (sourceLen - targetLen); ++i)
                tempS[i] = source[i];
            tempS[(sourceLen - targetLen)] = '\0';

            concatenate(tempS, replaceText);
        }
        else    //Target is in the middle
        {
            //Copy up to source[tPos]
            tempS = new char[tPos + 1];
            for(int i = 0; i < tPos; ++i)
                tempS[i] = source[i];
            tempS[tPos] = '\0';

            //insert replace
            concatenate(tempS, replaceText);

            //copy source[tPos + target length -> end]
            concatenate(tempS, substring(source, (tPos + targetLen), (sourceLen - replaceLen)));
        }

        //Update source
        delete[] source;
        source = tempS;

        //Update loop variable
        tPos = find(source, target);
    }
}
int find(const arrayString& source, const arrayString& target)
{
    int indexS = 0;
    int targetLen = length(target);
    bool match = false;

    while(source[indexS] != '\0')
    {
        if(source[indexS] == target[0])
        {
            for(int i = 1; i < targetLen; ++i)
            {
                if(target[i] != source[indexS + i])
                {
                    match = false;
                    break;
                }
                match = true;
            }
        }

        if(match)
        {
            return (indexS);
        }
        ++indexS;
    }
    return -1;
}
