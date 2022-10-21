#include<bits/stdc++.h>
#include<iostream> 
using namespace std;
// int solve(int idx, int l, vector<vector<int>> &points, vector<vector<int>> &dp){
//     if(idx==0){
//         int mx = 0;
//         for(int i=0;i<3;i++){
//             if(i!=l){
//                 mx = max(mx, points[idx][i]);
//             }            
//         }
//         return mx;
//     }
//     if(dp[idx][l]!=-1) return dp[idx][l];
//     int mx = 0;
//     for(int i=0;i<3;i++){
//         if(i!=l){
//             int p = points[idx][i] + solve(idx-1, i, points, dp);
//             mx = max(mx, p);
//         }
//     }
//     return dp[idx][l] = mx;
// }
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4,0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][1], max(points[0][0],points[0][2]));
    
    for(int day = 1; day < n; day++){
        for(int last=0; last<4; last++){
            dp[day][last] = 0;
            for(int i=0; i<3; i++){
                if(i!=last){
                    int p = points[day][i] + dp[day-1][i];
                    dp[day][last] = max(p,dp[day][last]);
                }
            }
        }
    }    
    return dp[n-1][3];
}