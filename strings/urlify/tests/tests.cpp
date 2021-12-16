#include "urlify.h"
#include "profile.h"

#include "gtest/gtest.h"

#include <random>

class ReplaceWhitespaceTest : public ::testing::Test
{
protected:
    std::string str1{"Hello world!"};
    std::string str2{"Hello"};
    const std::string expected1{"Hello%20world!"};
};

std::string random_string(size_t length)
{
    auto randchar = []() -> char
    {
        constexpr char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ "
            "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}

constexpr size_t CONTAINER_SIZE = 100000;

class SpeedTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        v.reserve(CONTAINER_SIZE);
        for (size_t i = 0; i != CONTAINER_SIZE; ++i)
            v.push_back(random_string(1000));
    }
    std::vector<std::string> v;
};

TEST_F(ReplaceWhitespaceTest, Test2)
{
    replaceWhitespace2(str1);
    replaceWhitespace2(str2);
    EXPECT_EQ(str1, expected1);
    EXPECT_EQ(str2, str2);
}
TEST_F(ReplaceWhitespaceTest, Test3)
{
    replaceWhitespace3(str1);
    replaceWhitespace3(str2);
    EXPECT_EQ(str1, expected1);
    EXPECT_EQ(str2, str2);
}
TEST_F(ReplaceWhitespaceTest, Test4)
{
    replaceWhitespace4(str1);
    replaceWhitespace4(str2);
    EXPECT_EQ(str1, expected1);
    EXPECT_EQ(str2, str2);
}
TEST_F(ReplaceWhitespaceTest, Test5)
{
    replaceWhitespace5(str1);
    replaceWhitespace5(str2);
    EXPECT_EQ(str1, expected1);
    EXPECT_EQ(str2, str2);
}

// Very slow
// TEST_F(SpeedTest, replaceWhitespace2)
// {
//     auto f = [this]()
//     {
//         for (auto &s : v)
//             replaceWhitespace2(s);
//     };
//     std::cerr << "replaceWhitespace2 runtime=" << profiler<>::duration(f).count() << "ms\n";
// }
TEST_F(SpeedTest, replaceWhitespace3)
{
    auto f = [this]()
    {
        for (auto &s : v)
            replaceWhitespace3(s);
    };
    std::cerr << "replaceWhitespace3 runtime=" << profiler<>::duration(f).count() << "ms\n";
}

TEST_F(SpeedTest, replaceWhitespace4)
{
    auto f = [this]()
    {
        for (auto &s : v)
            replaceWhitespace4(s);
    };
    std::cerr << "replaceWhitespace4 runtime=" << profiler<>::duration(f).count() << "ms\n";
}

TEST_F(SpeedTest, replaceWhitespace5)
{
    auto f = [this]()
    {
        for (auto &s : v)
            replaceWhitespace5(s);
    };
    std::cerr << "replaceWhitespace5 runtime=" << profiler<>::duration(f).count() << "ms\n";
}