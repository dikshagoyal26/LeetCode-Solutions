/** 
Title :   Find the Duplicate Number
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3371/
Idea  :   Hashmap of type boolean to check if the value has appeared already or not
Time Complexity : O(n)
*/
/**
    Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number,find the duplicate one.
    Example 1:
    Input: [1,3,4,2,2]
    Output: 2

    Example 2:
    Input: [3,1,3,4,2]
    Output: 3
    
*/
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        bool a[n];
        for (int i = 0; i < n; i++)
            a[i] = false;
        for (int i = 0; i < n; i++)
        {
            if (a[nums[i] - 1])
            {
                return nums[i];
            }
            else
            {
                a[nums[i] - 1] = true;
            }
        }
        return -1;
    }
};