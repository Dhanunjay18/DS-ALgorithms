#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/minimum-average-difference/description/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int totalSum = 0, n = nums.size();
        if(n==1) return 0;
        for(auto i: nums) totalSum += i;
        long long int minDiff = INT_MAX;
        int idx = 0;
        long long int currSum = 0;
        for(int i=0; i<n; ++i){
            currSum += nums[i];
            long long int currDiff;
            if(i==n-1) currDiff = abs((currSum/(i+1))-(totalSum-currSum));
            else currDiff = abs((currSum/(i+1))-(totalSum-currSum)/(n-i-1));
            if(minDiff>currDiff){
                idx = i;
                minDiff = currDiff;
            }
        }
        return idx;
    }
};