#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,cap;
    cin>>m>>n;
    int a[m][n];
    int mx = INT_MIN;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(j==n-1){
                mx = max(mx,a[i][j]);
            }
        }
    }
    cin>>cap;
    int cnt[mx+1] = {0};
    int f = 0;
    for(int i=0;i<m;i++){
        int start = a[i][1];
        int stop = a[i][2];
        for(int j=start;j<stop;j++){
            cnt[j] += a[i][0];
            if(cnt[j]>cap){ 
                f = 1;
            }
        }
    }
    if(f)
        cout<<"false"<<endl;
    else
        cout<<"true"<<endl;
    return 0;
}