#include "zero_matrix.h"
#include "utils.h"

#include <bitset>

void nullifyRow(std::vector<std::vector<int>> &matrix, int row)
{
    for (int j = 0; j < matrix[0].size(); ++j)
    {
        matrix[row][j] = 0;
    }
}

void nullifyCol(std::vector<std::vector<int>> &matrix, int col)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        matrix[i][col] = 0;
    }
}

void nullifyMatrix1(std::vector<std::vector<int>> &matrix)
{
    const size_t columnSize = matrix.size();
    const size_t rowSize = matrix[0].size();
    std::vector<int> columnToNulify(columnSize, 0);

    for (size_t i = 0; i != columnSize; ++i)
    {
        for (size_t j = 0; j != rowSize; ++j)
        {
            if (matrix[i][j] == 0)
            {
                ++columnToNulify[i];
                matrix[i].assign(rowSize, 0);
                break;
            }
        }
    }
    for (size_t i = 0; i != columnToNulify.size(); ++i)
    {
        if (columnToNulify[i])
            nullifyCol(matrix, i);
    }
}

//Fastest - without creating any additional arrays
void nullifyMatrix2(std::vector<std::vector<int>> &matrix)
{
    int M = matrix.size();
    int N = matrix[0].size();
    bool firstRow = false;

    // first row
    for (int i = 0; i < N; ++i)
    {
        if (matrix[0][i] == 0)
        {
            firstRow = true;
            break;
        }
    }

    // rest of the matrix
    for (int i = 1; i < M; ++i)
    {
        bool nullifyThisRow = false;
        for (int j = 0; j < N; ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                nullifyThisRow = true;
            }
        }
        if (nullifyThisRow)
            nullifyRow(matrix, i);
    }
    // now we know which column to be nullify using information stored in previous step.
    // cols first
    for (int j = 0; j < N; ++j)
    {
        if (matrix[0][j] == 0)
        {
            nullifyCol(matrix, j);
        }
    }

    // now first row
    if (firstRow)
    {
        nullifyRow(matrix, 0);
    }
}