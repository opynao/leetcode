#include "rotate_matrix.h"
#include "utils.h"

#include "gtest/gtest.h"

class RotateTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }
    std::vector<std::vector<int>> matrix{
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3}};
    std::vector<std::vector<int>> rotated1{
        {3, 2, 1, 0},
        {3, 2, 1, 0},
        {3, 2, 1, 0},
        {3, 2, 1, 0}};
    std::vector<std::vector<int>> rotated2{
        {3, 3, 3, 3},
        {2, 2, 2, 2},
        {1, 1, 1, 1},
        {0, 0, 0, 0}};
    std::vector<std::vector<int>> rotated3{
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3}};
};

TEST_F(RotateTest, Correctness_Rotate1)
{
    rotate1(matrix);
    EXPECT_EQ(matrix, rotated1);
    rotate1(matrix);
    EXPECT_EQ(matrix, rotated2);
    rotate1(matrix);
    EXPECT_EQ(matrix, rotated3);
    rotate1(matrix);
}

TEST_F(RotateTest, Correctness_Rotate2)
{
    rotate2(matrix);
    EXPECT_EQ(matrix, rotated1);
    rotate2(matrix);
    EXPECT_EQ(matrix, rotated2);
}