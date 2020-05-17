/** 
Title :  Find All Anagrams in a String
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/
Idea  :  Took two hashmaps, one for string s and another for p, and traversing and checking if they are equal at certain point or not
Time Complexity : O(n) 
*/
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int size_s = s.length(), size_n = p.length();
        vector<int> ans;
        if (size_s < 1 || size_n < 1 || size_s < size_n)
            return ans;
        unordered_map<char, int> map_s, map_p;
        int k = 0, i = 0, j = 0;
        for (j = 0; j < size_n; j++)
        {
            map_s[s[j]]++;
            map_p[p[j]]++;
        }
        if (map_s.size() == map_p.size() && map_s == map_p)
        {
            ans.push_back(k);
        }
        for (i = size_n; i < size_s; i++)
        {
            map_s[s[k]]--;
            if (map_s[s[k]] == 0)
            {
                map_s.erase(s[k]);
            }
            k++;
            map_s[s[i]]++;
            if (map_s.size() == map_p.size() && map_s == map_p)
            {
                ans.push_back(k);
            }
        }
        return ans;
    }
};