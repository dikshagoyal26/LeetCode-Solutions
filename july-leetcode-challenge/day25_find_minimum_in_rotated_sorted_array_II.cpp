/** 
Title :   Find Minimum in Rotated Sorted Array II
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3401/
Idea  :   Binary Search
Time Complexity : O(logn) 
*/
/**
    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
   (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
    Find the minimum element.
    The array may contain duplicates.

    Example 1:
    Input: [1,3,5]
    Output: 1

    Example 2:
    Input: [2,2,2,0,1]
    Output: 0

    Note:
    This is a follow up problem to Find Minimum in Rotated Sorted Array.
    Would allow duplicates affect the run-time complexity? How and why?
*/
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        if (nums[low] < nums[high])
            return nums[low];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[high])
                high = mid;
            else if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high--;
        }
        return nums[low];
    }
};
