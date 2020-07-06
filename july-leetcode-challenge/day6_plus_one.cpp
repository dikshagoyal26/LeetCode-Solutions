/** 
Title :   Plus One  
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/
Idea  :   Adding one to last value if its less than 10 then return the array else keep a carry and iterate from last until carry is zero.
Time Complexity : O(n)
*/
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        int size = digits.size();
        if (size == 0)
        {
            digits.push_back(1);
            return digits;
        }
        digits[size - 1] += 1;
        if (digits[size - 1] <= 9)
        {
            return digits;
        }
        for (int i = size - 1; i >= 0; i--)
        {
            int n = digits[i];
            n = n + carry;
            digits[i] = n % 10;
            carry = n / 10;
            if (carry == 0)
                break;
        }
        if (carry > 0)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};