/**
Title :   Image Overlap
Link  :   https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3450/
Idea  :   Shift And Count
Time Complexity : O(n^4)
*/
/*
    Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)
    We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.
    (Note also that a translation does not include any kind of rotation.)

    What is the largest possible overlap?
    Example 1:
    Input: A = [[1,1,0],
                [0,1,0],
                [0,1,0]]
        B = [[0,0,0],
                [0,1,1],
                [0,0,1]]
    Output: 3
    Explanation: We slide A to right by 1 unit and down by 1 unit.
    Notes: 
    1 <= A.length = A[0].length = B.length = B[0].length <= 30
    0 <= A[i][j], B[i][j] <= 1
*/
/**
 * @param {number[][]} A
 * @param {number[][]} B
 * @return {number}
 */
var largestOverlap = function (A, B) {
    const length = A.length;
    let max = 0;
    for (let rowOffset = -length; rowOffset < length; rowOffset++) {
        for (let colOffset = -length; colOffset < length; colOffset++) {
            max = Math.max(max, getOverlap(rowOffset, colOffset));
        }
    }
    return max;


    function getOverlap(rowOffset, colOffset) {
        let res = 0;

        for (let i = 0; i < length; i++) {
            let offsetI = i + rowOffset;
            if (offsetI < 0 || offsetI >= length)
                continue;

            for (let j = 0; j < length; j++) {

                let offsetJ = j + colOffset

                if (offsetJ < 0 || offsetJ >= length) continue;

                if (A[offsetI][offsetJ] == B[i][j])
                    res += A[offsetI][offsetJ];

            }
        }

        return res;
    }
};