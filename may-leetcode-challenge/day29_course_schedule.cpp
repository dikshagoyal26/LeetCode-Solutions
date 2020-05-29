/** 
Title :   Course Schedule
Link  :   https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/
Idea  :   BFS using topological sort 
Time Complexity : O(N+M) where M is length of prerequisites
*/
class Solution
{
public:
    bool dfsCycle(int curr, vector<bool> &visited, vector<bool> &rec_stack, vector<vector<int>> &graph)
    {
        visited[curr] = true;
        rec_stack[curr] = true;
        for (int i = 0; i < graph[curr].size(); i++)
        {
            if (rec_stack[graph[curr][i]])
                return true;
            if (dfsCycle(graph[curr][i], visited, rec_stack, graph))
                return true;
        }
        rec_stack[curr] = false;
        return false;
    }

    bool DFS(int numCourses, vector<vector<int>> &graph)
    {
        vector<bool> visited(numCourses, false);
        vector<bool> rec_stack(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfsCycle(i, visited, rec_stack, graph))
                return false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (numCourses < 3 && prerequisites.size() == 1)
        {
            return true;
        }
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        return DFS(numCourses, graph);
    }
};