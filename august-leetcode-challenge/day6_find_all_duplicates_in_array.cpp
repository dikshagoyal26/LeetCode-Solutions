/** 
Title :   Find All Duplicates in an Array
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3414/
Idea  :   Iterate and convert numbers at that index to negative and when the value at particular index becomes positive, then that number has occured twice.
Time Complexity : O(n)
*/
/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[2,3]
*/
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &n)
    {
        vector<int> duplicates;

        for (int i = 0; i < n.size(); i++)
        {
            int indexOfElem = abs(n[i]) - 1;
            n[indexOfElem] = -n[indexOfElem];
            if (n[indexOfElem] > 0)
                duplicates.push_back(indexOfElem + 1);
        }
        return duplicates;
    }
};