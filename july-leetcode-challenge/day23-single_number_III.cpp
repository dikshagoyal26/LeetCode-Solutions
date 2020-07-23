/** 
Title :   Single Number III 
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3399/
Idea  :   Bit Manipulation
Time Complexity : O(n) 
*/
/**
    Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

    Example:
    Input:  [1,2,1,3,2,5]
    Output: [3,5]
    
    Note:
    The order of the result is not important. So in the above example, [5, 3] is also correct.
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int sum = 0;
        for (auto num : nums)
        {
            sum ^= num;
        }

        vector<int> res{0, 0};
        int lowbit = sum & (-sum); //way to find lowbit
        for (auto num : nums)
        {
            if (num & lowbit)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};