/** 
Title :   Queue Reconstruction by Height
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3352/
Idea  :   Sorting the persons array on the basis of heights and then placing the person at the required index k
Time Complexity : O(n*n)
*/
/**
    Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

    Note:
    The number of people is less than 1,100.
    
    Example
    Input:
    [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    Output:
    [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]] 
 */
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> result;

        for (auto &v : people)
        {
            v[0] = -v[0]; //used instead of using passing a custom comparator in sort()
        }
        sort(people.begin(), people.end());

        for (auto &v : people)
        {
            v[0] = -v[0]; //turning it back to positive
            result.insert(result.begin() + v[1], v);
        }
        return result;
    }
};