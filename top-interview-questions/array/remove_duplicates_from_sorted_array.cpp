/** 
Title :  Remove Duplicates from Sorted Array
Link  :  https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
Approach  :  Once an element is encountered, bypass its duplicates and move on to the next unique element.
Time Complexity : O(n)
*/


class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[c++] = nums[i];
            while (i < nums.size() - 1 && nums[i + 1] == nums[i])
            {
                i++;
            }
        }
        return c;
    }
};