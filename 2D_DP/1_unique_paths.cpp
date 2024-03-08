#include <bits/stdc++.h>

using namespace std;

/*
Problem Statement:
Given two values M and N, which represent a matrix[M][N].
Find the total unique paths
from the top-left cell (matrix[0][0])
to the rightmost cell (matrix[M-1][N-1]).

At any cell we are allowed to move in only two directions:- bottom and right.
*/

/*
Approach:
Make a 2D dp array of size MxN.
dp[i][j] = total unique paths from the top-left cell to the cell (i, j).
*/

// * Memoization
// Time: O(mn)
// Space: O(mn) (dp array) + O(m+n) (recursion stack)

// Helper function for memoization
int fun(int i, int j, vector<vector<int>> &dp)
{
    // Base Cases
    if (i == 0 && j == 0) // top-left cell
        return 1;
    if (i < 0 || j < 0) // out of bounds
        return 0;

    // Lookup
    if (dp[i][j] != -1)
        return dp[i][j];

    // Recursive Case

    // Move up
    int up = fun(i - 1, j, dp);

    // Move left
    int left = fun(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int uniquePaths(int m, int n)
{
    // rows: index (0 to m-1), cols: index (0 to n-1)
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return fun(m - 1, n - 1, dp);
}

// * Tabulation
// Time: O(mn)
// Space: O(mn)
int uniquePaths2(int m, int n)
{
    // rows: index (0 to m-1), cols: index (0 to n-1)
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) // rows
    {
        for (int j = 0; j < n; j++) // cols
        {
            if (i == 0 && j == 0) // top-left cell
            {
                dp[i][j] = 1;
                continue;
            }

            // Move up
            int up = 0;
            if (i > 0)
                up = dp[i - 1][j];

            // Move left
            int left = 0;
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

// * Space Optimized
// Time: O(mn)
// Space: O(n)
int uniquePaths3(int m, int n)
{
    // cols: index (0 to n-1)
    vector<int> dp(n, 0);

    for (int i = 0; i < m; i++) // rows
    {
        for (int j = 0; j < n; j++) // cols
        {
            if (i == 0 && j == 0) // top-left cell
            {
                dp[j] = 1;
                continue;
            }

            // Move up
            int up = 0;
            if (i > 0)
                up = dp[j];

            // Move left
            int left = 0;
            if (j > 0)
                left = dp[j - 1];

            dp[j] = up + left;
        }
    }

    return dp[n - 1];
}

int main()
{
    int m = 3, n = 3;

    cout << "Total unique paths from the top-left cell (" << 0 << ", " << 0 << ") "
         << "to the rightmost cell (" << m - 1 << ", " << n - 1 << "):" << endl;
    cout << uniquePaths(m, n) << endl;  // 6
    cout << uniquePaths2(m, n) << endl; // 6
    cout << uniquePaths3(m, n) << endl; // 6
    cout << "Expected: 6\n";

    return 0;
}
