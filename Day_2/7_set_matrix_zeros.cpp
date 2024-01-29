#include <bits/stdc++.h>
using namespace std;

// 1st approach
// T.C - O((N*M)*(N + M)) + O(N*M)
// S.C - O(1)
// the markRow and markCol is to change the row and col to -1
void markRow(vector<vector<int>> &matrix, int n, int m, int i)
{
    for (int j = 0; j < n; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}
void markCol(vector<vector<int>> &matrix, int n, int m, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> bruteforce(vector<vector<int>> &matrix, int n, int m)
{
    // iterating in 2d array i.e. matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // while iterating if 0 occurs simply convert that entire row and col to -1 which is not 0 by default
            if (matrix[i][j] == 0)
            {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // change all the marked -1 to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

// 2nd approach
// T.C - O(2*N*M)
// S.C - O(N) + O(M)
vector<vector<int>> better(vector<vector<int>> &matrix, int n, int m)
{
    // create an array for col and row of size n and m
    int col[m] = {0};
    int row[n] = {0};

    // iterate in matrix and if any 0 occurs mark that row and col
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[i] = 1;
            }
        }
    }
    // iterate again in matrix and convert all the marked row and col to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
    // and return matrix
    return matrix;
}

// 3rd approach
// T.C - O(2*(N*M))
// S.C - O(1)
vector<vector<int>> optimal(vector<vector<int>> &matrix, int n, int m)
{
    // col - matrix[0][..]
    // row - matrix[..][0]

    // i -> row & j -> col

    // instead of creating an extra array to track the 0 we will use the matrix row and col. for better space complexity
    int col0 = 1;

    // iterate in matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if we found any 0 in matrix
            if (matrix[i][j] == 0)
            {
                // mark the i-th row
                matrix[i][0] = 0;
                // mark the j-th row
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    // will iterate in matrix again but will skip the 1st row and 1st col
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for row and col if it is marked then convert that row and col to 0
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    // this is for the 1st col and 1st row
    // if the row of 1st index is 0 then convert all the col to 0
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    // is the col of 1st index i.e. col0 is 0 then convert all the row element to 0
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};

    int n = matrix.size();    // row
    int m = matrix[0].size(); // col

    // 1st approach
    vector<vector<int>> ans = bruteforce(matrix, n, m);

    // 2nd approach
    vector<vector<int>> ans = better(matrix, n, m);

    // 3rd approach
    vector<vector<int>> ans = optimal(matrix, n, m);

    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}