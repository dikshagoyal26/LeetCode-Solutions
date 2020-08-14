/** 
Title :   Longest Palindrome
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3423/
Idea  :   Greedy
Time Complexity : O(n)
*/
/*
    Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
    This is case sensitive, for example "Aa" is not considered a palindrome here.
    Note:
    Assume the length of given string will not exceed 1,010.

    Example:
    Input:
    "abccccdd"
    Output:
    7
    Explanation:
    One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
        }
        for (auto x : map)
        {
            ans += x.second / 2 * 2;
            if (x.second % 2 == 1 && ans % 2 == 0)
                ans++;
        }
        return ans;
    }
};