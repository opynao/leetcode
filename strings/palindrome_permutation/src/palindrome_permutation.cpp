#include "palindrome_permutation.h"
#include "utils.h"

#include <cctype>

bool isPermutationOfPalindrome(const std::string &phrase)
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