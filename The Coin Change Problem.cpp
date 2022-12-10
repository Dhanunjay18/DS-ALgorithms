#include <bits/stdc++.h>

using namespace std;



// https://www.hackerrank.com/challenges/coin-change/problem

// https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

// https://leetcode.com/problems/coin-change-ii/description/

long solve(int idx, int target, vector<long> x, vector<vector<long>> &dp){
    if(idx==0) return target%x[idx]==0;  // After we came to the
    // last index (first in this case) we check if the current value i.e, value at index = 0
    // is divisibel with target, then we actually return 1 if it does, Otherwise we return 0
    if(dp[idx][target]!=-1) return dp[idx][target];
    long take = 0, notTake;
    // If we not take current index the just go one step back without affecting the target i.e, without any operation
    notTake = solve(idx-1, target, x, dp);
    // Since the number which is less than or equal to the target is possible to do the operation
    if(x[idx]<=target) take = solve(idx, target-x[idx], x, dp);
    // The above step is to because of there may be chances of selecting multiple variants of a single value and...
    // That is the reason for not changing the index value
    return  dp[idx][target] = take + notTake;
}

long getWays(int n, vector<long> x) {
    vector<vector<long>> dp(x.size()+1, vector<long>(n+1, -1));
    return solve(x.size()-1, n, x, dp);    
}