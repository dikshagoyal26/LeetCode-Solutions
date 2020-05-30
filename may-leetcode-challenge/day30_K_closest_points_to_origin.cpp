/** 
Title :  K Closest Points to Origin
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3345/
Idea  :  Storing distances in the form of pair in max heap for size k and then iterating it
Time Complexity : O(nlogk) 
*/
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int> > &points, int K)
    {
        if (points.size() == 1)
        {
            return points;
        }
        vector<vector<int>> res;
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < points.size(); i++)
        {
            int d = ((points[i][0]) * (points[i][0])) + ((points[i][1]) * (points[i][1]));
            if (i < K)
            {
                maxHeap.push({d, i});
            }
            else
            {
                if (maxHeap.top().first > d)
                {
                    maxHeap.pop();
                    maxHeap.push({d, i});
                }
            }
        }
        while (!maxHeap.empty())
        {
            res.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return res;
    }
};
