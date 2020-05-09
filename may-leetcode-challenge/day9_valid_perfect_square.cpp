/** 
Title :  Valid Perfect Square
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/
Idea  :  Using Binary Search find if any number on dividing with given number gives quotient equal to divisor and remainder as zero then its a perfect square
Time Complexity : O(logn) 
*/
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num < 1)
            return false;
        if (num == 1)
            return true;
        int left = 0, right = num, mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            int quo = num / mid;
            if (quo == mid && num % mid == 0)
                return true;
            else if (quo >= mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};