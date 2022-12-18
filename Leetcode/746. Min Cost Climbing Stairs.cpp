
// https://leetcode.com/problems/min-cost-climbing-stairs/description/
// Both Memoization and Tabulation Done here
class Solution {
public:
    int find(vector<int>& cost, int idx, int n, vector<int> &dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int one = cost[idx] + find(cost, idx+1, n, dp);
        int two = cost[idx] + find(cost, idx+2, n, dp);
        return dp[idx] = min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1);
        // return min(find(cost,0, n, dp), find(cost,1, n, dp));
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; ++i){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};