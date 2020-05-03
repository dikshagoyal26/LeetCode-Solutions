/*
Title :  Rotate Image
Link  :  https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/
Approach: Transpose of matrix and then reversing each row
Time Complexity : O(n*n)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[i].size();j++){
                int t=matrix[j][i];
                matrix[j][i]=matrix[i][j];
                matrix[i][j]=t;;
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};