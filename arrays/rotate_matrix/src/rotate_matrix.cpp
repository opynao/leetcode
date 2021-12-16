#include "rotate_matrix.h"
#include "utils.h"

void helper_transpose(std::vector<std::vector<int>> &matrix, int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (i != j)
                std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void helper_reverse(std::vector<int> &row, int N)
{
    for (int i = 0; i < N / 2; ++i)
        std::swap(row[i], row[N - i - 1]);
}

void rotate1(std::vector<std::vector<int>> &matrix)
{
    size_t N = matrix.size();
    // transpose matrix
    helper_transpose(matrix, N);
    // reverse each row
    for (int i = 0; i < N; ++i)
        helper_reverse(matrix[i], N);
}

void rotate2(std::vector<std::vector<int>> &matrix)
{
    size_t N = matrix.size();
    for (int i = 0; i < N / 2; ++i)
    {
        for (int j = i; j < N - i - 1; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][N - i - 1];
            matrix[j][N - i - 1] = matrix[N - i - 1][N - j - 1];
            matrix[N - i - 1][N - j - 1] = matrix[N - j - 1][i];
            matrix[N - j - 1][i] = temp;
        }
    }
}