/** 
Title :  Count Square Submatrices with All Ones
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/
Idea  :  Dynamic Programming
Time Complexity : O(mn) 
*/
class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int result = 0;
        int m = matrix.size();
        if (m < 1)
            return 0;
        int n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j];
                else if (matrix[i][j] == 1)
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
                result += dp[i][j];
            }
        }
        return result;
    }
};