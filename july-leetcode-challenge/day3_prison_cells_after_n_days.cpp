/** 
Title :   Prison Cells After N Days
Link  :   https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/
Idea  :   This is a pattern repeating problem.This pattern repeats for every 14 days, if we take out day 0 from the pattern.Day 0 never repeats beacuse of corners allways become zero.calculate cells for one day.From here everything repeats. Since I advanced by one day so i will subtract one day from N days. The days needs to be calculated are (N - 1) % 14*
Time Complexity : O(n)
*/
/**
    There are 8 prison cells in a row, and each cell is either occupied or vacant.
    Each day, whether the cell is occupied or vacant changes according to the following rules:
    If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
    Otherwise, it becomes vacant.
    (Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)
    We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.
    Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)
    Input: cells = [0,1,0,1,1,0,0,1], N = 7
    Output: [0,0,1,1,0,0,0,0]
    Explanation: 
    The following table summarizes the state of the prison on each day:
    Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
    Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
    Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
    Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
    Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
    Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
    Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
    Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
*/
class Solution
{

public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        if (N == 0)
            return cells;
        prison(cells, 1);
        prison(cells, (N - 1) % 14);
        return cells;
    }
    void prison(vector<int> &cells, const int &N)
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> v(8, 0);
            for (int i = 1; i < 7; i++)
                if (cells[i - 1] == cells[i + 1])
                    v[i] = 1;
                else
                    v[i] = 0;
            cells = v;
        }
    }
};