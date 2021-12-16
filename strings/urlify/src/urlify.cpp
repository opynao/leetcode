#include <urlify.h>

#include <algorithm>
#include <regex>
#include <boost/algorithm/string/replace.hpp>

// Slowest
void replaceWhitespace2(std::string &str)
{
    str = std::regex_replace(str, std::regex(" "), "%20");
}

// Fastest
void replaceWhitespace3(std::string &str)
{
    size_t start_pos{0};
    const std::string from{" "};
    const std::string to{"%20"};
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
}

void replaceWhitespace4(std::string &str)
{
    boost::replace_all(str, " ", "%20");
}

void replaceWhitespace5(std::string &source)
{
    const std::string &from{" "};
    const std::string &to{"%20"};
    std::string newString;
    newString.reserve(source.length()); // avoids a few memory allocations

    std::string::size_type lastPos = 0;
    std::string::size_type findPos;

    while (std::string::npos != (findPos = source.find(from, lastPos)))
    {
        newString.append(source, lastPos, findPos - lastPos);
        newString += to;
        lastPos = findPos + from.length();
    }

    // Care for the rest after last occurrence
    newString += source.substr(lastPos);

    source.swap(newString);
}