/** 
Title :  Single Element in a Sorted Array
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/
Idea  :  Binary Search with a bit modification.
Time Complexity : O(logn) 
*/
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            bool even_length = (r - m) % 2 == 0;
            if (nums[m] == nums[m + 1])
            {
                if (even_length)
                    l = m + 2;
                else
                    r = m - 1;
            }
            else if (nums[m] == nums[m - 1])
            {
                if (even_length)
                    r = m - 2;
                else
                    l = m + 1;
            }
            else
                return nums[m];
        }
        return nums[l];
    }
};
