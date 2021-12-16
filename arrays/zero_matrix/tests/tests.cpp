#include "zero_matrix.h"
#include "utils.h"
#include "profile.h"

#include "gtest/gtest.h"

#include <iostream>
#include <cctype>
#include <random>

class NullifyMatrixTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }
    std::vector<std::vector<int>> v{
        {0, 1, 2, 3},
        {1, 2, 3, 4},
        {5, 6, 7, 8}};
    std::vector<std::vector<int>> expected{
        {0, 0, 0, 0},
        {0, 2, 3, 4},
        {0, 6, 7, 8}};
};

TEST_F(NullifyMatrixTest, Correctness1)
{
    nullifyMatrix1(v);
    EXPECT_EQ(v, expected);
}

TEST_F(NullifyMatrixTest, Correctness2)
{
    nullifyMatrix2(v);
    EXPECT_EQ(v, expected);
}

std::vector<std::vector<int>> generateMatrix(size_t rowSize, size_t columnSize)
{
    using u32 = uint_least32_t;
    using engine = std::mt19937;

    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(0, 100);

    std::vector<std::vector<int>> matrix(columnSize);
    for (size_t j = 0; j != columnSize; ++j)
    {
        std::vector<int> row(rowSize);

        for (size_t i = 0; i != rowSize; ++i)
            row[i] = distribute(generator);

        matrix.push_back(std::move(row));
    }
    return matrix;
}

void PrintMatrix(const std::vector<std::vector<int>> &matrix)
{
    for (size_t j = 0; j != matrix.size(); ++j)
    {
        for (size_t i = 0; i != matrix[j].size(); ++i)
        {
            PR(i);
            PR(matrix[j][i]);
        }
        std::cerr << std::endl;
    }
}

using matrix_t = std::vector<std::vector<int>>;
constexpr size_t MATRIX_COUNT = 20000;

TEST(Speed, Test)
{
    std::vector<matrix_t> v;
    v.reserve(MATRIX_COUNT);
    for (size_t i = 0; i != MATRIX_COUNT; ++i)
        v.push_back(generateMatrix(100, 100));

    auto f1 = [&v]()
    {
        for (auto &m : v)
            nullifyMatrix1(m);
    };
    auto f2 = [&v]()
    {
        for (auto &m : v)
            nullifyMatrix2(m);
    };
    std::cerr << "nullifyMatrix1 runtime=" << profiler<>::duration(f1).count() << "ms\n";
    std::cerr << "nullifyMatrix2 runtime=" << profiler<>::duration(f2).count() << "ms\n";
}