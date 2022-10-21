#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
    1335. Minimum Difficulty of a Job Schedule (https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/)

    You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

    You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

    You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

    Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.
*/

/*
    Input: jobDifficulty = [6,5,4,3,2,1], d = 2

    Output: 7

    Explanation: First day you can finish the first 5 jobs, total difficulty = 6.

    Second day you can finish the last job, total difficulty = 1.
    
    The difficulty of the schedule = 6 + 1 = 7 
*/

class Solution {
public:
        int f(int idx, int d, vector<int> &jd, int n, vector<vector<int>> &dp){                
                if(idx==n and d==0) return 0;
                if(idx==n or d==0) return INT_MAX;
                if(dp[idx][d]!=-1) return dp[idx][d];
                int ans = INT_MAX;
                int stack = jd[idx];
                for(int i=idx; i<n; ++i){
                        stack = max(stack, jd[i]);
                        int temp = f(i+1, d-1, jd, n, dp);
                        if(temp != INT_MAX)
                                ans = min(ans, stack + temp);
                }
                return dp[idx][d] = ans;
        }
    int minDifficulty(vector<int>& jd, int d) {            
            int n = jd.size();
            vector<vector<int>> dp(n, vector<int>(d+1, 0));
            if(d>n) return -1;
            return f(0, d, jd, n, dp);
            
    }
};