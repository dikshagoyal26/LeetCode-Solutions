/**
Title :   Fizz Buzz
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3437/
Idea  :   Naive Approach
Time Complexity : O(n)
*/
/*
    Write a program that outputs the string representation of numbers from 1 to n.
    But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

    Example:
    n = 15,
    Return:
    [
        "1",
        "2",
        "Fizz",
        "4",
        "Buzz",
        "Fizz",
        "7",
        "8",
        "Fizz",
        "Buzz",
        "11",
        "Fizz",
        "13",
        "14",
        "FizzBuzz"
    ]
*/

/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function (n) {
    let newArr = [];
    for (let i = 1; i <= n; i++) {
        if ((i % 3 !== 0) && (i % 5 !== 0)) {
            newArr.push(i.toString());
        } else if ((i % 3 === 0) && (i % 5 !== 0)) {
            newArr.push("Fizz");
        } else if ((i % 3 !== 0) && (i % 5 === 0)) {
            newArr.push("Buzz");
        } else {
            newArr.push("FizzBuzz");
        }
    }

    return newArr;
};