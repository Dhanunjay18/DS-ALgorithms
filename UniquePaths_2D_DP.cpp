#include <bits/stdc++.h> 

// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

// https://leetcode.com/problems/unique-paths/submissions/866391940/

vector<vector<int>> dp;
int find(int i, int j) {
    if(i==0 and j==0) return 1;
    if(i<0 or j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = find(i-1, j);
    int left = find(i, j-1);
    return dp[i][j]=up + left;
}
// MEMOIZATION TO TABULATION
/*
    1 -> Do hardcode on base cases i.e, assign direct values.
    2 -> Express all states in for loops with the edge cases.
    3 -> Copy the recurence and Write
*/
int uniquePaths(int m, int n) {
    dp.clear();
    dp.resize(m, vector<int>(n));    
	dp[0][0] = 1;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(i==0 and j==0) continue;
            else{
                int up = 0, left = 0;
                if(i-1 >= 0) up = dp[i-1][j];
                if(j-1 >= 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}