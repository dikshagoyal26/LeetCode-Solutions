/** 
Title :   Counting Bits
Link  :   https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3343/
Idea  :   Dynamic Programming
Time Complexity : O(n)
*/
/**
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
*/
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1, 0);

        for (int i = 1; i < dp.size(); i++)
            dp[i] = i % 2 + dp[i / 2];

        return dp;
    }
};
