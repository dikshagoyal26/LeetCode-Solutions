/** 
Title :   Add Binary
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3395/
Idea  :   Normal COmputation from end
Time Complexity : O(n) 
*/
/**
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0 && a[i--] == '1')
                ++carry;
            if (j >= 0 && b[j--] == '1')
                ++carry;
            result.insert(0, 1, carry % 2 == 1 ? '1' : '0');
            carry /= 2;
        }

        return result;
    }
};