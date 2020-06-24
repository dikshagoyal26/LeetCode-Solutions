/** 
Title :   Unique Binary Search Trees
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3370/
Idea  :   Dynamic Programming
Time Complexity : O(n)
*/
/**
    Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n? 
*/
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += (dp[i - j - 1] * dp[j]);
            }
        }
        return dp[n];
    }
};