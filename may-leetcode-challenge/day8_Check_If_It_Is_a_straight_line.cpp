/** 
Title :  Check If It Is a Straight Line
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/
Idea  :  Check for slope of line formed by each point with first point is equal to slope of line formed by first two points or not by cross product method
Time Complexity : O(N) 
*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<3) return true;
        int y=coordinates[0][1]-coordinates[1][1];
        int x=coordinates[0][0]-coordinates[1][0];
        for(int i=2;i<coordinates.size();i++)
        {
            if(x*(coordinates[0][1]-coordinates[i][1])!=y*(coordinates[0][0]-coordinates[i][0]))
                return false;
        }
        return true;
    }
};