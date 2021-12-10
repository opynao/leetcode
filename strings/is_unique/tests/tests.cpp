#include "is_unique.h"
#include "profile.h"

#include "gtest/gtest.h"

#include <algorithm>

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
    std::string str1{"abcde"};
    std::string str2{"hello"};

    EXPECT_TRUE(isUniqueChars(str1));
    EXPECT_FALSE(isUniqueChars(str2));

    EXPECT_TRUE(isUniqueChars_bitvector(str1));
    EXPECT_FALSE(isUniqueChars_bitvector(str2));

    EXPECT_TRUE(isUniqueChars_noDS(str1));
    EXPECT_FALSE(isUniqueChars_noDS(str2));

    EXPECT_TRUE(isUniqueChars_set(str1));
    EXPECT_FALSE(isUniqueChars_set(str2));
}

TEST(Speed, Test)
{
    std::vector<std::string> v;
    for (size_t i = 0; i != 100000; ++i)
        v.push_back(random_string(50));

    auto f1 = [&v]()
    {
        for (const auto str : v)
            isUniqueChars(str);
    };
    auto f2 = [&v]()
    {
        for (const auto str : v)
            isUniqueChars_bitvector(str);
    };
    auto f3 = [&v]()
    {
        for (const auto str : v)
            isUniqueChars_noDS(str);
    };
    auto f4 = [&v]()
    {
        for (const auto str : v)
            isUniqueChars_set(str);
    };
    std::cerr << "isUniqueChars runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "isUniqueChars_bitvector runtime=" << profiler<>::duration(f2).count() << "ms\n";
    std::cerr << "isUniqueChars_noDS runtime=" << profiler<>::duration(f3).count() << "ms\n";
    std::cerr << "isUniqueChars_set runtime=" << profiler<>::duration(f4).count() << "ms\n";
}