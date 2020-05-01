/** 
Title :   First Bad Version
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/
Idea : Simple Binary Search to find the required Number
*/

/**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
           let l=1,r=n,mid;
            while(l<r){
                mid=l+Math.floor((r-l)/2);
                if(isBadVersion(mid)){
                    r=mid;
                } else{
                    l=mid+1;
                }
            }
        return l;
    };
};