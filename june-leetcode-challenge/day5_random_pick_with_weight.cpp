/** 
Title :   Random Pick with Weight
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3351/
Idea  :   Cumulative Distribution and taking a random number and returning its index
Time Complexity : O(n) could have been O(logn) with inary search though
*/
/** Question:
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
*/

class Solution
{
public:
    vector<int> cdf;
    Solution(vector<int> &w)
    {
        cdf.push_back(w[0]);
        for (int i = 1; i < w.size(); i++)
        {
            cdf.push_back(cdf[i - 1] + w[i]);
        }
    }

    int pickIndex()
    {
        int n = rand() % cdf[cdf.size() - 1];
        auto it = upper_bound(cdf.begin(), cdf.end(), n);
        return it - cdf.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */