/** 
Title :   Dungeon Game
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3367/
Idea  :   Dynamic Programming
Time Complexity : O(m*n)
*/

/**
    The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
    The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
    Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
    In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
    Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
*/
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size();
        if (m == 0)
            return 0;
        int n = dungeon[0].size();
        if (n == 0)
            return 0;
        int roomVal;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    dungeon[i][j] = dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];
                    continue;
                }
                else if (i == m - 1)
                {
                    roomVal = dungeon[i][j + 1];
                }
                else if (j == n - 1)
                {
                    roomVal = dungeon[i + 1][j];
                }
                else
                {
                    roomVal = min(dungeon[i][j + 1], dungeon[i + 1][j]);
                }
                if (dungeon[i][j] >= 0)
                {
                    dungeon[i][j] = dungeon[i][j] >= roomVal ? 1 : roomVal - dungeon[i][j];
                }
                else
                {
                    dungeon[i][j] = roomVal - dungeon[i][j];
                }
            }
        }
        return dungeon[0][0];
    }
};