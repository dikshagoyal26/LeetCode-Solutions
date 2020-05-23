/** 
Title :  Interval List Intersections
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3338/
Idea  :  To find intersation took the maximum of first position in every index vector and minimum of second position in every index of vector B and if fisrt is less then push it in resultant vector
Time Complexity : O(m+n) 
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int m=A.size(),n=B.size();
        if(m<1){
            return A;
        }
        if(n<1){
            return B;
        }
        int i=0,j=0;
        while(i<m&&j<n){
            int x=max(A[i][0],B[j][0]);
            int y=min(A[i][1],B[j][1]);
            if(x<=y){
                ans.push_back({x,y});
            }
            if(A[i][1]<B[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};