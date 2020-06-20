/** 
Title :   Permutation Sequence
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3366/
Idea  :   Recursion
Time Complexity : O(n*n)
*/

/**
    The set [1,2,3,...,n] contains a total of n! unique permutations.
    By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
    "123","132","213","231","312","321"
    Given n and k, return the kth permutation sequence.
    Note:
    Given n will be between 1 and 9 inclusive.
    Given k will be between 1 and n! inclusive.
    
    Example 1:
    Input: n = 3, k = 3
    Output: "213"
    
    Example 2:
    Input: n = 4, k = 9
    Output: "2314" 
*/
class Solution
{
public:
    int fact(int n)
    {
        int p = 1;
        for (int i = 2; i <= n; i++)
            p *= i;
        return p;
    }
    string answer(int k, vector<int> v)
    {
        int n = v.size();
        if (n == 0)
            return "";
        int f = fact(n - 1);
        int pos = k / f;
        k %= f;
        string c = to_string(v[pos]);
        v.erase(v.begin() + pos);
        return c + answer(k, v);
    }
    string getPermutation(int n, int k)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        return answer(k - 1, v);
    }
};