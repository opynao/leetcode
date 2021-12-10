#include "is_unique.h"
#include "utils.h"

#include <vector>
#include <iostream>
#include <bitset>
#include <set>

constexpr int MAX_CHARS = 128;

bool isUniqueChars(const std::string &str)
{
    if (str.length() > MAX_CHARS)
        return false;

    std::vector<bool> char_set(MAX_CHARS);
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i]; // Conversion of char into int, bs every char has its int number

        if (char_set[val])
            return false;

        char_set[val] = true;
    }
    return true;
}

// Fastest
bool isUniqueChars_bitvector(const std::string &str)
{
    // Reduce space usage by a factor of 8 using bitvector.
    // Each boolean otherwise occupies a size of 8 bits.
    std::bitset<MAX_CHARS> bits(0);
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i];
        if (bits.test(val) > 0) // if the value is already 1 (true) it means that it has already met
            return false;

        bits.set(val);
    }
    return true;
}

bool isUniqueChars_noDS(const std::string &str)
{
    for (int i = 0; i < str.length() - 1; i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])
                return false;
        }
    }
    return true;
}

// Slowest
bool isUniqueChars_set(const std::string &str)
{
    std::set<char> s;
    bool isInserted;
    std::set<char>::iterator itInserted;
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        auto [itInserted, isInserted] = s.insert(*it);
        if (isInserted == false)
            return false;
    }
    return true;
}