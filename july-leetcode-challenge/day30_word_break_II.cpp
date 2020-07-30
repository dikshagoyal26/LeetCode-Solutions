/** 
Title :   Word Break II
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3406/
Idea  :   Dynamic Programming
Time Complexity : O(n*n) 
*/
/**
    Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
    Note:
    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.
    
    Example 1:
    Input:
    s = "catsanddog"
    wordDict = ["cat", "cats", "and", "sand", "dog"]
    Output:
    [
    "cats and dog",
    "cat sand dog"
    ]

    Example 2:
    Input:
    s = "pineapplepenapple"
    wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    Output:
    [
    "pine apple pen apple",
    "pineapple pen apple",
    "pine applepen apple"
    ]
    Explanation: Note that you are allowed to reuse a dictionary word.
    
    Example 3:
    Input:
    s = "catsandog"
    wordDict = ["cats", "dog", "sand", "and", "cat"]
    Output:
    []
*/

class Solution
{
public:
    unordered_map<string, vector<string>> dp;
    vector<string> ff(string s, unordered_set<string> &word_dict)
    {
        vector<string> res;
        if (dp.find(s) != dp.end())
            return dp[s];

        for (int i = 1; i <= s.size(); i++)
        {
            if (word_dict.find(s.substr(0, i)) != word_dict.end())
            {
                if (s.substr(i).length() == 0)
                {
                    res.push_back(s.substr(0, i));
                }
                else
                {
                    vector<string> subList = ff(s.substr(i), word_dict);
                    for (auto sub : subList)
                        res.push_back(s.substr(0, i) + " " + sub);
                }
            }
        }

        return dp[s] = res;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> word_dict(wordDict.begin(), wordDict.end());
        return ff(s, word_dict);
    }
};