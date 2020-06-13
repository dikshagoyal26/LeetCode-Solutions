/** 
Title :   Largest Divisible Subset
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3359/
Idea  :   Dynamic Programming
Time Complexity : O(n*n)
*/
/**
    Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
    Si % Sj = 0 or Sj % Si = 0.
    If there are multiple solutions, return any subset is fine.

    Example 1:
    Input: [1,2,3]
    Output: [1,2] (of course, [1,3] will also be ok)
    
    Example 2:
    Input: [1,2,4,8]
    Output: [1,2,4,8]
 */
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return nums;
        }
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> ans;
        vector<int> parent(nums.size());
        parent[0] = 0;
        int countMax = 1;
        int ansIndex = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int val = 0;
            int num = nums[i];
            parent[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (num % nums[j] == 0)
                {
                    if (val < dp[j])
                    {
                        val = dp[j];
                        parent[i] = j;
                        if (countMax < val + 1)
                        {
                            countMax = val + 1;
                            ansIndex = i;
                        }
                    }
                }
            }
            dp[i] = val + 1;
        }
        for (int i = 0; i < countMax; i++)
        {
            ans.push_back(nums[ansIndex]);
            ansIndex = parent[ansIndex];
        }
        return ans;
    }
};