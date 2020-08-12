/** 
Title :   Pascal's Triangle II
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3421/
Idea  :   Iterating 1 to rowIndex and creating the cur vector, replacing it to return vector
Time Complexity : O(n)
*/
/*
    Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
    Note that the row index starts from 0.
    In Pascal's triangle, each number is the sum of the two numbers directly above it.

    Example:
    Input: 3
    Output: [1,3,3,1]
    Follow up:
    Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret{1}, cur{1};
        for (int i = 1; i <= rowIndex; i++)
        {
            ret.push_back(1);
            for (int j = 1; j < i; j++)
            {
                ret[j] = cur[j] + cur[j - 1];
            }
            cur = ret;
        }
        return ret;
    }
};