/** 
Title :   Unique Paths
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/543/week-5-june-29th-june-30th/3375/
Idea  :   Dynamic Programming
Time Complexity : O(nm)
*/
/**
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
    The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
    How many possible unique paths are there? 

    Example 1:
    Input: m = 3, n = 2
    Output: 3
    Explanation:
    From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Right -> Down
    2. Right -> Down -> Right
    3. Down -> Right -> Right
    
    Example 2:
    Input: m = 7, n = 3
    Output: 28
*/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[j] = dp[j - 1] + dp[j];
        return dp[n - 1];
        // vector<vector<int>> dp(m, vector<int>(n, 1));
        // for (int i = 1; i < m; i++)
        //     for (int j = 1; j < n; j++)
        //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        // return dp[m - 1][n - 1];
    }
};