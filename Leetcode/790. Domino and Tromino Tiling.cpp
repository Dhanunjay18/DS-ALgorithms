
// https://leetcode.com/problems/domino-and-tromino-tiling/

class Solution {
public:
    int numTilings(int n) {
        // using dp
        int m = 1e9 + 7;
        vector<long long> dp(1001, 0);
        dp[1] = 1; // | or -
        dp[2] = 2; // || or =
        dp[3] = 5; // ||| or =| or |= or L7 (and horizontal inverse)
        // dp[4] = 11, dp[5] = 24
        for(int i=4; i<=n; ++i) {
            dp[i] = ((2*dp[i-1]) + dp[i-3]);  
            dp[i] %= m;
        }
        return dp[n];
    }
};