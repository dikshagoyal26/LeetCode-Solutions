/** 
Title :  Two Sum
Link  :  https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
Approach :  One Pass Hash Map
Time Complexity : O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int val=target-nums[i];
            if(m.find(val)!=m.end()){
                return vector<int>{m[val],i};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};