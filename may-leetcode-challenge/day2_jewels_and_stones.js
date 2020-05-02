/** 
Title :  Jewels and Stones
Link  :  https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/
Idea  :  Used set to store each jewel, then iterate through stones and count if any stone is present in set
Time Complexity : O(J+S)
*/

/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    var jewels = new Set(J);
    var numJewels = 0;
    for (var i = 0; i < S.length; i++) {
        if (jewels.has(S.charAt(i))) numJewels++;
    }
    return numJewels;
};