/** 
Title :   Numbers With Same Consecutive Differences
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3428/
Idea  :   Bfs
Time Complexity : O(n*2^n)
*/
/*
    Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.
    Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.
    You may return the answer in any order.

    Example 1:
    Input: N = 3, K = 7
    Output: [181,292,707,818,929]
    Explanation: Note that 070 is not a valid number, because it has leading zeroes.

    Example 2:
    Input: N = 2, K = 1
    Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

    Note:
    1 <= N <= 9
    0 <= K <= 9
*/
class Solution
{
public:
    vector<int> bfs(int N, int K, vector<int> &ans)
    {
        queue<int> q;
        for (int i = 1; i < 10; i++)
        {
            q.push(i);
        }
        int lvl = 1;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                int t1 = q.front();
                q.pop();
                if (lvl == N)
                {
                    ans.push_back(t1);
                    continue;
                }
                int t = t1 % 10;
                int n1 = t - K;
                int n2 = t + K;
                if (n1 >= 0 && n1 < 10)
                {
                    q.push(t1 * 10 + n1);
                }
                if (K != 0 && n2 >= 0 && n2 < 10)
                {
                    q.push(t1 * 10 + n2);
                }
            }
            lvl++;
        }
        return ans;
    }
    vector<int> numsSameConsecDiff(int N, int K)
    {
        vector<int> ans;
        if (N == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
        return bfs(N, K, ans);
    }
};