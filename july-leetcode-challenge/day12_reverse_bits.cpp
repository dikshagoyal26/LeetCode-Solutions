/** 
Title :   Reverse Bits
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3388/
Idea  :   Bits
Time Complexity : O(n) 
*/
/**
Reverse bits of a given 32 bits unsigned integer.

Example 1:
Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
*/

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;
        int power = 31;
        while (n > 0)
        {
            int bit = n & 1;
            result += bit << power;
            n = n >> 1;
            power--;
        }

        return result;
    }
};