/** 
Title :   Sort Array By Parity
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3431/
Idea  :   Swapping
Time Complexity : O(n)
*/
/*
    Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
    You may return any answer array that satisfies this condition.

    Example 1:
    Input: [3,1,2,4]
    Output: [2,4,3,1]
    The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
    
    Note:
    1 <= A.length <= 5000
    0 <= A[i] <= 5000
*/

/**
 * @param {number[]} A
 * @return {number[]}
 */

/* APPROACH 1 */
var sortArrayByParity = function (A) {
    var len = A.length, temp;

    for (var i = 0, j = len - 1; i < j; ++i) {
        if (A[i] % 2 !== 0) {
            while (j > i) {
                if (A[j] % 2 === 0) {
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    --j;
                    break;
                }
                --j;
            }
        }
    }
    return A;
};

/* APPROACH 2 */
var sortArrayByParity = function (A) {
    let j = 0;

    for (let i = 0; i < A.length; i++) {
        if (!(A[i] % 2)) [A[i], A[j++]] = [A[j], A[i]]
    }
    return A;
};