/** 
Title :   Possible Bipartition
Link  :   https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3342/
Idea  :   BFS
Time Complexity : O(N+M) where M is length of dislikes
*/

class Solution
{
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> adjacent(N + 1); // to keep a track of dislikes for each value btw 0 to N
        vector<int> randomValue(N + 1, 0); //initial zero, 1 or -1 later on randomly
        vector<bool> visited(N + 1, false); // to check if any value is already visited or not
        for (auto val : dislikes) // if dislikes [[1,2],[2,3]] adjacent [[][2][1,3][2]]
        {
            adjacent[val[0]].push_back(val[1]);
            adjacent[val[1]].push_back(val[0]);
        }
        queue<int> temp_queue; //for BFS traversal
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                randomValue[i] = 1; //randomly assigned the value to 1
                temp_queue.push(i);
                while (!temp_queue.empty())
                {
                    int peekVal = temp_queue.front();
                    temp_queue.pop();
                    if (visited[peekVal])
                        continue;
                    visited[peekVal] = true;
                    for (auto val : adjacent[peekVal])
                    {
                        if (randomValue[val] == randomValue[peekVal])
                            return false;
                        randomValue[val] = randomValue[peekVal] == 1 ? -1 : 1;
                        temp_queue.push(val);
                    }
                }
            }
        }
        return true;
    }
};