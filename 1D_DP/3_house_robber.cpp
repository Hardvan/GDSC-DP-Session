#include <bits/stdc++.h>

using namespace std;

/*
Problem Statement:
A thief needs to rob money in a street.
The houses in the street are arranged in a circular manner.
Therefore the first and the last house are adjacent to each other.
The security system in the street is such that
if adjacent houses are robbed, the police will get notified.

Given an array of integers "arr" which represents money at each house.
Return the max amount of money that the thief can rob without alerting the police.
*/

/*
Observations:
The problem can be solved by using the approach discussed in 4_max_sum_of_non_adjacent_elements.cpp.
*/

/*
Approach:
Make 2 reduced arrays: arr1 (w/o last element) and arr2 (w/o first element).
Find the max sum of non-adjacent elements arr1 and arr2 separately.
Return max(ans1, ans2)
*/

int maxSumNonAdj(int n, vector<int> &arr)
{
    vector<int> dp(n, -1); // 0 to n-1

    dp[0] = arr[0];             // Base Case (Only 1 element)
    for (int i = 1; i < n; i++) // 1 to n-1
    {
        int notPick = dp[i - 1];

        int pick = arr[i];
        if (i >= 2)
            pick += dp[i - 2];

        dp[i] = max(pick, notPick);
    }

    return dp[n - 1];
}

// Time: O(n)
// Space: O(n)
int robStreet(int n, vector<int> &arr)
{
    if (n == 1) // Only 1 house
        return arr[0];

    // Reduced Arrays
    vector<int> arr1(arr.begin(), arr.end() - 1); // w/o last element
    vector<int> arr2(arr.begin() + 1, arr.end()); // w/o first element

    // Find the max sum of non-adjacent elements arr1 and arr2 separately
    int ans1 = maxSumNonAdj(n - 1, arr1);
    int ans2 = maxSumNonAdj(n - 1, arr2);
    return max(ans1, ans2);
}

int main()
{
    vector<int> arr{1, 5, 1, 2, 6};
    int n = arr.size();

    cout << "Max amount of money that the thief can rob without alerting the police:" << endl;
    cout << robStreet(n, arr) << endl; // 11
    cout << "Expected: 11\n";

    return 0;
}
