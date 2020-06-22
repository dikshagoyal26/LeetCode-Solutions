/** 
Title :   Single Number II
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3368/
Idea  :   Bit Manipulation
Time Complexity : O(n)
*/
/**
    Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

    Note:
    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/ 
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int high_val = 0, low_val = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            low_val = ~high_val & (low_val ^ nums[i]);
            high_val = ~low_val & (high_val ^ nums[i]);
        }
        return low_val;
    }
};