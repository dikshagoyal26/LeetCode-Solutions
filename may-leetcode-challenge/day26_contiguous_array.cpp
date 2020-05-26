/** 
Title :   Contiguous Array
Link  :   https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3341/
Idea  :   Considering 0 as -1 and taking sum of elements if at any point sum is zero then its because all the elements before that have equal number of ones and zeros, also to check in between subarrays length a hashmap is created and if at any point the key is already present in hashmap then it means in between both there is equal number of zeros and ones.
Time Complexity : O(n)
*/
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int curr_sum = 0;
        int maxlen = 0;
        unordered_map<int, int> countMap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                curr_sum += -1;
            }
            else
                curr_sum += 1;
            if (curr_sum == 0)
            {
                maxlen = i + 1;
            }
            else if (countMap.find(curr_sum) != countMap.end())
            {
                maxlen = max(maxlen, i - countMap[curr_sum]);
            }
            else
            {
                countMap[curr_sum] = i;
            }
        }
        return maxlen;
    }
};