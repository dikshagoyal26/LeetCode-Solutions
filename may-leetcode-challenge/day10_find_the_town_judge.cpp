/** 
Title :  Find the Town Judge
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/
Idea  :  Storing the count a person trust others and no of people trust the person in a two dimensional vector and then checking if any person trust no other person but is trusted by all others or not
Time Complexity : O(n) 
*/
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<vector<int>> a(N + 1, vector<int>(N + 1, 0));
        for (int i = 0; i < trust.size(); i++)
        {
            a[trust[i][1]][1]++;
            a[trust[i][0]][0]++;
        }
        for (int i = 1; i <= N; i++)
        {
            if (a[i][1] == N - 1 && a[i][0] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};