/** 
Title :  Maximum Sum Circular Subarray
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3330/
Idea  :  Finding the maxsum using kadane for straight array and circular array and returning the maximum of both
Time Complexity : O(n) 
*/

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int total_sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            total_sum += A[i];
        }
        int temp_sum = INT_MIN;
        int max_subarray_sum = INT_MIN;
        for (int i = 0; i < A.size(); i++)
        {
            temp_sum = A[i] + max(temp_sum, 0);
            max_subarray_sum = max(max_subarray_sum, temp_sum);
        }
        temp_sum = INT_MAX;
        int min_subarray_sum = INT_MAX;
        for (int i = 0; i < A.size(); i++)
        {
            temp_sum = A[i] + min(temp_sum, 0);
            min_subarray_sum = min(temp_sum, min_subarray_sum);
        }
        if (total_sum == min_subarray_sum)
            return max_subarray_sum;
        int max_circular_sum = total_sum - min_subarray_sum;
        return max(max_subarray_sum, max_circular_sum);
    }
};