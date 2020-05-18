/** 
Title :  Permutation in String
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/
Idea  :  Took two arrays, one for string s1 and another for s2, and traversing and checking if they are equal at certain point or not
Time Complexity : O(n) 
*/
class Solution
{
public:
    bool matches(int a[], int b[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string S1, string S2)
    {
        int m = S2.length(), n = S1.length();
        if (m < 1 || n < 1 || m < n)
            return false;
        int map_s1[26] = {0}, map_s2[26] = {0};
        int k = 0, i = 0, j = 0;
        for (j = 0; j < n; j++)
        {
            map_s1[S1[j] - 'a']++;
            map_s2[S2[j] - 'a']++;
        }
        if (matches(map_s2, map_s1))
        {
            return true;
        }
        for (i = n; i < m; i++)
        {
            map_s2[S2[k++] - 'a']--;
            map_s2[S2[i] - 'a']++;
            if (matches(map_s2, map_s1))
            {
                return true;
            }
        }
        return false;
    }
};