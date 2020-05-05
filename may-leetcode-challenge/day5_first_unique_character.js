/** 
Title :  First Unique Character in a String
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/
Idea  :  Storing frequency of all characters of string in a hashmap and checking if frequency of any element is 1
Time Complexity : O(N) 
*/

/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    var chars=new Map();
    for(let i=0;i<s.length;i++){
        let val = chars.has(s[i]) ? chars.get(s[i]) : 0;
        chars.set(s[i], val + 1);
    }
    for(let i=0;i<s.length;i++){
        if(chars.get(s[i])==1 )
            return i
    }
    return -1;
};