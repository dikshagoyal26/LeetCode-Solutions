/** 
Title :  Ransom Note
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/
Idea  :  Used map to keep count of different characters in both ransomNote and magazine, then iterate through note map and check if all its keys are present in magazine with value atleast equal to the value in note.
Time Complexity : O(R+M)
*/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> magMap;
        for (int i = 0; i < magazine.length(); i++)
        {
            magMap[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (magMap[ransomNote[i]] > 0)
            {
                magMap[ransomNote[i]]--;
            }
            else
                return false;
        }
        return true;
    }
};