/** 
Title :   Power of Two
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/
Idea  :   Bit Manipulation
Time Complexity : O(1)
*/
/**
 * Given an integer, write a function to determine if it is a power of two.
*/

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 1)
            return false;
        if ((n & (n - 1)) == 0)
            return true;

        return false;
    }
};