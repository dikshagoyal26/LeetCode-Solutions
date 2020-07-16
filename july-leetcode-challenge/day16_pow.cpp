/** 
Title :   Pow(x, n)
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3392/
Idea  :   Recursion
Time Complexity : O(n) 
*/
/** 
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:
Input: 2.00000, 10
Output: 1024.00000
*/
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 1)
            return x;
        if (n == 0)
            return 1;
        if (n < 0)
            return 1 / (x * myPow(x, abs(n) - 1));
        return n % 2 == 0 ? myPow(x * x, n / 2) : x * myPow(x, n - 1);
    }
};