/** 
Title :  First Unique Character in a String
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/
Idea  :  Storing frequency of all characters of string in a hashmap and checking if frequency of any element is 1
Time Complexity : O(N) 
*/

class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> m;
        for (int i = 0; i < s.length(); i++)
            m[s[i]]++;
        for (int i = 0; i < s.length(); i++)
        {
            if (m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};