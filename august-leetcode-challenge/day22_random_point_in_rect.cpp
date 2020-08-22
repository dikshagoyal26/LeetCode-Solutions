/** 
Title :   Random Point in Non-overlapping Rectangles
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3433/
Idea  :   Randomize
Time Complexity : O(n)
*/

/*
    Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.
    Note:
    An integer point is a point that has integer coordinates. 
    A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
    ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
    length and width of each rectangle does not exceed 2000.
    1 <= rects.length <= 100
    pick return a point as an array of integer coordinates [p_x, p_y]
    pick is called at most 10000 times.
    
    Example 1:
    Input: 
    ["Solution","pick","pick","pick"]
    [[[[1,1,5,5]]],[],[],[]]
    Output: 
    [null,[4,1],[4,1],[3,3]]
    
    Example 2:
    Input: 
    ["Solution","pick","pick","pick","pick","pick"]
    [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
    Output: 
    [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
    Explanation of Input Syntax:
    The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array of rectangles rects. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.

*/
class Solution
{
public:
    vector<int> cumulativeAreas;
    vector<vector<int>> rs;

    int getArea(vector<int> &r)
    {
        return (r[3] - r[1] + 1) * (r[2] - r[0] + 1);
    }

    int randint(int a, int b)
    {
        // random number from a to b, both included
        return rand() % (b - a + 1) + a;
    }

    vector<int> getRandomPoint(vector<int> r)
    {
        return {randint(r[0], r[2]), randint(r[1], r[3])};
    }

    Solution(vector<vector<int>> &rects)
    {
        // sending rand
        srand(time(NULL));
        // storing rects and rects data
        rs = rects;
        // populating cumulativeAreas
        cumulativeAreas.resize(rs.size());
        cumulativeAreas[0] = getArea(rs[0]);
        for (int i = 1; i < rs.size(); i++)
            cumulativeAreas[i] = cumulativeAreas[i - 1] + getArea(rs[i]);
    }

    vector<int> pick()
    {
        int currRect = upper_bound(begin(cumulativeAreas), end(cumulativeAreas), rand() % cumulativeAreas.back()) - begin(cumulativeAreas);
        return getRandomPoint(rs[currRect]);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */