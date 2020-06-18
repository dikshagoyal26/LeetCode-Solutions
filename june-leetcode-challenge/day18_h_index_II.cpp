/** 
Title :   H-Index II
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3364/
Idea  :   Binary Search
Time Complexity : O(logn)
*/
/**
    Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
    According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

    Example:
    Input: citations = [0,1,3,5,6]
    Output: 3 
    Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
                received 0, 1, 3, 5, 6 citations respectively. 
                Since the researcher has 3 papers with at least 3 citations each and the remaining 
                two with no more than 3 citations each, her h-index is 3.
    Note:
    If there are several possible values for h, the maximum one is taken as the h-index. 
*/

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int left = 0;
        int size = citations.size();
        int right = size - 1;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (citations[mid] == size - mid)
            {
                return citations[mid];
            }
            else if (citations[mid] >= size - mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return size - left;
    }
};