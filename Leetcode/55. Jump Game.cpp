// https://leetcode.com/problems/jump-game/

class Solution {
    vector<int> dp;
public:
    bool find(vector<int>& nums, int idx) {
        if(idx>=nums.size()-1) return dp[idx] = 1;
        if(dp[idx]!=-1) return dp[idx];
        int k = nums[idx];
        for(int i=1; i<=k; ++i) {
            if(find(nums, idx+i)) return dp[idx] = 1;
        }
        return dp[idx] = 0;
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        return find(nums, 0);
    }
};