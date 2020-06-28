/** 
Title :   Reconstruct Itinerary
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3374/
Idea  :   Graph DFS
Time Complexity : O(nlogn)
*/
/**
    Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
    Note:
    If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    All airports are represented by three capital letters (IATA code).
    You may assume all tickets form at least one valid itinerary.
    One must use all the tickets once and only once.

    Example 1:
    Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

    Example 2:
    Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
    Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
    But it is larger in lexical order.
**/
class Solution {
public:
      void find(map<string,vector<string>> &adj,string curr,vector<string> &res)
    {    
        
        for(int i=0;i<adj[curr].size();i++)
        {
            string x=adj[curr][i];
            adj[curr].erase(adj[curr].begin()+i);i--;
            find(adj,x,res);
        }
        res.push_back(curr);
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        int l=tickets.size();
        map<string,vector<string>> adj; 
        for(int i=0;i<l;i++)
         adj[tickets[i][0]].push_back(tickets[i][1]); 
        for(auto x=adj.begin();x!=adj.end();x++)
          sort(x->second.begin(),x->second.end());
        
        find(adj,"JFK",res);
        reverse(res.begin(),res.end());
        return res;
    }
};