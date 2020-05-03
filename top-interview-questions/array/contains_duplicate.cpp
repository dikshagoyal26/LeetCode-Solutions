/*
Title :  Contains Duplicate
Link  :  https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/
Approach :  Hash Table
Time Complexity : O(n)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<2) return false;
        unordered_set<int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m.insert(nums[i]);
                continue;
            }
            else
                return true;
        }
        return false;
    }
};