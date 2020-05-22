/** 
Title :  Sort Characters By Frequency
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/
Idea  :  Storing frequencies in a Hashmap and then storing the frequencies in the form of max heap as it will automatically convert it into descending order by frequency and then reforming the string
Time Complexity : O(nlogn) 
*/
class Solution
{
public:
    string frequencySort(string s)
    {
        if (s.length() < 3)
        {
            return s;
        }
        unordered_map<char, int> frequency;
        for (int i = 0; i < s.length(); i++)
        {
            frequency[s[i]]++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for (auto it : frequency)
        {
            maxHeap.push({it.second, it.first});
        }
        string result = "";
        while (!maxHeap.empty())
        {
            int x = maxHeap.top().first;
            char ch = maxHeap.top().second;
            while (x)
            {
                result += ch;
                x--;
            }
            maxHeap.pop();
        }
        return result;
    }
};