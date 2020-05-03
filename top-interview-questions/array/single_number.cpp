/*
Title :  Single Number
Link  :  https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/
Approach: Bit Manipulation because (a⊕0=a) & (a⊕a=0)
Time Complexity : O(n)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (int i=0;i<nums.size();i++) {
            a ^= nums[i];
        }
        return a;
    }
};