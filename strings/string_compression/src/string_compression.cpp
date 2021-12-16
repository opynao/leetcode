#include "string_compression.h"
#include "utils.h"

// Fastest
std::string compress1(const std::string &str)
{
    char repeatingCh{str[0]};
    int repetitionCount{};
    std::string compressed{""};
    for (size_t i = 0; i != str.size(); ++i)
    {
        if (str[i] == repeatingCh)
        {
            ++repetitionCount;

            if (i == str.size() - 1)
            {
                compressed += repeatingCh;
                compressed += std::to_string(repetitionCount);
            }
        }
        else
        {
            // more effective than
            // compressed += repeatingCh + std::to_string(repetitionCount);
            compressed += repeatingCh;
            compressed += std::to_string(repetitionCount);
            repeatingCh = str[i];
            repetitionCount = 1;
        }
        if (compressed.length() > str.length())
            return str;
    }
    return (compressed.length() < str.length() ? compressed : str);
}

std::string compress2(const std::string &str)
{
    size_t original_length = str.length();
    if (original_length < 2)
        return str;

    std::string out{""};
    int count = 1;
    for (size_t i = 1; i < original_length; ++i)
    {
        if (str[i - 1] == str[i])
        {
            ++count;
        }
        else
        {
            out += str[i - 1];
            out += std::to_string(count);
            count = 1;
        }
        if (out.length() >= original_length)
        {
            return str;
        }
    }
    out += str[original_length - 1];
    out += std::to_string(count);
    return (out.length() >= original_length ? str : out);
}
