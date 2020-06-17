/** 
Title :   Surrounded Regions
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3363/
Idea  :   DFS
Time Complexity : O(n*n)
*/
/**
    Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
    A region is captured by flipping all 'O's into 'X's in that surrounded region.

    Explanation:
    Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
 */
class Solution
{
public:
    void dfs(vector<vector<char>> &board, int x, int y, int row, intcol)
    {
        if (x < 0 || x >= row || y < 0 || y >= col)
            return;

        board[x][y] = '1';
        if (x - 1 > 0 && board[x - 1][y] == 'O')
            dfs(board, x - 1, y, row, col);
        if (x + 1 < row && board[x + 1][y] == 'O')
            dfs(board, x + 1, y, row, col);
        if (y - 1 > 0 && board[x][y - 1] == 'O')
            dfs(board, x, y - 1, row, col);
        if (y + 1 < col && board[x][y + 1] == 'O')
            dfs(board, x, y + 1, row, col);
    }
    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        if (row < 1)
            return;
        int col = board[0].size();
        if (row <= 1 || col <= 1)
        {
            return;
        }

        for (int i = 0; i < row; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0, row, col);
            if (board[i][col - 1] == 'O')
                dfs(board, i, col - 1, row, col);
        }
        for (int i = 0; i < col; i++)
        {
            if (board[0][i] == 'O')
                dfs(board, 0, i, row, col);
            if (board[row - 1][i] == 'O')
                dfs(board, row - 1, i, row, col);
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                board[i][j] = board[i][j] == '1' ? 'O' : 'X';
            }
        }
    }
};
