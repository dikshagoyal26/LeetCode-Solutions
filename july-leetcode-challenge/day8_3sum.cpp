/** 
Title :   3 Sum
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3384/
Idea  :   Sorting and three pointer approach
Time Complexity : O(n*n)
*/
/** 
    Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
    Note:
    The solution set must not contain duplicate triplets.
    Example:
    Given array nums = [-1, 0, 1, 2, -1, -4],
    A solution set is:
    [
    [-1, 0, 1],
    [-1, -1, 2]
    ]
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < int(nums.size()) - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int sum = 0 - nums[i];
                int low = i + 1;
                int high = nums.size() - 1;

                while (low < high)
                {
                    if (nums[low] + nums[high] == sum)
                    {
                        ans.push_back(vector<int>{nums[i], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;

                        low++;
                        high--;
                    }
                    else if (nums[low] + nums[high] > sum)
                        high--;
                    else
                        low++;
                }
            }
        }
        return ans;
    }
};