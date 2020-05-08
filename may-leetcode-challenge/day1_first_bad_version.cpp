/** 
Title :   First Bad Version
Link  :   https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/
Idea : Simple Binary Search to find the required Number
Time Complexity : O(logn)
*/


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n,mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(isBadVersion(mid)){
                r=mid;
            } else{
                l=mid+1;
            }
        }
        return l;
    }
};