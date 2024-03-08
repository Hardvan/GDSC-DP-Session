#include <bits/stdc++.h>

using namespace std;

// * dp array is initialized with -1 as:
// vector<int> dp(n + 1, -1);

// ? 1) Memoization (Top Down)
// Direction: main problem to subproblem
// Time: O(n)
// Space: O(n) (dp array) + O(n) (recursion stack)
int fun(int n, vector<int> &dp)
{
    // Base case
    if (n <= 1)
        return n;

    // Lookup
    if (dp[n] != -1)
        return dp[n];

    // Compute, store and return
    return dp[n] = fun(n - 1, dp) + fun(n - 2, dp);
}

int fib(int n)
{
    vector<int> dp(n + 1, -1); // dp[i] = fib(i)
    return fun(n, dp);
}

// ? 2) Tabulation (Bottom Up)
// Direction: subproblem to main problem
// Time: O(n)
// Space: O(n) (for dp array)
int fib2(int n)
{
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// ? 3) Space Optimized Tabulation
// Time: O(n)
// Space: O(1) (no dp array)
int fib3(int n)
{
    // Base case
    if (n <= 1)
        return n;

    int first = 0;
    int second = 1;
    int third;
    for (int i = 2; i <= n; i++)
    {
        third = first + second;
        first = second;
        second = third;
    }

    return second; // OR return third;
}

int main()
{
    int n = 10;

    cout << fib(n) << endl;
    cout << fib2(n) << endl;
    cout << fib3(n) << endl;
    cout << "Expected: 55\n";

    return 0;
}
