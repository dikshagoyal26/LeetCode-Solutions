/** 
Title :   Course Schedule II
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3394/
Idea  :   When using the normal DFS method, it fails a lot times when there is a cycle in the graph. Here we use hashset to check cycle when we go through DFS.
Time Complexity : O(n) 
*/
/**
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1] .

Example 2:
Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

*/
class Solution
{
public:
    vector<vector<int>> clist;
    vector<int> ans;
    unordered_set<int> vis;
    unordered_set<int> cyc;
    bool isCycle = false;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        clist.assign(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) //build pre course list
        {
            clist[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int j = 0; j < numCourses; j++)
        {
            if (vis.count(j) < 1)
                dfs(j);
            if (isCycle)
                return vector<int>();
        }
        return ans;
    }
    void dfs(int j)
    {
        cyc.insert(j);
        vis.insert(j);
        for (int k = 0; k < clist[j].size(); k++)
        {
            if (cyc.count(clist[j][k]) > 0)
                isCycle = true; //detect cycle at the same time
            if (vis.count(clist[j][k]) < 1)
                dfs(clist[j][k]); //keep dfs
        }
        ans.insert(ans.begin(), j);
        cyc.erase(j);
    }
};