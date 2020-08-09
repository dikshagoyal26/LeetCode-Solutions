/** 
Title :   Rotting Oranges
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3418/
Idea  :   DFS
Time Complexity : O(n)
*/
/*
    In a given grid, each cell can have one of three values:
    the value 0 representing an empty cell;
    the value 1 representing a fresh orange;
    the value 2 representing a rotten orange.
    Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
    Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

    Example 1:
    Input: [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4

    Example 2:
    Input: [[2,1,1],[0,1,1],[1,0,1]]
    Output: -1
    Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

    Example 3:
    Input: [[0,2]]
    Output: 0
    Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
    
    Note:
    1 <= grid.length <= 10
    1 <= grid[0].length <= 10
    grid[i][j] is only 0, 1, or 2.
*/
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    fresh++;
            }
        int ans = -1;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int r = p.first + dir[i];
                    int c = p.second + dir[i + 1];
                    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        q.push({r, c});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if (fresh > 0)
            return -1;
        if (ans == -1)
            return 0;
        return ans;
    }
};