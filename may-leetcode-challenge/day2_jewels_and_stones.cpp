/** 
Title :  Jewels and Stones
Link  :  https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/
Idea  :  Used set to store each jewel, then iterate through stones and count if any stone is present in set
Time Complexity : O(J+S)
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> m;
        for(int i=0;i<S.length();i++){
            m[S[i]]++;
        }
        int c=0;
        for(int i=0;i<J.length();i++){
            c+=m[J[i]];
        }
        return c;
    }
};