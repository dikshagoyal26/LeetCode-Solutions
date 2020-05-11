/** 
Title :  Flood Fill
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/
Idea  :  Stored the starting color, flood fill it , and using DFS checked if adjacent colors are similar to starting color then flood filled them and checked for next adjacent ones and so on.
Time Complexity : O(n) 
*/

class Solution
{
public:
    void fill(vector<vector<int>> &image, int x, int y, int oldColor, int newColor)
    {
        if (image[x][y] != oldColor)
            return;
        image[x][y] = newColor;
        if (x + 1 < image.size())
            fill(image, x + 1, y, oldColor, newColor);
        if (x - 1 >= 0)
            fill(image, x - 1, y, oldColor, newColor);
        if (y + 1 < image[0].size())
            fill(image, x, y + 1, oldColor, newColor);
        if (y - 1 >= 0)
            fill(image, x, y - 1, oldColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image.size() == 0 || image[sr][sc] == newColor)
            return image;
        int oldColor = image[sr][sc];
        fill(image, sr, sc, oldColor, newColor);
        return image;
    }
};