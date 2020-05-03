/** 
Title :  Best Time to Buy and Sell Stock II
Link  :  https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
Approach :  Simple One Pass
Time Complexity : O(n)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
                maxp+=prices[i]-prices[i-1];
        }
        return maxp;
    }
};