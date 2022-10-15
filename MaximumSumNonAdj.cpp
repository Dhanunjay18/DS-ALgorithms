#include <bits/stdc++.h> 
#include<iostream>
using namespace  std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    // vector<int> dp(n,-1);
    int prev = nums[0]; // dp[0] = nums[0]
    int prev2 = 0; // neg = 0
    int curr;
    
    for(int i=1;i<n;++i){
        int take = nums[i];
        if(i>1) take += prev2; // dp[i-2]
        int notTake =  prev;   // dp[i-1]
        curr = max(take,notTake); // dp[i] = max(take,notTake) 
        prev2 = prev;
        prev = curr;
    }
    return prev; // return dp[i]
}