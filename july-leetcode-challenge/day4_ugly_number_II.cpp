/** 
Title :   Ugly Number II
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3380/
Idea  :   Using dp and generating n ugly numbers
Time Complexity : O(n)
*/
/**
    Write a program to find the n-th ugly number.
    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

    Example:
    Input: n = 10
    Output: 12
    Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

    Note:  
    1 is typically treated as an ugly number.
    n does not exceed 1690. 
*/

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int mult2 = 2, mult3 = 3, mult5 = 5;
        for (int i = 1; i < n; i++)
        {
            int m = min(min(mult2, mult3), mult5);
            dp[i] = m;
            if (m == mult2)
            {
                i2++;
                mult2 = dp[i2] * 2;
            }
            if (m == mult3)
            {
                i3++;
                mult3 = dp[i3] * 3;
            }
            if (m == mult5)
            {
                i5++;
                mult5 = dp[i5] * 5;
            }
        }
        return dp[n - 1];
    }
};