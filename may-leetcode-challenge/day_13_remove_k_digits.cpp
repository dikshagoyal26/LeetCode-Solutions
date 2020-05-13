/** 
Title :  Remove K Digits
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/
Idea  :  As long as enough elements are present in string ans, and last element of ans is greater than current element of num, pop it to guarantee that nxt element is smaller than previous one
Time Complexity : O(nk) 
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k >= num.length())
        {
            return "0";
        }
        if (k == 0)
        {
            return num;
        }
        string ans = "";
        for (int i = 0; i < num.size(); i++)
        {
            while (!ans.empty() && ans.back() > num[i] && k > 0)
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }
        while (k > 0)
        {
            ans.pop_back();
            k--;
        }
        int s = 0;
        while (s < ans.size())
        {
            if (ans[s] != '0')
            {
                break;
            }
            s++;
        }
        if (s > 0)
        {
            ans = ans.substr(s, num.size() - k);
            if (ans.length() > 0)
            {
                return ans;
            }
            return "0";
        }
        return ans;
    }
};