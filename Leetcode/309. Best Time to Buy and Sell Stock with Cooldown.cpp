
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
    vector<vector<int>> dp;
    int find(int idx, int buy, vector<int> prices) {
        if(idx>=prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy==1) {
            return dp[idx][buy] = max(find(idx+1, 0, prices)-prices[idx], find(idx+1, 1, prices));
        }
        return dp[idx][buy] = max(find(idx+2, 1, prices)+prices[idx], find(idx+1, 0, prices));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1, vector<int>(2, -1));
        return find(0, 1, prices); //{idx, buy, prices};   
    }
};