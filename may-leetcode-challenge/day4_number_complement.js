/** 
Title :  Number Complement
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/
Idea  :  Bit Manipulation
Time Complexity : O(N) where N is number of digits
*/

/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function (num) {
    if (num == 0) return 1;
    var copy = num;
    var i = 0;

    while (copy != 0) {
        copy >>= 1;
        num ^= (1 << i);
        i += 1;
    }
    return num;
};
