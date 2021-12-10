#include "check_permutation.h"
#include "profile.h"

#include "gtest/gtest.h"

std::string random_string(size_t length)
{
    auto randchar = []() -> char
    {
        constexpr char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}

TEST(Correctness, Test)
{
    std::string str1 = "testest";
    std::string str2 = "estxest";

    EXPECT_FALSE(arePermutation_sort(str1, str2));
    EXPECT_FALSE(arePermutation(str1, str2));
    EXPECT_FALSE(arePermutation_stl(str1, str2));

    str1 = "hello";
    str2 = "oellh";

    EXPECT_TRUE(arePermutation_sort(str1, str2));
    EXPECT_TRUE(arePermutation(str1, str2));
    EXPECT_TRUE(arePermutation_stl(str1, str2));
}

TEST(Speed, Test_WordsArePermutations)
{
    std::vector<std::string> v;
    for (size_t i = 0; i != 100000; ++i)
        v.push_back(random_string(50));

    auto f1 = [&v]()
    {
        for (auto str : v)
            arePermutation_sort(str, str);
    };
    auto f2 = [&v]()
    {
        for (auto str : v)
            arePermutation(str, str);
    };
    auto f3 = [&v]()
    {
        for (auto str : v)
            arePermutation_stl(str, str);
    };
    std::cerr << "arePermutation_sort runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "arePermutation runtime=" << profiler<>::duration(f2).count() << "ms\n";
    std::cerr << "arePermutation_stl runtime=" << profiler<>::duration(f3).count() << "ms\n";
}

TEST(Speed, Test_WordsAreNotPermutations)
{
    std::vector<std::string> v;
    for (size_t i = 0; i != 100000; ++i)
        v.push_back(random_string(50));

    auto f1 = [&v]()
    {
        auto itReverse = v.rbegin();
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            arePermutation_sort(*it, *itReverse);
            ++itReverse;
        }
    };
    auto f2 = [&v]()
    {
        auto itReverse = v.rbegin();
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            arePermutation(*it, *itReverse);
            ++itReverse;
        }
    };
    auto f3 = [&v]()
    {
        auto itReverse = v.rbegin();
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            arePermutation_stl(*it, *itReverse);
            ++itReverse;
        }
    };
    std::cerr << "arePermutation_sort runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "arePermutation runtime=" << profiler<>::duration(f2).count() << "ms\n";
    std::cerr << "arePermutation_stl runtime=" << profiler<>::duration(f3).count() << "ms\n";
}