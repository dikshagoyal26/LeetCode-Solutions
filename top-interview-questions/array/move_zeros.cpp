/** 
Title :  Move Zeros
Link  :  https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/
Approach : two pointer
Time Complexity : O(n)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[c++]=nums[i];
            }
        }
        while(c<nums.size()){
            nums[c++]=0;

        }
    }
};