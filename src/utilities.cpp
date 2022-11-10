#include "utilities.h"

vector<string> split(string str, char del) {
    // declaring temp string to store the curr "word" upto del
    string temp = "";
    vector<string> to_ret;
    for (int i = 0; i < (int)str.size(); i++)
    {
        // If cur char is not del, then append it to the cur "word", otherwise
        // you have completed the word, print it, and start a new word.
        if (str[i] != del)
        {
            temp += str[i];
        }
        else
        {
            to_ret.push_back(temp);
            temp = "";
        }
    }

    to_ret.push_back(temp);
    return to_ret;
}