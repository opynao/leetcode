#include "one_way.h"
#include "utils.h"
#include <profile.h>

#include "gtest/gtest.h"
#include <map>

TEST(Correctness, Test)
{
    const std::unordered_map<std::string, std::string> m_true{
        {"pale", "ple"},
        {"pales", "pale"},
        {"pale", "bale"}};

    for (auto it = m_true.begin(); it != m_true.end(); ++it)
        EXPECT_TRUE(isOneChange(it->first, it->second));

    for (auto it = m_true.begin(); it != m_true.end(); ++it)
        EXPECT_TRUE(isOneChange1(it->first, it->second));

    const std::map<std::string, std::string> m_false{
        {"pale", "bake"}};

    for (auto it = m_false.begin(); it != m_false.end(); ++it)
        EXPECT_FALSE(isOneChange(it->first, it->second));

    for (auto it = m_false.begin(); it != m_false.end(); ++it)
        EXPECT_FALSE(isOneChange1(it->first, it->second));
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

TEST(Speed, WithoutChanges)
{
    std::vector<std::string> v;
    for (size_t i = 0; i != 100000; ++i)
        v.push_back(random_string(50));

    auto f1 = [&v]()
    {
        for (const std::string &str : v)
            isOneChange(str, str);
    };
    auto f2 = [&v]()
    {
        for (const std::string &str : v)
            isOneChange1(str, str);
    };
    std::cerr << "isOneChange strings without changes runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "isOneChange1  strings without changes runtime=" << profiler<>::duration(f2).count() << "ms\n";
}

TEST(Speed, OneChange)
{
    std::vector<std::string> v;
    for (size_t i = 0; i != 100000; ++i)
        v.push_back(random_string(50));

    auto f1 = [&v]()
    {
        for (const std::string &str : v)
        {
            std::string changed = str;
            changed[49] = 'A';
            isOneChange(str, changed);
        }
    };
    auto f2 = [&v]()
    {
        for (const std::string &str : v)
        {
            std::string changed = str;
            changed[49] = 'A';
            isOneChange1(str, changed);
        }
    };

    std::cerr << "isOneChange strings with one change runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "isOneChange1 strings with one change runtime=" << profiler<>::duration(f2).count() << "ms\n";
}

TEST(Speed, SomeChanges)
{
    std::vector<std::string> v;
    for (size_t i = 0; i != 100000; ++i)
        v.push_back(random_string(50));

    auto f1 = [&v]()
    {
        for (const std::string &str : v)
        {
            std::string changed = str;
            changed[49] = 'A';
            changed[48] = 'B';
            isOneChange(str, changed);
        }
    };
    auto f2 = [&v]()
    {
        for (const std::string &str : v)
        {
            std::string changed = str;
            changed[49] = 'A';
            changed[48] = 'B';
            isOneChange1(str, changed);
        }
    };

    std::cerr << "isOneChange strings with some changes runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "isOneChange1 strings with some changes runtime=" << profiler<>::duration(f2).count() << "ms\n";
}