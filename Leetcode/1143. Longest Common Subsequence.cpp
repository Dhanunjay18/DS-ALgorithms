

// https://leetcode.com/problems/longest-common-subsequence/description/

// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Studied at : Jenny Lectures
        int n = text1.size();
        int m = text2.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m));
        string s = "";
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                // IF THE CHARS AT I AND J FOR TEXT1 AND TEXT2 ARE EQUAL THEN CURRENT VALUE WILL BE DP[I][J] = DP[I-1][J-1] + 1;
                // BASICALLY INCREASING THE DIAGONAL VALUE AND ASSIGNING IT TO THE CURRENT POSITION
                if(text1[i]==text2[j]) {
                    s += text1[i];
                    if(i==0 or j==0) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j-1] + 1;
                } 
                else  { // The chars are not equal 
                    // Then we should assign the dp[i][j] to max of its top and left values i.e, dp[i][j] = max(top, left).
                    if(i==0 and j==0) dp[i][j] = 0;
                    else if(i==0) dp[i][j] = dp[i][j-1];
                    else if(j==0) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);  // max(left, top)
                }
            }
        }
        cout << s << endl;
        return dp[n-1][m-1];
    }
};