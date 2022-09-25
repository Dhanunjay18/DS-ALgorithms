#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n,vector<int> (m,0));
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums1[i]==nums2[j]){
                if(i==0 or j==0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(dp[i][j],ans);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums1{1,2,3,2,1};
    vector<int> nums2{3,2,1,4,7};
    cout<<findLength(nums1,nums2);
    return 0;
}
