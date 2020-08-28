/**
Title :   Implement Rand10() Using Rand7()
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3439/
Idea  :   Math
Steps :  1. Determine if the result will be in the range 1 ... 5 or the range 6 ..  10. With rand7() we have equal odds of getting a number < 4 and getting a number > 4. If the number is 4, we can just roll again.
        2. If the number is < 4, we will pick a random number in 1 ... 5 so set offset = 0. If the number is > 4, we will pick a random number in 6 ... 10 so set offset = 5
        3. Pick a random number in 1 ... 5 with equal probability. Just use rand7() repeatedly until you get a number in the range 1 ... 5.
        4. Return offset + num
Time Complexity : O(1)
*/
/*
    Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.
    Do NOT use system's Math.random().

    Example 1:
    Input: 1
    Output: [7]

    Example 2:
    Input: 2
    Output: [8,4]

    Example 3:
    Input: 3
    Output: [8,1,10]
    
    Note:
    rand7 is predefined.
    Each testcase has one argument: n, the number of times that rand10 is called.
    
    Follow up:
    What is the expected value for the number of calls to rand7() function?
    Could you minimize the number of calls to rand7()?
*/
/**
 * The rand7() API is already defined for you.
 * var rand7 = function() {}
 * @return {number} a random integer in the range 1 to 7
 */
var rand10 = function () {
    var num = rand7()
    while (num == 4) {
        num = rand7()
    }

    var offset = num < 4 ? 0 : 5
    num = rand7()
    while (num > 5) {
        num = rand7()
    }
    return offset + num
};