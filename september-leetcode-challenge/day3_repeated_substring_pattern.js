/**
Title :   Repeated Substring Pattern
Link  :   https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3447/
Time Complexity : O(n)
*/
/*
    Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

    Example 1:
    Input: "abab"
    Output: True
    Explanation: It's the substring "ab" twice.
    
    Example 2:
    Input: "aba"
    Output: False
    
    Example 3:
    Input: "abcabcabcabc"
    Output: True
    Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
/**
 * @param {string} s
 * @return {boolean}
 */
var repeatedSubstringPattern = function (s) {
    return s.repeat(2).slice(1, -1).includes(s);
};