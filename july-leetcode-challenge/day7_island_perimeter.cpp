/** 
Title :   Island Perimeter
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3383/
Idea  :   Iterating and checking for borders if borders have land then increase the count accordingly
Time Complexity : O(n*m)
*/

/** 
    You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
    Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
    The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

    Example:
    Input:
    [[0,1,0,0],
    [1,1,1,0],
    [0,1,0,0],
    [1,1,0,0]]
    Output: 16
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
           int mx = grid[0].size() - 1, my = grid.size() - 1, res = 0;
        for (int y = 0; y <= my; y++) {
            for (int x = 0; x <= mx; x++) {
                if (grid[y][x] == 1) res += !x + !y + (mx == x) + (my == y);
                else res += (x && grid[y][x - 1]) + (y && grid[y - 1][x]) + (x < mx && grid[y][x + 1]) + (y < my && grid[y + 1][x]);
            }
        }
        return res;
    }
};