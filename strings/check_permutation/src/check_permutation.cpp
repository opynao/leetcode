#include "check_permutation.h"
#include "utils.h"

#include <cstdio>
#include <algorithm>

// Slowest
bool arePermutation_sort(std::string &str1, std::string &str2)
{
    if (str1.length() != str2.length())
        return false;

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    return str1 == str2;
}

constexpr size_t ASCII_TABLE_SIZE = 128;
// Fastest
bool arePermutation(const std::string &str1, const std::string &str2)
{
    if (str1.length() != str2.length())
        return false;

    int count[ASCII_TABLE_SIZE] = {0};

    for (int i = 0; i < str1.length(); i++) // increase count[val] if we have this char
    {
        int val = str1[i];
        ++count[val];
    }

    for (int i = 0; i < str2.length(); i++) // decrease count[val] if the same char in the second string
    {
        int val = str2[i];
        --count[val];
        if (count[val] < 0) // if count[val] is less than 0 than the second string has more this char than first
            return false;
    }

    return true;
}

bool arePermutation_stl(const std::string &str1, const std::string &str2)
{
    return std::is_permutation(str1.cbegin(), str1.cend(), str2.begin());
}