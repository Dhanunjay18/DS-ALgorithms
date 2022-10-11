/*
A. Planets
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day, Vogons wanted to build a new hyperspace highway through a distant system with n planets. The i-th planet is on the orbit ai, there could be multiple planets on the same orbit. It's a pity that all the planets are on the way and need to be destructed.

Vogons have two machines to do that.

The first machine in one operation can destroy any planet at cost of 1 Triganic Pu.
The second machine in one operation can destroy all planets on a single orbit in this system at the cost of c Triganic Pus.
Vogons can use each machine as many times as they want.

Vogons are very greedy, so they want to destroy all planets with minimum amount of money spent. Can you help them to know the minimum cost of this project?
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int ts;
    cin>>ts;
    while(ts--){
        int n,c;
    cin>>n>>c;
    map<int,int> mp;
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        mp[t]++;
    }
    int ans = 0;
    for(auto it: mp){
        ans += min(c,it.second);
    }
    cout<<ans<<endl;
    }
    return 0;
}