#include "palindrome_permutation.h"
#include "utils.h"

#include <cctype>
#include <array>

// Fastest
bool isPermutationOfPalindrome1(const std::string &phrase)
{
    std::vector<int> table(128, 0);
    for (size_t i = 0; i != phrase.length(); ++i)
    {
        int c = std::toupper(phrase[i]);
        ++table[c];
    }
    bool isOdd{false};
    for (size_t i = 0; i != table.size(); ++i)
    {
        if (table[i] % 2)
        {
            if (isOdd)
                return false;
            isOdd = true;
        }
    }
    return true;
}

bool isPermutationOfPalindrome2(const std::string &phrase)
{
    std::array<int, 26> table{0};
    for (size_t i = 0; i != phrase.length(); ++i)
    {
        if (phrase[i] == ' ')
            continue;
        int c = getCharIndex(phrase[i]);
        ++table[c];
    }
    bool isOdd{false};
    for (size_t i = 0; i != table.size(); ++i)
    {
        if (table[i] % 2)
        {
            if (isOdd)
                return false;
            isOdd = true;
        }
    }
    return true;
}

int getCharIndex(const char c)
{
    int idx = -1;
    if (c >= 'a' && c <= 'z')
    {
        idx = c - 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        idx = c - 'A';
    }
    return idx;
}