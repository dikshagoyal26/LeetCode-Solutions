/**
Title :   Contains Duplicate III
Link  :   https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3446/
Idea :    Sorting
Time Complexity : O(nlogk)
*/
/*
    Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

    Example 1:
    Input: nums = [1,2,3,1], k = 3, t = 0
    Output: true
   
    Example 2:
    Input: nums = [1,0,1,1], k = 1, t = 2
    Output: true
    
    Example 3:
    Input: nums = [1,5,9,1,5,9], k = 2, t = 3
    Output: false
*/
/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
/** Approach: 1 */
var containsNearbyAlmostDuplicate = function (nums, k, t) {
    for (i = 0; i <= nums.length; i++) {
        for (j = i + 1; j <= i + k; j++) {
            if (Math.abs(nums[i] - nums[j]) <= t) return true;
        }
    }
    return false;
};
/** Approach: 2 */
var containsNearbyAlmostDuplicate = function (nums, k, t) {
    if (!nums || nums.length < 2) return false;
    var indices = [nums.length];
    for (i = 0; i < nums.length; ++i) {
        indices[i] = i;
    }
    indices = indices.sort(function (a, b) {
        return nums[a] - nums[b];
    });
    var i, j;
    for (i = 0; i < nums.length - 1; ++i) {
        for (j = i + 1; j < nums.length; ++j) {
            if (nums[indices[j]] - nums[indices[i]] > t) break;
            if (Math.abs(indices[j] - indices[i]) <= k) return true;
        }
    }
    return false
};