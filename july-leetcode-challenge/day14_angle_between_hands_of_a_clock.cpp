/** 
Title :   Angle Between Hands of a Clock
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3390/
Idea  :   Maths
Time Complexity : O(1) 
*/
/** 
    Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

    Example 1:
    Input: hour = 12, minutes = 30
    Output: 165

*/

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double minutesAngle = (360 / 60) * minutes;
        double hoursAngle = (360 / 12) * (hour % 12);
        hoursAngle += (360 / 12) * (minutes / 60.0); // minutes for adding to hours
        double angle = abs(minutesAngle - hoursAngle);
        return min(angle, 360 - angle);
    }
};