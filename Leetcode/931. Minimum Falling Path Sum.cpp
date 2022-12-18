
// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
        vector<vector<int>>dp;
    int find(int row, int col, int n, vector<vector<int>>& matrix){
        if(row<0 or row==n or col<0 or col==n) return 0; // Should return only when current positon meets last point
        if(dp[row][col]!=-1) return dp[row][col];
        int sum = matrix[row][col];
        if(col==0) sum += min(find(row+1,col+1,n, matrix), find(row+1,col,n, matrix));   // If curr position is at 1st column then we should not go to left coner(i.e, row+1, col-1)
        else if(col==n-1) sum += min(find(row+1,col-1,n, matrix), find(row+1,col,n, matrix));  // If curr position is at last column then we should not go to left coner(i.e, row+1, col+1)
        else sum += min(find(row+1, col-1, n, matrix),min(find(row+1, col+1, n, matrix), find(row+1, col, n, matrix)));
        return dp[row][col] = sum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        dp.resize(300,vector<int>(300,-1));
        int n = matrix.size();
        int sum = INT_MAX;
        for(int i=0; i<n; ++i){
            sum = min(sum,find(0, i, n, matrix));
        }
        return sum;
    }
};