#include <bits/stdc++.h>

using namespace std;

/*
Problem Statement:
Given a no. of stairs and a frog.
The frog wants to climb from the 0th stair to the (N-1)th stair.

At a time the frog can climb either one or two steps.

A height[N] array is also given.
Whenever the frog jumps from a stair i to stair j,
the energy consumed in the jump is abs(height[i] - height[j]),
where abs() means the absolute difference.

Return the min energy that can be used by the frog to jump from stair 0 to stair N-1.
*/

// * Memoization Approach
// Time: O(n)
// Space: O(n)

// Helper function for memoization
int fun(int ind, vector<int> &height, vector<int> &dp)
{
    // Base Case
    if (ind == 0) // 0th stair
        return 0;

    // Lookup
    if (dp[ind] != -1)
        return dp[ind];

    // Recursive Case

    // Energy to reach current stair from 1 stair before
    int jump1 = abs(height[ind] - height[ind - 1]) + fun(ind - 1, height, dp);

    // Energy to reach current stair from 2 stairs before
    int jump2 = INT_MAX;
    if (ind >= 2) // valid index
        jump2 = abs(height[ind] - height[ind - 2]) + fun(ind - 2, height, dp);

    return dp[ind] = min(jump1, jump2);
}

int minEnergy(int n, vector<int> &height)
{
    vector<int> dp(n, -1); // 0 to n-1 stair
    return fun(n - 1, height, dp);
}

// * Tabulation Approach
// Time: O(n)
// Space: O(n)
int minEnergy2(int n, vector<int> &height)
{
    vector<int> dp(n, -1); // 0 to n-1 stair

    dp[0] = 0;                  // 0th stair
    for (int i = 1; i < n; i++) // 1 to n-1
    {
        int jump1 = abs(height[i] - height[i - 1]) + dp[i - 1];
        int jump2 = INT_MAX;
        if (i >= 2)
            jump2 = abs(height[i] - height[i - 2]) + dp[i - 2];

        dp[i] = min(jump1, jump2);
    }

    return dp[n - 1];
}

// * Space Optimized
// Time: O(n)
// Space: O(1)
int minEnergy3(int n, vector<int> &height)
{
    int first = 0;
    int second = 0;
    for (int i = 1; i < n; i++) // 1 to n-1
    {
        int jump1 = abs(height[i] - height[i - 1]) + second;
        int jump2 = INT_MAX;
        if (i >= 2)
            jump2 = abs(height[i] - height[i - 2]) + first;

        first = second;
        second = min(jump1, jump2);
    }

    return second;
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();

    cout << minEnergy(n, height) << endl;  // 40
    cout << minEnergy2(n, height) << endl; // 40
    cout << minEnergy3(n, height) << endl; // 40
    cout << "Expected: 40\n";

    return 0;
}
