/** 
Title :  Best Time to Buy and Sell Stock II
Link  :  https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
Approach : Reverse
Time Complexity : O(n)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0||k==nums.size()) return;
        reverse(nums.begin(),nums.end());
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};