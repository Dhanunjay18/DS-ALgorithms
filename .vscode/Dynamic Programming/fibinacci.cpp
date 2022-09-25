#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int usingRecursion(int n){
    if(n<=1){
        return n;
    }
    return usingRecursion(n-1) + usingRecursion(n-2);
}

int usingDPMemorization(int n,vector<int> &dp){
    if(n<=1)    return n;
    if(dp[n]!=-1)   return dp[n];
    return dp[n] = usingDPMemorization(n-1,dp) + usingDPMemorization(n-2,dp);
}

int usingDPTabulation(int n){
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){    
    int n;
    cin>>n;
    // cout<<usingRecursion(n);
    // vector<int> dp(n+1,-1);
    // cout<<usingDPMemorization(n,dp)<<endl;
    cout<<usingDPTabulation(n)<<endl;
    return 0;
}