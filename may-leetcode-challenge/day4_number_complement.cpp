/** 
Title :  Number Complement
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/
Idea  :  Bit Manipulation
Time Complexity : O(N) where N is number of digits
*/

class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
            return 1;
        int copy = num;
        int i = 0;

        while (copy != 0)
        {
            copy >>= 1;
            num ^= (1 << i);
            i += 1;
        }
        return num;
    }
};