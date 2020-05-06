/** 
Title :  Majority Element
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/
Idea  :  Creating a count a storing the element, if count is zero then updating the count with curr element and then checking if majElement is equal to curr element then increment the count else decrement it
Time Complexity : O(N) 
*/
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    var count = 0;
    var majElement;
    for (let i = 0; i < nums.length; i++) {
        if (count == 0) {
            majElement = nums[i];
        }
        count += (majElement == nums[i]) ? 1 : -1;
    }
    return majElement;
};