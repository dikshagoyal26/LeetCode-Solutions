/** 
Title :   Reverse String
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3350/
Idea  :   Two pointers
Time Complexity : O(n) to swap n/2 characters
*/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        if (n < 2)
            return;
        int i = 0, j = n - 1;
        while (i < j)
        {
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;
            j--;
            i++;
        }
        return;
    }
};