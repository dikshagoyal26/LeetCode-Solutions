/** 
Title :   Subsets
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3387/
Idea  :   Backtrack
Time Complexity : O(n*2^n)
*/
/** 
    Given a set of distinct integers, nums, return all possible subsets (the power set).
    Note: The solution set must not contain duplicate subsets.

    Example:
    Input: nums = [1,2,3]
    Output:
    [
    [3],
    [1],
    [2],
    [1,2,3],
    [1,3],
    [2,3],
    [1,2],
    []
    ]
*/

class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int> >& res, vector<int>& subset,int index){
        res.push_back(subset); 
        for (int i = index; i <nums.size(); i++) { 
            subset.push_back(nums[i]); 
            backtrack(nums, res, subset, i + 1); 
            subset.pop_back(); 
        } 
        return; 
    }
    vector<vector<int>> compute(vector<int>& nums){
        vector<int> subset; 
        vector<vector<int> > res; 
        int index = 0; 
        backtrack(nums, res, subset, index); 
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res = compute(nums); 
        return res;
    }
};