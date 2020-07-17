/** 
Title :   Top K Frequent Elements
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/
Idea  :   Hashmap and Min heap
Time Complexity : O(nlogn) 
*/
/**
Given a non-empty array of integers, return the k most frequent elements.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/
class Solution
{
public:
    struct comp
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (k == nums.size())
        {
            return nums;
        }
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq(mp.begin(), mp.end());
        while (k)
        {
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ans;
    }
};