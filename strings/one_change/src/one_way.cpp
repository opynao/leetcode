#include "one_way.h"
#include "utils.h"

#include <cstdlib>
#include <bitset>
#include <array>

constexpr size_t ALPHABET_SIZE = 26;

int getLetterId(const char ch)
{
    int idx{-1};

    if ('A' <= ch && ch <= 'Z')
        return ch - 'A';
    else
        return ch - 'a';
}

bool isOneChange(const std::string &s1, const std::string &s2)
{
    if (std::abs(static_cast<int>(s1.length() - s2.length())) > 1)
        return false;
    std::array<int, ALPHABET_SIZE> table{0};
    for (const char c : s1)
    {
        int letterId = getLetterId(c);
        ++table[letterId];
    }
    for (const char c : s2)
    {
        int letterId = getLetterId(c);
        --table[letterId];
    }
    bool mismatchDone{false};

    for (const int letterFrequency : table)
    {
        if (letterFrequency != 0)
        {
            if (isOneChange)
                return false;
            mismatchDone = true;
        }
    }
    return true;
}

// Fastest
// Check if the words have changes immediately not processing data in the array
bool isOneChange1(const std::string s1, const std::string s2)
{
    if (std::abs(static_cast<int>(s1.length() - s2.length())) > 1)
        return false;

    std::string bigger, smaller;
    bigger = s1.length() >= s2.length() ? s1 : s2; // a - longest word
    smaller = s1.length() < s2.length() ? s1 : s2;  // b - shortest word
    int len1, len2;
    len1 = bigger.length();
    len2 = smaller.length();

    bool mismatchDone{false};
    for (int i = 0, j = 0; i < len1 && j < len2;)
    {
        if (bigger[i] != smaller[j]) // if the chars are not identical
        {
            if (mismatchDone)
                return false;
            mismatchDone = true;
            if (len1 == len2)
                ++i, ++j;
            else
                ++i;
        }
        else
            ++i, ++j;
    }
    return true;
}