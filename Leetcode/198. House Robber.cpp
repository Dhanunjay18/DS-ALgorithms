
// https://leetcode.com/problems/house-robber/description/

class Solution {
    vector<int> dp;
public:
    int find(vector<int> &nums, int idx) {
        if(idx>=nums.size()) {
            return 0;     
        }
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = nums[idx] + max(find(nums, idx+2), find(nums,idx+3));
    }
    int rob(vector<int>& nums) {
        dp.resize(101, -1);
        // Using Recursion and Memoization
        // int ans1 = find(nums, 0);
        // int ans2 = find(nums, 1);
        // return max(ans1, ans2); 



        // Tabulation Method         
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        for(int i=3; i<n; ++i) {
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        }
        return max(dp[n-1], dp[n-2]);
    }
};