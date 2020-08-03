/** 
Title :   Valid Palindrome  
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3411/
Idea  :   two pointer
Time Complexity : O(n)
*/
/*
    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
    Note: For the purpose of this problem, we define empty string as valid palindrome.

    Example 1:
    Input: "A man, a plan, a canal: Panama"
    Output: true

    Example 2:
    Input: "race a car"
    Output: false
    
    Constraints:
    s consists only of printable ASCII characters.
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (!isalnum(s[i]) && i < s.size())
                i++;
            while (!isalnum(s[j]) && j)
                j--;
            if (tolower(s[i++]) != tolower(s[j--]))
                return i > s.size();
        }
        return true;
    }
};