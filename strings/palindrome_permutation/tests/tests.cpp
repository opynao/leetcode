#include "palindrome_permutation.h"
#include "gtest/gtest.h"
#include "profile.h"

#include <functional>

TEST(Correctness, Test)
{
    const std::string str1{"Rats live on no evil star"};
    const std::string str2{"hello"};

    EXPECT_TRUE(isPermutationOfPalindrome1(str1));
    EXPECT_FALSE(isPermutationOfPalindrome1(str2));

    EXPECT_TRUE(isPermutationOfPalindrome2(str1));
    EXPECT_FALSE(isPermutationOfPalindrome2(str2));
}

std::string random_string(size_t length)
{
    auto randchar = []() -> char
    {
        constexpr char charset[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}

TEST(Speed, Test_WordsArePermutations)
{
    std::vector<std::string> v;
    for (size_t i = 0; i != 300000; ++i)
        v.push_back(random_string(50));

    auto f1 = [&v]()
    {
        for (auto str : v)
            isPermutationOfPalindrome1(str + str);
    };
    auto f2 = [&v]()
    {
        for (auto str : v)
            isPermutationOfPalindrome2(str + str);
    };

    std::cerr << "isPermutationOfPalindrome1 runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "isPermutationOfPalindrome2 runtime=" << profiler<>::duration(f2).count() << "ms\n";
}

TEST(Speed, Test_WordsAreNotPermutations)
{
    std::vector<std::string> v;
    for (size_t i = 0; i != 300000; ++i)
        v.push_back(random_string(100));

    auto f1 = [&v]()
    {
        for (auto str : v)
            isPermutationOfPalindrome1(str);
    };
    auto f2 = [&v]()
    {
        for (auto str : v)
            isPermutationOfPalindrome2(str);
    };
    std::cerr << "isPermutationOfPalindrome1 runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "isPermutationOfPalindrome2 runtime=" << profiler<>::duration(f2).count() << "ms\n";
}