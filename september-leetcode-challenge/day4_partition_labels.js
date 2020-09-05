/**
Title :   Partition Labels
Link  :   https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3448/
Idea  :   Greedy
Time Complexity : O(n)
*/
/*
    A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

    Example 1:
    Input: S = "ababcbacadefegdehijhklij"
    Output: [9,7,8]
    Explanation:
    The partition is "ababcbaca", "defegde", "hijhklij".
    This is a partition so that each letter appears in at most one part.
    A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
    
    Note:
    S will have length in range [1, 500].
    S will consist of lowercase English letters ('a' to 'z') only.
*/
/**
 * @param {string} S
 * @return {number[]}
 */
var partitionLabels = function (S) {
    var last = {}
    for (let i = 0; i < S.length; ++i) {
        let idx = S[i].charCodeAt() - 97;
        last[idx] = i;
        // console.log(last)
    }

    let j = 0, anchor = 0;
    let ans = []
    for (let i = 0; i < S.length; ++i) {
        let idx = S[i].charCodeAt() - 97;
        j = Math.max(j, last[idx]);
        if (i == j) {
            ans.push(i - anchor + 1);
            anchor = i + 1;
        }
    }
    return ans;
};