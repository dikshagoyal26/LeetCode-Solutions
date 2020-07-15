/** 
Title :   Reverse Words in a String
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3391/
Idea  :   Storing the words in stack and poping them out
Time Complexity : O(1) 
*/

/**
Given an input string, reverse the string word by word.

Example 1:
Input: "the sky is blue"
Output: "blue is sky the"
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        int pos = 0;
        string res;

        while (pos < s.length())
        {
            int end, start;

            while (s[pos] == ' ' && pos < s.length())
                pos++;

            start = pos;

            while (s[pos] != ' ' && pos < s.length())
                pos++;

            end = pos;

            if (end == start)
                break;

            st.push(s.substr(start, end - start));
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
            if (!st.empty())
                res += " ";
        }

        return res;
    }
};