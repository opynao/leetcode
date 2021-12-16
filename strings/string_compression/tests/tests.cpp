#include "string_compression.h"
#include "gtest/gtest.h"
#include "profile.h"

#include <functional>

TEST(Correctness, Test)
{
    const std::string str1{"aaabcccccddddd"};
    const std::string compressed1{"a3b1c5d5"};
    const std::string str2{"hello"};

    EXPECT_EQ(compress1(str1), compressed1);
    EXPECT_EQ(compress1(str2), str2);

    EXPECT_EQ(compress2(str1), compressed1);
    EXPECT_EQ(compress2(str2), str2);
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

TEST(Speed, Test_SymbolsAreRandom)
{
    std::vector<std::string> v;
    for (size_t i = 0; i != 300000; ++i)
        v.push_back(random_string(50));

    auto f1 = [&v]()
    {
        for (auto str : v)
            compress1(str);
    };
    auto f2 = [&v]()
    {
        for (auto str : v)
            compress2(str);
    };

    std::cerr << "compress1 runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "compress2 runtime=" << profiler<>::duration(f2).count() << "ms\n";
}

TEST(Speed, Test_SymbolIsTheSame)
{
    std::vector<std::string> v;
    for (size_t i = 0; i != 300000; ++i)
        v.push_back(std::string(200, 'a'));

    auto f1 = [&v]()
    {
        for (auto str : v)
            compress1(str);
    };
    auto f2 = [&v]()
    {
        for (auto str : v)
            compress1(str);
    };
    std::cerr << "compress1 runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "compress2 runtime=" << profiler<>::duration(f2).count() << "ms\n";
}