/** 
Title :   Largest Time for Given Digits
Link  :   https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3445/
Idea :    Backtracking
Time Complexity : O(1)
*/
/*
    Given an array of 4 digits, return the largest 24 hour time that can be made.
    The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.
    Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

    Example 1:
    Input: [1,2,3,4]
    Output: "23:41"
    
    Example 2:
    Input: [5,5,5,5]
    Output: ""
    
    Note:
    A.length == 4
    0 <= A[i] <= 9
*/

/**
 * @param {number[]} A
 * @return {string}
 */
var largestTimeFromDigits = function (A) {
    const n = A.length;
    let largest = -1;
    const visited = new Array(n).fill(false);

    find_perms([]);

    if (largest == -1) return "";

    return convert_to_str(largest);

    function find_perms(arr) {
        if (arr.length == n) {
            if (isValid(arr)) {
                const time = convert_to_mins(arr);
                largest = Math.max(time, largest);
            }
            return;
        }

        for (let i = 0; i < n; i++) {
            if (visited[i] == true) continue;

            visited[i] = true;
            arr.push(A[i]);
            find_perms(arr);
            arr.pop();
            visited[i] = false;
        }

    }

    function isValid(arr) {
        if (arr[0] > 2 || (arr[0] == 2 && arr[1] > 3) || arr[2] > 5) return false;
        return true;
    }

    function convert_to_mins(arr) {
        return (arr[0] * 600) + (arr[1] * 60) + (arr[2] * 10) + arr[3];
    }

    function convert_to_str(mins) {
        const hr1 = Math.floor(mins / 600);
        mins %= 600;
        const hr2 = Math.floor(mins / 60);
        mins %= 60;
        const min1 = Math.floor(mins / 10);
        mins %= 10;
        const min2 = mins;

        return `${hr1}${hr2}:${min1}${min2}`;
    }
}