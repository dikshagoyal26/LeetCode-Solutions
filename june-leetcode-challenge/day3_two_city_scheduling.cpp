/** 
Title :   Two City Scheduling
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/
Idea  :   Check for minumum of both for each city and inserting data in a maxheap and then adding cost for each
Time Complexity : O(nlogn) because of priority queue
*/
/**
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.
Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
*/
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        priority_queue<pair<int, int>> pq;
        int n = costs.size();
        for (int i = 0; i < n; i++)
        {
            pq.push(make_pair(costs[i][0] - costs[i][1], i));
        }
        int sum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            sum += costs[pq.top().second][1];
            pq.pop();
        }
        for (int i = 0; i < n / 2; i++)
        {
            sum += costs[pq.top().second][0];
            pq.pop();
        }
        return sum;
        /** Another solution - sorting
            sort(costs.begin(), costs.end(), [&](vector<int> a, vector<int> b) {
                return a[1]-a[0] < b[1]-b[0];
            });
            int n = costs.size()/2;
            int sum=0;
            for(int i=0;i<costs.size()/2;i++){
                sum+=(costs[i][1]+costs[i+costs.size()/2][0]);
            }
            return sum; 
        */     
    }
};