/** 
Title :   Perfect Squares
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3373/
Idea  :   Maths Legendre's theorem 
Time Complexity : O(n)
*/
/**
    Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

    Example 1:
    Input: n = 12
    Output: 3 
    Explanation: 12 = 4 + 4 + 4.
    
    Example 2:
    Input: n = 13
    Output: 2
    Explanation: 13 = 4 + 9. 
*/

class Solution
{
public:
    int numSquares(int n)
    {
        while ((n & 3) == 0)
        {
            n >>= 2;
        }
        if ((n & 7) == 7)
            return 4;
        if (n < 4)
            return n;
        int end = sqrt(n);
        if (end * end == n)
            return 1;
        for (int i = 1; i <= end; ++i)
        {
            int remain = n - i * i;
            int possible = sqrt(remain);
            if (possible * possible == remain)
                return 2;
        }
        return 3;
    }
};